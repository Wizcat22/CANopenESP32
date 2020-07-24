/**
 * @file Gyro.cpp
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Gyro
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

#include "Gyro.h"

void Gyro::init(CO_t *CO)
{
    CO_local = CO;
}

/* return current angle */
float Gyro::getAngle(bool rad)
{
    if (rad)
    {
        return OD_gyro_angle_register[ODA_gyro_angle_register_angle];
    }
    return OD_gyro_angle_register[ODA_gyro_angle_register_angle] * CALCULATE_RAD_TO_DEGREE;
}

/* return gyroscope temperature */
float Gyro::getTemperature()
{
    return ((float)(OD_gyro_temperature_register[ODA_gyro_temperature_register_temperature]) / 8);
}

/* return gyroscope life counter */
uint8_t Gyro::getLifeCounter()
{
    return OD_gyro_lifecounter_register[ODA_gyro_lifecounter_register_lifecounter];
}

/* status flag: Value>0 if drift compensation active */
uint8_t Gyro::isDriftCompenstaionActive()
{
    return OD_gyro_status_register[ODA_gyro_status_register_status] & STATUS_IS_DIRFT_COMPENSATION_ENABLE;
}

/* status flag: Value>0 if confirm angle to zero message */
uint8_t Gyro::confirmAngleSetToZero()
{
    return OD_gyro_status_register[ODA_gyro_status_register_status] & STATUS_CONFIRM_ANGLE_TO_ZERO;
}

/* status flag: Value>0 if drift compensation is complete */
uint8_t Gyro::isDriftCompenstaionComplete()
{
    return OD_gyro_status_register[ODA_gyro_status_register_status] & STATUS_IS_DRIFT_COMPENSATION_COMPLETE;
}

/* status flag: returns parameter error status. See datasheet for more information */
uint8_t Gyro::GyroParameterError()
{
    return OD_gyro_status_register[ODA_gyro_status_register_status] & STATUS_PARAMETER_ERROR;
}

/* Set angle to zero flag. must be checked (confirmAngleSetToZero) and reset (disableAngleToZero) */
void Gyro::enableAngleToZero()
{
    OD_gyro_command_register[ODA_gyro_command_register_command] |= CMD_ANGLE_TO_ZERO;
    CO_local->TPDO[0]->sendRequest = 1;
}

/* Reset angle to zero flag. must be checked (confirmAngleSetToZero) */
void Gyro::disableAngleToZero()
{
    OD_gyro_command_register[ODA_gyro_command_register_command] &= ~CMD_ANGLE_TO_ZERO;
    CO_local->TPDO[0]->sendRequest = 1;
}

/* Set drift compensation flag. (must be checked (complete) & disabled again)*/
void Gyro::enableDriftCompensation()
{
    OD_gyro_command_register[ODA_gyro_command_register_command] |= CMD_DRIFT_COMPENSATION;
    CO_local->TPDO[0]->sendRequest = 1;
}

/* Reset drift compensation flag */
void Gyro::disableDriftCompensation()
{
    OD_gyro_command_register[ODA_gyro_command_register_command] &= ~CMD_DRIFT_COMPENSATION;
    CO_local->TPDO[0]->sendRequest = 1;
}
