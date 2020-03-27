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

#define TMR_TASK_INTERVAL (1000)   /* Interval of tmrTask thread in microseconds */
#define INCREMENT_1MS(var) (var++) /* Increment 1ms variable in tmrTask */

      volatile uint16_t CO_timer1ms = 0U; /* variable increments each millisecond */

/**
 * User-defined CAN base structure, passed as argument to CO_init.
 */
struct CANbase
{
  uintptr_t baseAddress; /**< Base address of the CAN module */
};

//#########-TimerConfiguration-############
/* timer thread executes in constant intervals ********************************/
static void timerCallback(void *arg);

const esp_timer_create_args_t timerCallbackArgs = {
    .callback = &timerCallback,
    /* name is optional, but may help identify the timer when debugging */
    .name = "timerCallback"};

esp_timer_handle_t periodicTimer;

void mainTask(void *pvParameter)
{
  CO_NMT_reset_cmd_t reset = CO_RESET_NOT;
  //OD_powerOnCounter++;

  while (reset != CO_RESET_APP)
  {
    /* CANopen communication reset - initialize CANopen objects *******************/
    CO_ReturnError_t err;
    uint16_t timer1msPrevious;

    /* disable CAN and CAN interrupts */
    struct CANbase canBase = {
        .baseAddress = 0u, /* CAN module address */
    };

    /* initialize CANopen */
    
    err = CO_init(&canBase, 42 /* NodeID */, 1000 /* bit rate */);
    if (err != CO_ERROR_NO)
    {
      ESP_LOGE("mainTask", "CO_init failed. Errorcode: %d", err);
      while (1)
        ;
      /* CO_errorReport(CO->em, CO_EM_MEMORY_ALLOCATION_ERROR, CO_EMC_SOFTWARE_INTERNAL, err); */
    }

    /* Configure Timer interrupt function for execution every 1 millisecond */
    ESP_ERROR_CHECK(esp_timer_create(&timerCallbackArgs, &periodicTimer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodicTimer, TMR_TASK_INTERVAL));
    /* Configure CAN transmit and receive interrupt */
    ESP_LOGE("mainTask", "Init Timer");
    /* start CAN */

    CO_CANsetNormalMode(CO->CANmodule[0]);

    reset = CO_RESET_NOT;
    timer1msPrevious = CO_timer1ms;
    ESP_LOGE("mainTask", "Enter Loop");
    
    //CO->NMT->operatingState = CO_NMT_OPERATIONAL; /* WORKAROUND */
    CO_sendNMTcommand(CO, 0x01 , 0x03); 
    int q = 0;
    while (reset == CO_RESET_NOT)
    {
      /* loop for normal program execution ******************************************/
      uint16_t timer1msCopy, timer1msDiff;

      timer1msCopy = CO_timer1ms;
      timer1msDiff = timer1msCopy - timer1msPrevious;
      timer1msPrevious = timer1msCopy;

      /* CANopen process */
      reset = CO_process(CO, timer1msDiff, NULL);

      /* Nonblocking application code may go here. */
      ESP_LOGE("TEST","Winkel: %f", (OD_readAngle[ODA_readAngle_angle]*(float)(57.2958)));
      ESP_LOGE("TEST","Temperature: %f", (float)((float)(OD_readAnalogueInput16Bit[ODA_readAnalogueInput16Bit_temperature])/8));
      ESP_LOGE("TEST","lifeCounter: %d", OD_lifeCounter[ODA_lifeCounter_lifeCounter]);
      ESP_LOGE("TEST", "STATUS-BITS: %d", OD_readInput8Bit[ODA_readInput8Bit_statusbits07]);
      
      if (q)
      {
        OD_writeOutput8Bit[ODA_writeOutput8Bit_commandbits07] = 0b00000010;
      }
      else
      {
        OD_writeOutput8Bit[ODA_writeOutput8Bit_commandbits07] = 0b00000000;
      }
      CO->TPDO[0]->sendRequest = true;
      q=~q;
      
      /* Process EEPROM */

      /* Wait */
      
      vTaskDelay(100 / portTICK_PERIOD_MS);
    }
  }
  /* program exit
     * ***************************************************************/
  /* stop threads */
  esp_timer_stop(periodicTimer);
  esp_timer_delete(periodicTimer);
  /* delete objects from memory */
  CO_delete((void *)0 /* CAN module address */);

  /* reset */
  esp_restart();
  while (true)
  {
    ESP_LOGE("mainTask", "Application END");
  }
}

/* timer thread executes in constant intervals ********************************/
static void timerCallback(void *arg)
{
  INCREMENT_1MS(CO_timer1ms);

  if (CO->CANmodule[0]->CANnormal)
  {
    bool_t syncWas;

    /* Process Sync */
    syncWas = CO_process_SYNC(CO, TMR_TASK_INTERVAL);

    /* Read inputs */
    CO_process_RPDO(CO, syncWas);

    /* Further I/O or nonblocking application code may go here. */

    /* Write outputs */
    CO_process_TPDO(CO, syncWas, TMR_TASK_INTERVAL);

    /* verify timer overflow */
    if (0)
    {
      CO_errorReport(CO->em, CO_EM_ISR_TIMER_OVERFLOW, CO_EMC_SOFTWARE_INTERNAL, 0U);
    }
  }
}

void app_main()
{
  xTaskCreate(&mainTask, "mainTask", 4096, NULL, 5, NULL);
}