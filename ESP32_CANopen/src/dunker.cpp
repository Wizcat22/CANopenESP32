/**
 * @file dunker.cpp
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Dunker Motoren CANOpen
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

#include "dunker.h"
#include "modul_config.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "CANopen.h"
#include "CO_OD.h"
#include "esp_log.h"

/**
     * @brief Array for all Motors and the corresponding object-dictionary entries
     * 
     */
Dunker::motorRegister Dunker::motor[] =
    {{&OD_motor_0_device_command, &OD_motor_0_error_register, &OD_motor_0_status_register, &OD_motor_0_mode_of_operation, &OD_motor_0_power_enable, &OD_motor_0_velocity_target_value},
     {&OD_motor_1_device_command, &OD_motor_1_error_register, &OD_motor_1_status_register, &OD_motor_1_mode_of_operation, &OD_motor_1_power_enable, &OD_motor_1_velocity_target_value}};

/**
 * @brief Number of created objects
 * 
 */
static uint8_t numMotors = 0;

/**
 * @brief Motornumber of this object
 * 
 */
uint8_t motorNumber = 0;

Dunker::Dunker()
{
    motorNumber = numMotors;
    numMotors++;
}

int8_t Dunker::init(CO_t *CO, uint8_t nodeId, uint8_t tpdoNum)
{
    int8_t ret = 0;
    _CO = CO;
    _nodeId = nodeId;
    _tpdoNum = tpdoNum;
    /*Configure PDO Mapping on Device 0x1A*/
    uint32_t mappedRxObjects[] = {0x40000108, 0x40030108, 0x40040108, 0x43000120};
    ret = mapRPDO(0, _nodeId, mappedRxObjects, 4);
    uint32_t mappedTxObjects[] = {0x40020120, 0x40010110};
    ret += mapTPDO(0, _nodeId, mappedTxObjects, 2, 0x100, 0x100);
    return ret;
}

int8_t Dunker::clearError()
{
    *motor[motorNumber].command = CMD_ClearError;
    *motor[motorNumber].velocity = 0;
    CO->TPDO[_tpdoNum]->sendRequest = 1;
    return 0;
}

int8_t Dunker::quickStop()
{
    *motor[motorNumber].command = CMD_QuickStop;
    *motor[motorNumber].velocity = 0;
    CO->TPDO[_tpdoNum]->sendRequest = 1;
    return 0;
}

int8_t Dunker::halt()
{
    *motor[motorNumber].command = CMD_Halt;
    *motor[motorNumber].velocity = 0;
    CO->TPDO[_tpdoNum]->sendRequest = 1;
    return 0;
}

int8_t Dunker::continueMovement()
{
    *motor[motorNumber].command = CMD_Continue;
    *motor[motorNumber].velocity = 0;
    CO->TPDO[_tpdoNum]->sendRequest = 1;
    return 0;
}

int8_t Dunker::setEnable(uint8_t value)
{

    int8_t ret = 0;

    *motor[motorNumber].mode = OPERATION_MODE;
    *motor[motorNumber].power = 1;
    CO->TPDO[_tpdoNum]->sendRequest = 1;

    /*Check for fault condition*/
    if (!(*motor[motorNumber].status & STAT_Error))
    {
        if (value)
        {
            while (!(*motor[motorNumber].status & STAT_Enabled))
            {
                vTaskDelay(1 / portTICK_PERIOD_MS);
                *motor[motorNumber].mode = OPERATION_MODE;
                *motor[motorNumber].power = value;
                CO->TPDO[_tpdoNum]->sendRequest = 1;
            }
        }
        else
        {
            *motor[motorNumber].mode = OPERATION_MODE;
            *motor[motorNumber].power = value;
            CO->TPDO[_tpdoNum]->sendRequest = 1;
        }
    }
    else
    {
        ret = *motor[motorNumber].error; //Can't dis-/enable motor while in fault condition
        ESP_LOGE("Dunker.setEnable", "Can't dis-/enable motor while in fault condition!");
    }
    return ret;
}

int8_t Dunker::setSpeed(int32_t speed)
{
    int8_t ret = 0;

    /*Check for fault condition*/
    if (!(*motor[motorNumber].status & STAT_Error))
    {
        *motor[motorNumber].velocity = speed;
        CO->TPDO[_tpdoNum]->sendRequest = 1;
    }
    else
    {
        ret = *motor[motorNumber].error; //Can't set speed while in fault condition
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