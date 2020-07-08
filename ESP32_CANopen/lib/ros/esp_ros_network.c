/*
 * WiFi initialization for setting up ROS communication over TCP sockets
*/

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_eth.h"
#include "rom/gpio.h"
#include <tcpip_adapter.h>
#include "driver/gpio.h"
#include "driver/periph_ctrl.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#include "modul_config.h"

#include "eth_phy/phy_lan8720.h"

const int IPV4_GOTIP_BIT = BIT0;
static EventGroupHandle_t network_event_group;

static const char *TAG = "NET";

static char addr_str[128];
static int addr_family;
static int ip_protocol;
static int sock;

#ifdef CONFIG_ROSSERIAL_OVER_ETH
static void eth_gpio_config_rmii(void)
{
  phy_rmii_configure_data_interface_pins();
  phy_rmii_smi_configure_pins(PIN_SMI_MDC, PIN_SMI_MDIO);
}
#endif

static esp_err_t network_event_handler(void *ctx, system_event_t *event)
{
  tcpip_adapter_ip_info_t ip;

  switch (event->event_id)
  {
  case SYSTEM_EVENT_ETH_CONNECTED:
    ESP_LOGI(TAG, "Ethernet Link Up");
    break;
  case SYSTEM_EVENT_ETH_DISCONNECTED:
    ESP_LOGI(TAG, "Ethernet Link Down");
    xEventGroupClearBits(network_event_group, IPV4_GOTIP_BIT);
    break;
  case SYSTEM_EVENT_ETH_START:
    ESP_LOGI(TAG, "Ethernet Started");
    break;
  case SYSTEM_EVENT_ETH_GOT_IP:
    memset(&ip, 0, sizeof(tcpip_adapter_ip_info_t));
    ESP_ERROR_CHECK(tcpip_adapter_get_ip_info(ESP_IF_ETH, &ip));
    ESP_LOGI(TAG, "Ethernet Got IP Addr");
    ESP_LOGI(TAG, "ETHIP:" IPSTR, IP2STR(&ip.ip));
    ESP_LOGI(TAG, "ETHMASK:" IPSTR, IP2STR(&ip.netmask));
    ESP_LOGI(TAG, "ETHGW:" IPSTR, IP2STR(&ip.gw));
    xEventGroupSetBits(network_event_group, IPV4_GOTIP_BIT);
    break;
  case SYSTEM_EVENT_ETH_STOP:
    ESP_LOGI(TAG, "Ethernet Stopped");
    break;
  case SYSTEM_EVENT_STA_START:
    ESP_LOGI(TAG, "Start AP");
    esp_wifi_connect();
    break;
  case SYSTEM_EVENT_STA_GOT_IP:
    ESP_LOGI(TAG, "got ip:%s", ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
    xEventGroupSetBits(network_event_group, IPV4_GOTIP_BIT);
    break;
  case SYSTEM_EVENT_STA_DISCONNECTED:
  {
    ESP_LOGI(TAG, "Retrying connection to AP");
    esp_wifi_connect();
    xEventGroupClearBits(network_event_group, IPV4_GOTIP_BIT);
    break;
  }
  default:
    break;
  }
  return ESP_OK;
}

void ros_tcp_init()
{
  nvs_flash_init();

  network_event_group = xEventGroupCreate();

  tcpip_adapter_init();
  ESP_ERROR_CHECK(esp_event_loop_init(network_event_handler, NULL));

#ifdef CONFIG_ROSSERIAL_OVER_ETH
  eth_config_t config = DEFAULT_ETHERNET_PHY_CONFIG;
  config.phy_addr = 1;
  config.gpio_config = eth_gpio_config_rmii;
  config.tcpip_input = tcpip_adapter_eth_input;
  config.clock_mode = 3;

  ESP_ERROR_CHECK(esp_eth_init(&config));
  ESP_ERROR_CHECK(esp_eth_enable());
#endif

#ifdef CONFIG_ROSSERIAL_OVER_WIFI
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&cfg));
  wifi_config_t wifi_config = {
      .sta = {
          .ssid = ROS_SERVER_AP,
          .password = ROS_SERVER_PASS,
      },
  };

  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config));
  ESP_ERROR_CHECK(esp_wifi_start());
#endif

  ESP_LOGI(TAG, "Waiting for network connection...");
  xEventGroupWaitBits(network_event_group, IPV4_GOTIP_BIT, false, true, 10000 / portTICK_PERIOD_MS);
  if (!(xEventGroupGetBits(network_event_group) & IPV4_GOTIP_BIT))
  {
    esp_restart();
  }

  ESP_LOGI(TAG, "Connected to network");
}

void ros_tcp_connect(const char *host_ip, int port_num)
{
  struct sockaddr_in destAddr;
  destAddr.sin_addr.s_addr = inet_addr(host_ip);
  destAddr.sin_family = AF_INET;
  destAddr.sin_port = htons(port_num);
  addr_family = AF_INET;
  ip_protocol = IPPROTO_IP;
  inet_ntoa_r(destAddr.sin_addr, addr_str, sizeof(addr_str) - 1);

  sock = socket(addr_family, SOCK_STREAM, ip_protocol);
  if (sock < 0)
  {
    ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
  }
  int err = connect(sock, (struct sockaddr *)&destAddr, sizeof(destAddr));
  if (err != 0)
  {
    ESP_LOGE(TAG, "Socket unable to connect: errno %d", errno);
  }
  if (sock > 0 || err == 0)
  {
    ESP_LOGI(TAG, "Socket connection successfull");
  }
}

void ros_tcp_send(uint8_t *data, int length)
{
  int err = send(sock, data, length, SO_KEEPALIVE);
  if (err < 0)
  {
    ESP_LOGE(TAG, "Sending failed with errno %d", errno);
  }
}

int ros_tcp_read(uint8_t *buf, int length)
{
  int len = recv(sock, buf, length, SO_KEEPALIVE);
  if (len < 0 && errno != 11)
  {
    ESP_LOGE(TAG, "Receive failed with errno %d", errno);
    esp_restart();
    return -1;
  }
  return len;
}
