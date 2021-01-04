#ifndef ROS_ESP32_HARDWARE_H_
#define ROS_ESP32_HARDWARE_H_

extern "C"
{
#include "stdio.h"
#include "esp_err.h"
#include "esp_timer.h"
#include <driver/uart.h>
#include <lwip/inet.h>

#include <tcpip_adapter.h>
#include "esp_log.h"

#include "esp_ros_network.h"
#include "modul_config.h"
}

class ESP32Hardware
{
protected:
  uint8_t rx_buf[1024];

public:
  ESP32Hardware()
  {
  }

  // Initialization code for ESP32
  void init()
  {
#if defined(CONFIG_ROSSERIAL_OVER_ETH) || defined(CONFIG_ROSSERIAL_OVER_WIFI)
    ros_tcp_init();
    tcpip_adapter_ip_info_t ipInfo;
#if defined(CONFIG_ROSSERIAL_OVER_ETH)
    ESP_ERROR_CHECK(tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_ETH, &ipInfo));
#endif
#if defined(CONFIG_ROSSERIAL_OVER_WIFI)
    ESP_ERROR_CHECK(tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &ipInfo));
#endif
    ESP_LOGI("TEST: ", "%s", inet_ntoa(ipInfo.ip.addr));
    uint32_t rosserver = (ipInfo.ip.addr & (0x00FFFFFF)) + (200 << 24);
    ESP_LOGI("TEST: ", "%s", inet_ntoa(rosserver));
    ros_tcp_connect(inet_ntoa(rosserver), ROS_SERVER_PORT);
#else
    uart_driver_install(UART_PORT, 1024, 1024, 0, NULL, 0);
#endif
  }

  // read a byte from the serial port. -1 = failure
  int read()
  {
    int read_len;
#if defined(CONFIG_ROSSERIAL_OVER_ETH) || defined(CONFIG_ROSSERIAL_OVER_WIFI)
    read_len = ros_tcp_read(rx_buf, 1);
#else
    read_len = uart_read_bytes(UART_PORT, (uint8_t *)rx_buf, 1, 0);
#endif
    if (read_len == 1)
    {
      return rx_buf[0];
    }
    else
    {
      return -1;
    }
  }

  // write data to the connection to ROS
  void write(uint8_t *data, int length)
  {
#if defined(CONFIG_ROSSERIAL_OVER_ETH) || defined(CONFIG_ROSSERIAL_OVER_WIFI)
    ros_tcp_send(data, length);
#else
    uart_write_bytes(UART_PORT, (char *)data, (size_t)length);
#endif
  }

  // returns milliseconds since start of program
  unsigned long time()
  {
    return esp_timer_get_time() / 1000;
  }
};
#endif
