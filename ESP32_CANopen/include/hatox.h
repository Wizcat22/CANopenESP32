/**
 * @file hatox.h
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