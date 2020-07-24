/**
 * @file Hatox.c
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
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

uint8_t getLeftStickX() { return OD_statusRegister[ODA_statusRegister_analogDat2]; }
uint8_t getLeftStickY() { return OD_statusRegister[ODA_statusRegister_analogDat1]; }
uint8_t getRightStickX() { return OD_statusRegister[ODA_statusRegister_analogDat4]; }
uint8_t getRightStickY() { return OD_statusRegister[ODA_statusRegister_analogDat3]; }
uint8_t getStickDir() { return OD_statusRegister[ODA_statusRegister_analogDat0]; }
uint16_t getButtonStatus() { return (OD_statusRegister[ODA_statusRegister_digitalDat1] << 8) + OD_statusRegister[ODA_statusRegister_digitalDat0]; }

uint8_t setText(uint8_t line, uint8_t column, const char *text, uint8_t len)
{
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

uint8_t initText()
{
  setText(1, 1, "FH-Dor", 6);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  setText(1, 7, "tmund ", 6);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  setText(1, 13, "MTD4", 4);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  setText(2, 1, "Speed:", 6);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  setText(3, 1, "Mode: ", 6);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  return 1;
}