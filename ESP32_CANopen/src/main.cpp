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
#include "imslROS.h"

extern "C" {
  // Get declaration for f(int i, char c, float x)
  #include "Gyro.h"
}

#include "ros.h"


#define GPIO_INPUT_IO_0     (gpio_num_t)(36)
#define GPIO_INPUT_IO_1     (gpio_num_t)(39)
#define GPIO_INPUT_PIN_SEL  ((1ULL<<GPIO_INPUT_IO_0) | (1ULL<<GPIO_INPUT_IO_1))


volatile uint16_t coInterruptCounter = 0U; /* variable increments each millisecond */

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
      while (1){}
    }
    /* Configure Timer interrupt function for execution every CO_MAIN_TASK_INTERVAL */
    ESP_ERROR_CHECK(esp_timer_create(&coMainTaskArgs, &periodicTimer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodicTimer, CO_MAIN_TASK_INTERVAL));

    /* start CAN */
    CO_CANsetNormalMode(CO->CANmodule[0]);

    reset = CO_RESET_NOT;
    coInterruptCounterPrevious = coInterruptCounter;    

    /*Set Operating Mode of Slave to Operational*/
    CO_sendNMTcommand(CO, 0x01 , 0x03); 

    /* application init code goes here. */

    //Gyro Drift Compensation status
    uint8_t DCenabled = 0;

    //gpio configuration
    gpio_config_t io_conf;
    //bit mask of the used pins
    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    //set as input mode    
    io_conf.mode = GPIO_MODE_INPUT;
    //enable pull-up mode
    gpio_config(&io_conf);

    initGyro(CO);
    rosserialSetup();


    while (reset == CO_RESET_NOT)
    {
      /* loop for normal program execution ******************************************/
      uint16_t coInterruptCounterCopy, coInterruptCounterDiff;

      coInterruptCounterCopy = coInterruptCounter;
      coInterruptCounterDiff = coInterruptCounterCopy - coInterruptCounterPrevious;
      coInterruptCounterPrevious = coInterruptCounterCopy;

      /* CANopen process */
      reset = CO_process(CO, coInterruptCounterDiff, NULL);

      /* Nonblocking application code may go here. */

      //ESP_LOGI("TEST","Angle: %f", getAngle(false));
      //ESP_LOGI("TEST","Temperature: %f", getTemperature());
      ESP_LOGI("TEST","lifeCounter: %d", getLifeCounter());
      //ESP_LOGI("TEST", "Drift Compensation Active: %d", isDriftCompenstaionActive());
      //ESP_LOGI("TEST", "Drift Compenstation Complete: %d", isDriftCompenstaionComplete());
      //ESP_LOGI("TEST", "Set Angle to Zero Confirm: %d", confirmAngleSetToZero());
      //ESP_LOGI("TEST", "Parameter Error Status: %d", GyroParameterError());
      if (gpio_get_level(GPIO_INPUT_IO_0))
      {
        enableDriftCompensation();
        DCenabled = 1;
      }
      if (DCenabled == 1){
        if (isDriftCompenstaionComplete()){
          disableDriftCompensation();
          DCenabled = 0;
        }
      }
      if (gpio_get_level(GPIO_INPUT_IO_1)){
        enableAngleToZero();
      }
      if (confirmAngleSetToZero()){
        disableAngleToZero();
      }  

      rosserialPublish();
      //ROS Handle Messages
      NodeHandleSpin();
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

extern "C"{
void app_main()
{
  xTaskCreate(&mainTask, "mainTask", 4096, NULL, 5, NULL);
}

}