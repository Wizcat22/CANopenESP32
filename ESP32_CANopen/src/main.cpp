/**
 * @file main.cpp
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Main
 * @version 0.1
 * @date 2020-07-24
 * 
 * @copyright Copyright (c) 2020
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
#include "imslROS.h"

#include "ros.h"

/*System components*/
Dunker motor0;
Gyro hg_gyro;

/* TEST*/
uint8_t counter = 0;
/* TEST_END */

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
      esp_restart();
    }
    /* Configure Timer interrupt function for execution every CO_MAIN_TASK_INTERVAL */
    ESP_ERROR_CHECK(esp_timer_create(&coMainTaskArgs, &periodicTimer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodicTimer, CO_MAIN_TASK_INTERVAL));

    /* start CAN */
    CO_CANsetNormalMode(CO->CANmodule[0]);

    reset = CO_RESET_NOT;
    coInterruptCounterPrevious = coInterruptCounter;

    /*Set Operating Mode of Slaves to Operational*/
    CO_sendNMTcommand(CO, 0x01, NODE_ID_MOTOR0);
    //CO_sendNMTcommand(CO, 0x01, NODE_ID_MOTOR1);
    //CO_sendNMTcommand(CO, 0x01, NODE_ID_GYRO);
    //CO_sendNMTcommand(CO, 0x01, NODE_ID_HATOX);

    /* Initialise system components */
    motor0.init(CO, NODE_ID_MOTOR0, 2);
    hg_gyro.init(CO);

    /* application init code goes here. */
    //rosserialSetup();

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
      if (counter == 0)
      {
        motor0.setEnable(1);
        motor0.setSpeed(1000);
        counter++;
      }
      if (coInterruptCounter > 4000 && counter == 1)
      {
        motor0.setSpeed(3000);
        counter++;
      }
      if (coInterruptCounter > 8000 && counter == 2)
      {
        motor0.quickStop();
        counter++;
      }
      if (coInterruptCounter > 12000 && counter == 3)
      {
        motor0.continueMovement();
        motor0.setSpeed(1000);
        counter++;
      }
      if (coInterruptCounter > 16000 && counter == 4)
      {
        motor0.halt();
        motor0.setEnable(0);
        counter++;
      }

      //ROS Publish Messages
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
