/**
 * @file hatox.cpp
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

#include "Hatox.h"
#include "esp_log.h"

int8_t Hatox::init(CO_t *CO)
{
  int8_t ret = 0;
  _CO = CO;
  return ret;
}

uint8_t Hatox::getLeftStickX() { return OD_hatox_status_register[ODA_hatox_status_register_analog_data_2]; }
uint8_t Hatox::getLeftStickY() { return OD_hatox_status_register[ODA_hatox_status_register_analog_data_1]; }
uint8_t Hatox::getRightStickX() { return OD_hatox_status_register[ODA_hatox_status_register_analog_data_4]; }
uint8_t Hatox::getRightStickY() { return OD_hatox_status_register[ODA_hatox_status_register_analog_data_3]; }
uint8_t Hatox::getStickDir() { return OD_hatox_status_register[ODA_hatox_status_register_analog_data_0]; }
uint16_t Hatox::getButtonStatus() { return (OD_hatox_status_register[ODA_hatox_status_register_digital_data_1] << 8) + OD_hatox_status_register[ODA_hatox_status_register_digital_data_0]; }

uint8_t Hatox::setText(uint8_t line, uint8_t column, std::string text)
{
  while (CO->TPDO[0]->sendRequest == 1)
  {
  }
  if (text.length() < 7 && text.length() > 0 && line > 0 && line < 4 && column > 0 && column < 17)
  {
    OD_hatox_command_register[ODA_hatox_command_register_line] = line;
    OD_hatox_command_register[ODA_hatox_command_register_column] = column;
    for (uint8_t i = 0; i < text.length(); i++)
    {
      OD_hatox_command_register[ODA_hatox_command_register_char_0 + i] = text[i];
    }
    CO->TPDO[0]->sendRequest = 1;
    return 1;
  }
  return 0;
}