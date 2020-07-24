/**
 * @file dunker.h
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