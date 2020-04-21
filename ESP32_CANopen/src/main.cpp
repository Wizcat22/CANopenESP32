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
#include "dunker.h"
#include "Gyro.h"
//#include "imslROS.h"

#include "ros.h"

Dunker motor;
Gyro hg_gyro;

volatile uint32_t coInterruptCounter = 0U; /* variable increments each millisecond */

//Timer Interrupt Configuration
static void coMainTask(void *arg);

esp_timer_create_args_t coMainTaskArgs;
//Timer Handle
esp_timer_handle_t periodicTimer;

void mainTask(void *pvParameter)
{
  coMainTaskArgs.callback = &coMainTask;
  coMainTaskArgs.name = "coMainTask";
  CO_NMT_reset_cmd_t reset = CO_RESET_NOT;
  vTaskDelay(BOOT_WAIT / portTICK_PERIOD_MS);
  while (reset != CO_RESET_APP)
  {
    /* CANopen communication reset - initialize CANopen objects *******************/
    CO_ReturnError_t err;
    uint32_t coInterruptCounterPrevious;

    /* initialize CANopen */
    err = CO_init(NULL, NODE_ID_SELF /* NodeID */, CAN_BITRATE /* bit rate */);
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
    CO_sendNMTcommand(CO, 0x01, NODE_ID_MOTOR);

    /* application init code goes here. */
    //rosserialSetup();

    int16_t speed = 0;
    uint8_t init = 0;
    uint8_t toggle = 0;
    uint8_t activate_gyro = 0;

    if (activate_gyro)
    {
      hg_gyro.init(CO);
    }

    while (reset == CO_RESET_NOT)
    {
      /* loop for normal program execution ******************************************/
      uint32_t coInterruptCounterCopy;
      uint32_t coInterruptCounterDiff;
      coInterruptCounterCopy = coInterruptCounter;
      coInterruptCounterDiff = coInterruptCounterCopy - coInterruptCounterPrevious;
      coInterruptCounterPrevious = coInterruptCounterCopy;

      /* CANopen process */
      reset = CO_process(CO, coInterruptCounterDiff, NULL);

      /* Nonblocking application code may go here. */
      if (init == 0)
      {
        motor.init(CO);
        motor.setEnable(1);
        init = 1;
      }
      if (coInterruptCounter > 20000 && init == 1)
      {
        motor.halt();
        init = 2;
      }

      if (toggle)
      {
        speed += 100;
      }
      else
      {
        speed -= 100;
      }
      if (speed >= 4950 || speed <= -4950)
      {
        toggle = !toggle;
      }

      motor.setSpeed(speed);

      if (activate_gyro)
      {
        ESP_LOGI("GYRO_Test", "lifeCounter: %d", hg_gyro.getLifeCounter());
      }

      // ESP_LOGI("MAIN", "%d", voltage);
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

extern "C"
{
  void app_main()
  {
    xTaskCreate(&mainTask, "mainTask", 4096, NULL, 5, NULL);
  }
}
