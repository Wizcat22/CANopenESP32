#include "dunker.h"
#include "modul_config.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "CANopen.h"
#include "CO_OD.h"
#include "esp_log.h"

CO_t *_CO;

int8_t Dunker::init(CO_t *CO)
{
    int8_t ret = 0;
    _CO = CO;
    /*Configure PDO Mapping on Device 0x1A*/
    uint32_t mappedRxObjects[] = {0x60420010, 0x60400010, 0x60600008};
    ret = mapRPDO(0, NODE_ID_MOTOR, mappedRxObjects, 3);
    uint32_t mappedTxObjects[] = {0x60410010};
    ret = mapTPDO(0, NODE_ID_MOTOR, mappedTxObjects, 1, 0x100, 0x100);
    return ret;
}

int8_t Dunker::setEnable(uint8_t value)
{

    int8_t ret = 0;

    /*Check for fault condition*/
    if ((OD_motor_0_status_word & BM_STATUS_FAULT_REACTION_ACTIVE) != STATUS_FAULT_REACTION_ACTIVE && (OD_motor_0_status_word & BM_STATUS_FAULT) != STATUS_FAULT)
    {
        if (value)
        {
            while (((OD_motor_0_status_word & BM_STATUS_NOT_READY_TO_SWITCH_ON) != STATUS_NOT_READY_TO_SWITCH_ON) && (OD_motor_0_status_word & BM_STATUS_READY_TO_SWITCH_ON) != STATUS_READY_TO_SWITCH_ON)
            {
                vTaskDelay(1 / portTICK_PERIOD_MS);
                OD_motor_0_modes_of_operation = OPERATION_MODE;
                OD_motor_0_control_word = CTRL_SHUTDOWN;
                CO->TPDO[2]->sendRequest = 1;
            }
            OD_motor_0_control_word = CTRL_SWITCH_ON_ENABLE_OPERATION;
            CO->TPDO[2]->sendRequest = 1;
        }
        else
        {
            OD_motor_0_control_word = CTRL_DISABLE_VOLTAGE;
            CO->TPDO[2]->sendRequest = 1;
        }
    }
    else
    {
        ret = -1; //Can't dis-/enable motor while in fault condition
        ESP_LOGE("Dunker.setEnable", "Can't dis-/enable motor while in fault condition!");
    }
    return ret;
}

int8_t Dunker::setSpeed(int16_t speed)
{
    int8_t ret = 0;

    /*Check for fault condition*/
    if ((OD_motor_0_status_word & BM_STATUS_FAULT_REACTION_ACTIVE) != STATUS_FAULT_REACTION_ACTIVE && (OD_motor_0_status_word & BM_STATUS_FAULT) != STATUS_FAULT)
    {
        OD_motor_0_vl_target_velocity_register = speed; /*Set Motor Speed*/
        CO->TPDO[2]->sendRequest = 1;
    }
    else
    {
        ret = -1; //Can't set speed while in fault condition
    }
    return ret;
}

int8_t Dunker::coProcessUploadSDO()
{
    uint32_t SdoAbortCode = CO_SDO_AB_NONE;
    int8_t ret = 0;
    uint32_t dataSize = 0;

    do
    {
        ret = CO_SDOclientUpload(_CO->SDOclient[0], 1, 5000, &dataSize, &SdoAbortCode);

    } while (ret > 0);
    return ret;
}

int8_t Dunker::coProcessDownloadSDO()
{
    uint32_t SdoAbortCode = CO_SDO_AB_NONE;
    int8_t ret = 0;
    do
    {
        ret = CO_SDOclientDownload(_CO->SDOclient[0], 1, 5000, &SdoAbortCode);
    } while (ret > 0);
    return ret;
}

int8_t Dunker::mapRPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects)
{
    int8_t ret = 0;
    uint32_t v32 = 0; //Temporary Storage
    uint8_t v8 = 0;   //Temporary Storage

    //RPDO Disable
    v32 = ((0x200 + nodeId + pdoNumber) | 0x80000000);
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1400 + pdoNumber, 1, (uint8_t *)&v32, sizeof(v32), 0);
    ret = coProcessDownloadSDO();

    //RPDO Disable Mapping
    v8 = 0;
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1600 + pdoNumber, 0, (uint8_t *)&v8, sizeof(v8), 0);
    ret = coProcessDownloadSDO();

    //RPDO Mapping
    for (uint8_t i = 0; i < numMappedObjects; i++)
    {
        v32 = mappedObjects[i];
        CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1600 + pdoNumber, 1 + i, (uint8_t *)&v32, sizeof(v32), 0);
        ret = coProcessDownloadSDO();
    }

    //RPDO Enable Mapping
    v8 = numMappedObjects;
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1600 + pdoNumber, 0, (uint8_t *)&v8, sizeof(v8), 0);
    ret = coProcessDownloadSDO();

    //RPDO Enable
    v32 = (0x200 + nodeId + pdoNumber);
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1400 + pdoNumber, 1, (uint8_t *)&v32, sizeof(v32), 0);
    ret = coProcessDownloadSDO();

    return ret;
}

int8_t Dunker::mapTPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects, uint16_t eventTime, uint16_t inhibitTime)
{
    int8_t ret = 0;
    uint32_t v32 = 0;
    uint16_t v16 = 0;
    uint8_t v8 = 0;

    //TPDO Disable
    v32 = ((0x180 + nodeId + pdoNumber) | 0x80000000);
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1800 + pdoNumber, 1, (uint8_t *)&v32, sizeof(v32), 0);
    ret = coProcessDownloadSDO();

    //TPDO Disable Mapping
    v8 = 0;
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1a00 + pdoNumber, 0, (uint8_t *)&v8, sizeof(v8), 0);
    ret = coProcessDownloadSDO();

    //TPDO Set Eventtime
    v16 = eventTime;
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1800 + pdoNumber, 5, (uint8_t *)&v16, sizeof(v16), 0);
    ret = coProcessDownloadSDO();

    //TPDO Set Inhibittime
    v16 = inhibitTime;
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1800 + pdoNumber, 3, (uint8_t *)&v16, sizeof(v16), 0);
    ret = coProcessDownloadSDO();

    //TPDO Mapping
    for (uint8_t i = 0; i < numMappedObjects; i++)
    {
        v32 = mappedObjects[i];
        CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1a00 + pdoNumber, 1 + i, (uint8_t *)&v32, sizeof(v32), 0);
        ret = coProcessDownloadSDO();
    }

    //TPDO Enable Mapping
    v8 = numMappedObjects;
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1a00 + pdoNumber, 0, (uint8_t *)&v8, sizeof(v8), 0);
    ret = coProcessDownloadSDO();

    //TPDO Enable
    v32 = (0x180 + nodeId + pdoNumber);
    CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x1800 + pdoNumber, 1, (uint8_t *)&v32, sizeof(v32), 0);
    ret = coProcessDownloadSDO();

    return ret;
}