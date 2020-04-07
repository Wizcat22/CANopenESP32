#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_err.h"
#include "esp_log.h"
#include <stdlib.h>
#include <stdint.h>
#include "driver/can.h"
#include "esp_timer.h"
#include "soc/soc.h"
#include "CANopen.h"
#include "CO_OD.h"
#include "CO_config.h"
#include "modul_config.h"
//#include "imslROS.h"

#include "ros.h"

#define GPIO_INPUT_IO_0 (gpio_num_t)(36)
#define GPIO_INPUT_IO_1 (gpio_num_t)(39)
#define GPIO_INPUT_PIN_SEL ((1ULL << GPIO_INPUT_IO_0) | (1ULL << GPIO_INPUT_IO_1))

volatile uint16_t coInterruptCounter = 0U; /* variable increments each millisecond */
volatile uint16_t coInterruptCounterDiff = 0U;

//Timer Interrupt Configuration
static void coMainTask(void *arg);

int8_t coProcessSDO();

esp_timer_create_args_t coMainTaskArgs;
//Timer Handle
esp_timer_handle_t periodicTimer;

void mainTask(void *pvParameter)
{
  coMainTaskArgs.callback = &coMainTask;
  coMainTaskArgs.name = "coMainTask";
  CO_NMT_reset_cmd_t reset = CO_RESET_NOT;

  while (reset != CO_RESET_APP)
  {
    /* CANopen communication reset - initialize CANopen objects *******************/
    CO_ReturnError_t err;
    uint16_t coInterruptCounterPrevious;

    /* initialize CANopen */
    err = CO_init(NULL, 42 /* NodeID */, 1000 /* bit rate */);
    if (err != CO_ERROR_NO)
    {
      ESP_LOGE("mainTask", "CO_init failed. Errorcode: %d", err);
      CO_errorReport(CO->em, CO_EM_MEMORY_ALLOCATION_ERROR, CO_EMC_SOFTWARE_INTERNAL, err);
      while (1)
      {
      }
    }
    /* Configure Timer interrupt function for execution every CO_MAIN_TASK_INTERVAL */
    ESP_ERROR_CHECK(esp_timer_create(&coMainTaskArgs, &periodicTimer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodicTimer, CO_MAIN_TASK_INTERVAL));

    /* start CAN */
    CO_CANsetNormalMode(CO->CANmodule[0]);

    reset = CO_RESET_NOT;
    coInterruptCounterPrevious = coInterruptCounter;

    /*Set Operating Mode of Slave to Operational*/
    CO_sendNMTcommand(CO, 0x01, 26);

    /* application init code goes here. */
    //rosserialSetup();

    uint8_t devmode = 3;
    uint32_t speed = 3000;
    uint8_t power = 1;
    uint8_t testtt = 1;
    while (reset == CO_RESET_NOT)
    {
      /* loop for normal program execution ******************************************/
      uint16_t coInterruptCounterCopy;

      coInterruptCounterCopy = coInterruptCounter;
      coInterruptCounterDiff = coInterruptCounterCopy - coInterruptCounterPrevious;
      coInterruptCounterPrevious = coInterruptCounterCopy;

      /* CANopen process */
      reset = CO_process(CO, coInterruptCounterDiff, NULL);

      /* Process SDO*/
      coProcessSDO();

      if (testtt == 1)
      {
        CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x4003, 1, &devmode, sizeof(devmode), 0);
        CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x4300, 1, (uint8_t *)&speed, sizeof(speed), 0);
        CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x4004, 1, (uint8_t *)&power, sizeof(power), 0);
        testtt = 0;
      }
      if (coInterruptCounter > 10000)
      {
        power = 0;
        CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x4004, 1, (uint8_t *)&power, sizeof(power), 0);
      }

      /* Nonblocking application code may go here. */

      //ESP_LOGI("TEST","Angle: %f", getAngle(false));
      //ESP_LOGI("TEST","Temperature: %f", getTemperature());
      //ESP_LOGI("TEST", "lifeCounter: %d", getLifeCounter());
      //ESP_LOGI("TEST", "Drift Compensation Active: %d", isDriftCompenstaionActive());
      //ESP_LOGI("TEST", "Drift Compenstation Complete: %d", isDriftCompenstaionComplete());
      //ESP_LOGI("TEST", "Set Angle to Zero Confirm: %d", confirmAngleSetToZero());
      //ESP_LOGI("TEST", "Parameter Error Status: %d", GyroParameterError());

      //rosserialPublish();
      //ROS Handle Messages
      //NodeHandleSpin();

      /* Wait */
      vTaskDelay(MAIN_WAIT / portTICK_PERIOD_MS);
    }
  }
  /* program exit
     * ***************************************************************/
  /* reset */
  esp_restart();
  while (true)
  {
    ESP_LOGE("mainTask", "Application END");
  }
}

/* CanOpen-Task executes in constant intervals ********************************/
static void coMainTask(void *arg)
{
  coInterruptCounter++;

  if (CO->CANmodule[0]->CANnormal)
  {
    bool_t syncWas;

    /* Process Sync */
    syncWas = CO_process_SYNC(CO, CO_MAIN_TASK_INTERVAL);

    /* Read inputs */
    CO_process_RPDO(CO, syncWas);

    /* Write outputs */
    CO_process_TPDO(CO, syncWas, CO_MAIN_TASK_INTERVAL);
  }
}

int8_t coProcessSDO()
{
  uint32_t SdoAbortCode = CO_SDO_AB_NONE;
  int8_t ret = 0;
  do
  {
    ret = CO_SDOclientDownload(CO->SDOclient[0], coInterruptCounterDiff, 2000, &SdoAbortCode);
  } while (ret > 0);
  return ret;
}

extern "C"
{
  void app_main()
  {
    xTaskCreate(&mainTask, "mainTask", 4096, NULL, 5, NULL);
  }
}