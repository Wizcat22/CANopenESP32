
#ifndef GYRO_H_
#define GYRO_H_

#include "CANopen.h"
#include <stdint.h>
#include "CO_OD.h"

void initGyro(CO_t *CO);

float getAngle(bool rad);   /* return current angle in degrees */

float getTemperature(); /* return gyroscope temperature */

uint8_t getLifeCounter();   /* return gyroscope life counter */

uint8_t isDriftCompenstaionActive();    /* status flag: Value>0 if drift compensation active */

uint8_t confirmAngleSetToZero();    /* status flag: Value>0 if confirm angle to zero message */

uint8_t isDriftCompenstaionComplete(); /* status flag: Value>0 if drift compensation is complete */

uint8_t GyroParameterError(); /* status flag: returns parameter error status. See datasheet for more information */

void enableAngleToZero();   /* Set angle to zero flag. must be checked (confirmAngleSetToZero) and reset (disableAngleToZero) */

void disableAngleToZero();  /* Reset angle to zero flag. must be checked (confirmAngleSetToZero) */

void enableDriftCompensation(); /* Set drift compensation flag. (must be checked (complete) & disabled again)*/

void disableDriftCompensation();    /* Reset drift compensation flag */

#endif