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

#ifdef __cplusplus
extern "C"
{
#endif

    void initMotor(CO_t *CO);
    void setMotorEnable(uint8_t value);
    void setMotorSpeed(int32_t speed);
    int8_t coProcessDownloadSDO();
    int8_t coProcessUploadSDO();
    void mapRPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects);
    void mapTPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects, uint16_t eventTime, uint16_t inhibitTime);

#ifdef __cplusplus
}
#endif

#endif /* DUNKER_H_ */