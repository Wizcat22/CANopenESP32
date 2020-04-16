/**
 * @file dunker.h
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @brief Dunker Motoren CANOpen
 * @version 0.1
 * @date 2020-04-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef DUNKER_H_
#define DUNKER_H_

#include <stdint.h>
#include "CANopen.h"
#include "CO_OD.h"

class Dunker
{
private:
    /*Constants*/
    static constexpr int16_t CTRL_SHUTDOWN = 0x0E;
    static constexpr int16_t CTRL_SWITCH_ON = 0x07;
    static constexpr int16_t CTRL_SWITCH_ON_ENABLE_OPERATION = 0x0F;
    static constexpr int16_t CTRL_DISABLE_VOLTAGE = 0x00;
    static constexpr int16_t CTRL_QUICK_STOP = 0x02;
    static constexpr int16_t CTRL_DISABLE_OPERATION = 0x07;
    static constexpr int16_t CTRL_ENABLE_OPERATION = 0x0F;
    static constexpr int16_t CTRL_FAULT_RESET = 0x80;

    static constexpr int16_t BM_STATUS_NOT_READY_TO_SWITCH_ON = 0x4F;
    static constexpr int16_t BM_STATUS_SWITCH_ON_DISABLED = 0x4F;
    static constexpr int16_t BM_STATUS_READY_TO_SWITCH_ON = 0x6F;
    static constexpr int16_t BM_STATUS_SWITCHED_ON = 0x6F;
    static constexpr int16_t BM_STATUS_OPERATION_ENABLED = 0x6F;
    static constexpr int16_t BM_STATUS_QUICK_STOP_ACTIVE = 0x6F;
    static constexpr int16_t BM_STATUS_FAULT_REACTION_ACTIVE = 0x4F;
    static constexpr int16_t BM_STATUS_FAULT = 0x4F;

    static constexpr int16_t STATUS_NOT_READY_TO_SWITCH_ON = 0x00;
    static constexpr int16_t STATUS_SWITCH_ON_DISABLED = 0x40;
    static constexpr int16_t STATUS_READY_TO_SWITCH_ON = 0x21;
    static constexpr int16_t STATUS_SWITCHED_ON = 0x23;
    static constexpr int16_t STATUS_OPERATION_ENABLED = 0x27;
    static constexpr int16_t STATUS_QUICK_STOP_ACTIVE = 0x07;
    static constexpr int16_t STATUS_FAULT_REACTION_ACTIVE = 0x0F;
    static constexpr int16_t STATUS_FAULT = 0x08;

    static constexpr int16_t OPERATION_MODE = 0x02;

public:
    CO_t *_CO;

    /*Functions*/
    int8_t init(CO_t *CO);
    int8_t setEnable(uint8_t value);
    int8_t setSpeed(int16_t speed);
    int8_t coProcessDownloadSDO();
    int8_t coProcessUploadSDO();
    int8_t mapRPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects);
    int8_t mapTPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects, uint16_t eventTime, uint16_t inhibitTime);
};

// #ifdef __cplusplus
// extern "C"
// {
// #endif

//     void initMotor(CO_t *CO);
//     void setMotorEnable(uint8_t value);
//     void setMotorSpeed(int16_t speed);
//     int8_t coProcessDownloadSDO();
//     int8_t coProcessUploadSDO();
//     void mapRPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects);
//     void mapTPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects, uint16_t eventTime, uint16_t inhibitTime);

// #ifdef __cplusplus
// }
// #endif

#endif /* DUNKER_H_ */