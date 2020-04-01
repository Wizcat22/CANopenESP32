#include "Hatox.h"

uint8_t getLeftStickX(){ return OD_statusRegister[ODA_statusRegister_analogDat2];}
uint8_t getLeftStickY(){ return OD_statusRegister[ODA_statusRegister_analogDat1];}
uint8_t getRightStickX(){ return OD_statusRegister[ODA_statusRegister_analogDat4];}
uint8_t getRightStickY(){ return OD_statusRegister[ODA_statusRegister_analogDat3];}
uint8_t getStickDir(){ return OD_statusRegister[ODA_statusRegister_analogDat0];}
uint16_t getButtonStatus(){ return (OD_statusRegister[ODA_statusRegister_digitalDat1]<<8) + OD_statusRegister[ODA_statusRegister_digitalDat0];}

uint8_t setText(uint8_t line, uint8_t column, const char* text, uint8_t len){
    if (len < 7 && len > 0 && line > 0 && line < 4 && column > 0 && column < 17)
    {
      OD_commandRegister[ODA_commandRegister_line] = line;
      OD_commandRegister[ODA_commandRegister_column] = column;
      for (uint8_t i = 0; i < len; i++)
      {
          OD_commandRegister[ODA_commandRegister_char0 + i] = text[i];
      }
      CO->TPDO[0]->sendRequest = 1;
      return 1;
    }   
    return 0;
}