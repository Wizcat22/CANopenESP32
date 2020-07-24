/**
 * @file Hatox.h
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Hatox 
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
uint8_t initText();

#endif