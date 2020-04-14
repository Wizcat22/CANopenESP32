#include "dunker.h"
#include "modul_config.h"
#include "CANopen.h"
#include "CO_OD.h"

CO_t *_CO;

void initMotor(CO_t *CO)
{
    _CO = CO;
    /*Configure PDO Mapping on Device 0x1A*/
    uint32_t mappedRxObjects[] = {0x43000120, 0x40030108, 0x40040108};
    mapRPDO(0, NODE_ID_MOTOR, mappedRxObjects, 3);
    uint32_t mappedTxObjects[] = {0x43000120, 0x40030108, 0x40040108};
    mapTPDO(0, NODE_ID_MOTOR, mappedTxObjects, 3, 0x100, 0x100);
}

void setMotorEnable(uint8_t value)
{
    if (value)
    {
        OD_deviceMode.deviceMode = 3;   /*Set Device Mode to 3*/
        OD_powerEnable.powerEnable = 1; /*Enable Motor Power*/
        CO->TPDO[0]->sendRequest = 1;
    }
    else
    {
        OD_powerEnable.powerEnable = 0; /*Enable Motor Power*/
        CO->TPDO[0]->sendRequest = 1;
    }
}

void setMotorSpeed(int32_t speed)
{
    OD_velocityDesiredValue.velocityDesiredValue = speed; /*Set Motor Speed*/
    CO->TPDO[0]->sendRequest = 1;
}

int8_t coProcessUploadSDO()
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

int8_t coProcessDownloadSDO()
{
    uint32_t SdoAbortCode = CO_SDO_AB_NONE;
    int8_t ret = 0;
    do
    {
        ret = CO_SDOclientDownload(_CO->SDOclient[0], 1, 5000, &SdoAbortCode);
    } while (ret > 0);
    return ret;
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