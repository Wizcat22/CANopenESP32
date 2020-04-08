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

uint32_t voltage = 0;

//Timer Interrupt Configuration
static void coMainTask(void *arg);

int8_t coProcessDownloadSDO();
int8_t coProcessUploadSDO();
void mapRPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects);
void mapTPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects, uint16_t eventTime, uint16_t inhibitTime);

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

    int32_t speed = 0;
    uint8_t init = 0;
    uint8_t toggle = 0;

    while (reset == CO_RESET_NOT)
    {
      /* loop for normal program execution ******************************************/
      uint16_t coInterruptCounterCopy;

      coInterruptCounterCopy = coInterruptCounter;
      coInterruptCounterDiff = coInterruptCounterCopy - coInterruptCounterPrevious;
      coInterruptCounterPrevious = coInterruptCounterCopy;

      /* CANopen process */
      reset = CO_process(CO, coInterruptCounterDiff, NULL);

      /* Nonblocking application code may go here. */
      if (init == 0)
      {
        /*Configure PDO Mapping on Device 0x1A*/
        uint32_t mappedRxObjects[] = {0x43000120, 0x40030108, 0x40040108};
        mapRPDO(0, 0x1A, mappedRxObjects, 3);
        uint32_t mappedTxObjects[] = {0x43000120, 0x40030108, 0x40040108};
        mapTPDO(0, 0x1A, mappedTxObjects, 3, 0x100, 0x100);

        /*Set Device Mode to 3*/
        OD_deviceMode.deviceMode = 3;
        /*Enable Motor Power*/
        OD_powerEnable.powerEnable = 1;
        CO->TPDO[0]->sendRequest = 1;
        init = 1;
      }
      if (coInterruptCounter > 20000 && OD_powerEnable.powerEnable == 1)
      {
        OD_powerEnable.powerEnable = 0;
        CO->TPDO[0]->sendRequest = 1;
      }
      if (toggle)
      {
        speed += 100;
      }
      else
      {
        speed -= 100;
      }
      if (speed >= 3000 || speed <= -2800)
      {
        toggle = !toggle;
      }

      OD_velocityDesiredValue.velocityDesiredValue = speed;
      CO->TPDO[0]->sendRequest = 1;

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

int8_t coProcessUploadSDO()
{
  uint32_t SdoAbortCode = CO_SDO_AB_NONE;
  int8_t ret = 0;
  uint32_t dataSize = 0;
  do
  {
    ret = CO_SDOclientUpload(CO->SDOclient[0], coInterruptCounterDiff, 2000, &dataSize, &SdoAbortCode);
  } while (ret > 0);
  return ret;
}

int8_t coProcessDownloadSDO()
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

void mapRPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects)
{
  uint32_t v32 = 0; //Temporary Storage
  uint8_t v8 = 0;   //Temporary Storage

  //RPDO Disable
  v32 = ((0x200 + nodeId + pdoNumber) | 0x80000000);
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1400 + pdoNumber, 1, (uint8_t *)&v32, sizeof(v32), 0);
  coProcessDownloadSDO();

  //RPDO Disable Mapping
  v8 = 0;
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1600 + pdoNumber, 0, (uint8_t *)&v8, sizeof(v8), 0);
  coProcessDownloadSDO();

  //RPDO Mapping
  for (uint8_t i = 0; i < numMappedObjects; i++)
  {
    v32 = mappedObjects[i];
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1600 + pdoNumber, 1 + i, (uint8_t *)&v32, sizeof(v32), 0);
    coProcessDownloadSDO();
  }

  //RPDO Enable Mapping
  v8 = numMappedObjects;
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1600 + pdoNumber, 0, (uint8_t *)&v8, sizeof(v8), 0);
  coProcessDownloadSDO();

  //RPDO Enable
  v32 = (0x200 + nodeId + pdoNumber);
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1400 + pdoNumber, 1, (uint8_t *)&v32, sizeof(v32), 0);
  coProcessDownloadSDO();
}

void mapTPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects, uint16_t eventTime, uint16_t inhibitTime)
{
  uint32_t v32 = 0;
  uint16_t v16 = 0;
  uint8_t v8 = 0;

  //TPDO Disable
  v32 = ((0x180 + nodeId + pdoNumber) | 0x80000000);
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1800 + pdoNumber, 1, (uint8_t *)&v32, sizeof(v32), 0);
  coProcessDownloadSDO();

  //TPDO Disable Mapping
  v8 = 0;
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1a00 + pdoNumber, 0, (uint8_t *)&v8, sizeof(v8), 0);
  coProcessDownloadSDO();

  //TPDO Set Eventtime
  v16 = eventTime;
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1800 + pdoNumber, 5, (uint8_t *)&v16, sizeof(v16), 0);
  coProcessDownloadSDO();

  //TPDO Set Inhibittime
  v16 = inhibitTime;
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1800 + pdoNumber, 3, (uint8_t *)&v16, sizeof(v16), 0);
  coProcessDownloadSDO();

  //TPDO Mapping
  for (uint8_t i = 0; i < numMappedObjects; i++)
  {
    v32 = mappedObjects[i];
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1a00 + pdoNumber, 1 + i, (uint8_t *)&v32, sizeof(v32), 0);
    coProcessDownloadSDO();
  }

  //TPDO Enable Mapping
  v8 = numMappedObjects;
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1a00 + pdoNumber, 0, (uint8_t *)&v8, sizeof(v8), 0);
  coProcessDownloadSDO();

  //TPDO Enable
  v32 = (0x180 + nodeId + pdoNumber);
  CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1800 + pdoNumber, 1, (uint8_t *)&v32, sizeof(v32), 0);
  coProcessDownloadSDO();
}