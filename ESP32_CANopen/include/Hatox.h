#ifndef HATOX_H_
#define HATOX_H_

#define HATOX_BTN_RUN 1
#define HATOX_BTN_FAST 2
#define HATOX_BTN_SLOW 4
#define HATOX_BTN_1 8
#define HATOX_BTN_2 16
#define HATOX_BTN_3 32
#define HATOX_BTN_4 64
#define HATOX_BTN_STOP 128
#define HATOX_BTN_5 256
#define HATOX_BTN_6 512

#include "CANopen.h"
#include <stdint.h>
#include "CO_OD.h"

uint8_t getLeftStickX();
uint8_t getLeftStickY();
uint8_t getRightStickX();
uint8_t getRightStickY();
uint8_t getStickDir();
uint16_t getButtonStatus();
uint8_t setText(uint8_t line, uint8_t column, const char *text, uint8_t len);

#endif