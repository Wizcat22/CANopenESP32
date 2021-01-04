/**
 * @file hatox_config.h
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Configuration File 
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

#ifndef HATOX_CONFIG_H
#define HATOX_CONFIG_H

//####  MAIN CONFIG  ####
#define MAIN_WAIT 100 /** Time in ms between every main loop cycle */

//----------------------------------

//####  ROS MESSAGE CONFIG  ####

#define MAX_LINEAR_VEL 5.0          /** Maximum linear velocity in m/s */
#define MAX_ANGULAR_VEL 0.5         /** Maximum angular velocity in rad/s */
#define MAX_SPEED_LEVEL 10          /** Maximum angular velocity in rad/s */
#define MAX_LINEAR_VEL_REVERSE -0.2 /** Maximum linear reverse velocity in m/s */

//----------------------------------

//####  ROSSERIAL CONFIG  ####
#define ROS_SERVER_AP "ESPNet"
#define ROS_SERVER_PASS "fb2fe3eda4"

//#define CONFIG_ROSSERIAL_OVER_SERIAL /** Use Serial */
#define CONFIG_ROSSERIAL_OVER_ETH /** Use Ethernet instead of Serial */
//#define CONFIG_ROSSERIAL_OVER_WIFI    /** Use WIFI instead of Serial */

#define ROS_SERVER_IP "192.168.10.200" /** Rosserial server ip */
//#define ROS_SERVER_IP "10.0.101.194" /** Rosserial server ip (DEV!) */
#define ROS_SERVER_PORT 11411 /** Rosserial server port */

#define UART_PORT UART_NUM_0   /** Serial interface for Rosserial */
#define UART_TX_PIN GPIO_NUM_1 /** Serial TX Pinnummber */
#define UART_RX_PIN GPIO_NUM_3 /** Serial RX Pinnummber */

#define DEFAULT_ETHERNET_PHY_CONFIG phy_lan8720_default_ethernet_config /** Default Ethernet configuration */

#define PIN_SMI_MDC 23  /** PHY ETH MDC Pinnumber */
#define PIN_SMI_MDIO 18 /** PYH ETH MDIO Pinnumber */

#endif /* HATOX_CONFIG_H */