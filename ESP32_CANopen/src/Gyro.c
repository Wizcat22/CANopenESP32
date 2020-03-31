
#include "Gyro.h"

CO_t *CO_local;

void initGyro(CO_t *CO){
  CO_local = CO;
}

/* return current angle in degrees */
float getAngle(bool rad){ 
  if (rad)
  {
    return OD_angleRegister[ODA_angleRegister_angle];
  }
  return OD_angleRegister[ODA_angleRegister_angle]*(float)(57.2958);
}

/* return gyroscope temperature */
float getTemperature(){
  return ((float)(OD_temperatureRegister[ODA_temperatureRegister_temperature])/8);
}

/* return gyroscope life counter */
uint8_t getLifeCounter(){
  return OD_lifeCounterRegister[ODA_lifeCounterRegister_lifeCounter];
}

 /* status flag: Value>0 if drift compensation active */
uint8_t isDriftCompenstaionActive(){
  return OD_statusRegister[ODA_statusRegister_statusbits] & 0b00000001;
}

/* status flag: Value>0 if confirm angle to zero message */
uint8_t confirmAngleSetToZero(){
  return OD_statusRegister[ODA_statusRegister_statusbits] & 0b00000010;
}

/* status flag: Value>0 if drift compensation is complete */
uint8_t isDriftCompenstaionComplete(){
  return OD_statusRegister[ODA_statusRegister_statusbits] & 0b00010000;
}

/* status flag: returns parameter error status. See datasheet for more information */
uint8_t GyroParameterError(){
  return OD_statusRegister[ODA_statusRegister_statusbits] & 0b10000000;
}

/* Set angle to zero flag. must be checked (confirmAngleSetToZero) and reset (disableAngleToZero) */
void enableAngleToZero(){
  OD_commandRegister[ODA_commandRegister_command] = 0b00000010;
  CO_local->TPDO[0]->sendRequest = 1;
}

/* Reset angle to zero flag. must be checked (confirmAngleSetToZero) */
void disableAngleToZero(){
  OD_commandRegister[ODA_commandRegister_command] = 0b00000000;
  CO_local->TPDO[0]->sendRequest = 1;
}

/* Set drift compensation flag. (must be checked (complete) & disabled again)*/
void enableDriftCompensation(){
  OD_commandRegister[ODA_commandRegister_command] = 0b00000001;
  CO_local->TPDO[0]->sendRequest = 1;
}

/* Reset drift compensation flag */
void disableDriftCompensation(){
  OD_commandRegister[ODA_commandRegister_command] = 0b00000000;
  CO_local->TPDO[0]->sendRequest = 1;
}
