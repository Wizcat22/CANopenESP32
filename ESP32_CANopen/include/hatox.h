#ifndef HATOX_H_
#define HATOX_H_

#include "CANopen.h"
#include <stdint.h>
#include "CO_OD.h"

class Hatox
{

private:
    static constexpr int16_t HATOX_BTN_RUN = 1;    //Bitposition for RUN Button
    static constexpr int16_t HATOX_BTN_FAST = 2;   //Bitposition for Rabbit Button
    static constexpr int16_t HATOX_BTN_SLOW = 4;   //Bitposition for Turtle Button
    static constexpr int16_t HATOX_BTN_1 = 8;      //Bitposition for 1 Button
    static constexpr int16_t HATOX_BTN_2 = 16;     //Bitposition for 2 Button
    static constexpr int16_t HATOX_BTN_3 = 32;     //Bitposition for 3 Button
    static constexpr int16_t HATOX_BTN_4 = 64;     //Bitposition for 4 Button
    static constexpr int16_t HATOX_BTN_STOP = 128; //Bitposition for STOP Button
    static constexpr int16_t HATOX_BTN_5 = 256;    //Bitposition for 5 Button
    static constexpr int16_t HATOX_BTN_6 = 512;    //Bitposition for 6 Button

public:
    uint8_t getLeftStickX();
    uint8_t getLeftStickY();
    uint8_t getRightStickX();
    uint8_t getRightStickY();
    uint8_t getStickDir();
    uint16_t getButtonStatus();
    uint8_t setText(uint8_t line, uint8_t column, const char *text, uint8_t len);
};

#endif