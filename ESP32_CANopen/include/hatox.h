#ifndef HATOX_H_
#define HATOX_H_

#include "CANopen.h"
#include <stdint.h>
#include <string>
#include "CO_OD.h"

class Hatox
{

private:
    static constexpr int16_t HATOX_BTN_RUN = (1 << 0);  //Bitposition for RUN Button
    static constexpr int16_t HATOX_BTN_FAST = (1 << 1); //Bitposition for Rabbit Button
    static constexpr int16_t HATOX_BTN_SLOW = (1 << 2); //Bitposition for Turtle Button
    static constexpr int16_t HATOX_BTN_1 = (1 << 3);    //Bitposition for 1 Button
    static constexpr int16_t HATOX_BTN_2 = (1 << 4);    //Bitposition for 2 Button
    static constexpr int16_t HATOX_BTN_3 = (1 << 5);    //Bitposition for 3 Button
    static constexpr int16_t HATOX_BTN_4 = (1 << 6);    //Bitposition for 4 Button
    static constexpr int16_t HATOX_BTN_STOP = (1 << 7); //Bitposition for STOP Button
    static constexpr int16_t HATOX_BTN_5 = (1 << 8);    //Bitposition for 5 Button
    static constexpr int16_t HATOX_BTN_6 = (1 << 9);    //Bitposition for 6 Button

public:
    CO_t *_CO;

    int8_t init(CO_t *CO);
    uint8_t getLeftStickX();
    uint8_t getLeftStickY();
    uint8_t getRightStickX();
    uint8_t getRightStickY();
    uint8_t getStickDir();
    uint16_t getButtonStatus();
    uint8_t setText(uint8_t line, uint8_t column, std::string text);
};

#endif