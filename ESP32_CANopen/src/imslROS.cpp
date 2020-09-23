/**
 * @file imslROS.cpp
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Rosserial
 * @version 0.1
 * @date 2019-09-13
 * 
 * @copyright Copyright (c) 2019
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

#include "imslROS.h"
#include <string.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "soc/soc.h"
#include "driver/can.h"
#include "geometry_msgs/Twist.h"
#include "ros.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Byte.h"
#include "std_msgs/Int8.h"
#include "std_msgs/UInt8MultiArray.h"
#include "std_srvs/SetBool.h"
//#include "ros_custom_messages/modul_info.h"

extern "C"
{
#include "Hatox.h"
}

ros::NodeHandle nh; /** Rosserial nodehandle */

/*Messages*/
std_msgs::UInt8MultiArray hatoxDataMsg; /** Rosmessage for hatox data */
geometry_msgs::Twist hatoxVelMsg;       /** Rosmessage for twist data */
std_msgs::Bool hatoxEnableMsg;          /** Rosmessage for MxVk LOS Module data */
std_msgs::Bool mtd4ShutdownMsg;
//ros_custom_messages::modul_info mtd4TestMsg;

/*Publisher*/
ros::Publisher hatoxDataPub("hatox_data", &hatoxDataMsg);             /** Rosserial publisher for topic "/hatox_data" */
ros::Publisher hatoxVelPub("cmd_vel", &hatoxVelMsg);                  /** Rosserial publisher for topic "/cmd_vel" */
ros::Publisher hatoxEnablePub("enable", &hatoxEnableMsg);             /** Rosserial publisher for topic "/enable" */
ros::Publisher mtd4ShutdownPub("shutdown", &mtd4ShutdownMsg);         /** Rosserial publisher for topic "/shutdown" */
//ros::Publisher mtd4TestPub("modul_info", &mtd4TestMsg);         /** Rosserial publisher for topic "/shutdown" */

/*Variables*/
uint8_t rob_status = 0;        /* Robot Status*/
uint8_t last_rob_status = 254; /* Last used Robot Status*/
uint8_t speedLevel = 1;        /* Robot Speed Multiplier*/
uint8_t last_speedLevel = 0;   /* Last used Robot Speed Multiplier*/

double linearVelocity = (MAX_LINEAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
double angularVelocity = (MAX_ANGULAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
bool hatoxButtonsReleased = true;

/*Callbacks*/

//Robot Status Callback
void sub_status_cb(const std_msgs::Byte &status_msg)
{
  rob_status = status_msg.data;
  if (last_rob_status != rob_status)
  {
    if (rob_status == 0)
    {
      setText(3, 7, "Idle..", 6);
      last_rob_status = rob_status;
    }
    if (rob_status == 1)
    {
      setText(3, 7, "E-Stop", 6);
      last_rob_status = rob_status;
    }
    if (rob_status == 2)
    {
      setText(3, 7, "Twist ", 6);
      last_rob_status = rob_status;
    }
  }
}

/*Subscriber*/
ros::Subscriber<std_msgs::Byte> sub("ctrl_status", sub_status_cb);             /*Subscriber for Robot Status Message: /ctrl_status*/

/*User Functions*/

/* Handle Buttons*/
void handleButtons()
{
  if ((getButtonStatus() & HATOX_BTN_FAST) && (hatoxButtonsReleased == true))
  {
    hatoxButtonsReleased = false;
    if (speedLevel < MAX_SPEED_LEVEL)
    {
      ++speedLevel;
    }
  }
  //Decrease speed (Button Turtle)
  if ((getButtonStatus() & HATOX_BTN_SLOW) && (hatoxButtonsReleased == true))
  {
    hatoxButtonsReleased = false;
    if (speedLevel > 1)
    {
      --speedLevel;
    }
  }

  //Enable Motors (Button 1)
  if (getButtonStatus() & HATOX_BTN_1 && hatoxButtonsReleased == true)
  {
    hatoxEnableMsg.data = true;
    hatoxEnablePub.publish(&hatoxEnableMsg);
    hatoxButtonsReleased = false;
  }
  //Disable Motors (Button 2)
  if (getButtonStatus() & HATOX_BTN_2 && hatoxButtonsReleased == true)
  {
    speedLevel = 1;
    hatoxEnableMsg.data = false;
    hatoxEnablePub.publish(&hatoxEnableMsg);
    hatoxButtonsReleased = false;
  }
  //Shutdown MT-D4 (Button 6)
  if (getButtonStatus() & HATOX_BTN_6 && hatoxButtonsReleased == true)
  {
    setText(3, 7, "SHDWN!", 6);
    hatoxButtonsReleased = false;
    mtd4ShutdownMsg.data = true;
    mtd4ShutdownPub.publish(&mtd4ShutdownMsg);
  }
  /*No Button Pressed*/
  if (getButtonStatus() == 128)
  {
    hatoxButtonsReleased = true;
  }
}

/* Handle Joysticks*/
void handleSpeed()
{
  if (last_speedLevel != speedLevel)
  {
    last_speedLevel = speedLevel;

    linearVelocity = (MAX_LINEAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
    angularVelocity = MAX_ANGULAR_VEL; //(MAX_ANGULAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
    if (linearVelocity > MAX_LINEAR_VEL)
    {
      linearVelocity = MAX_LINEAR_VEL;
    }
    if (angularVelocity > MAX_ANGULAR_VEL)
    {
      angularVelocity = MAX_ANGULAR_VEL;
    }
    if (linearVelocity < -MAX_LINEAR_VEL)
    {
      linearVelocity = -MAX_LINEAR_VEL;
    }
    if (angularVelocity < -MAX_ANGULAR_VEL)
    {
      angularVelocity = -MAX_ANGULAR_VEL;
    }
    const char text[] = {(unsigned char)(0x30 + linearVelocity), ',', (unsigned char)(0x30 + 10 * (linearVelocity - (int)linearVelocity)), 'm', '/', 's'};
    setText(2, 8, text, 6);
  }

  //Set values in twist message based on hatox data
  hatoxVelMsg.linear.x = (getLeftStickY() - 127) / 127.0f * linearVelocity;

  //Limit reverse velocity
  if (hatoxVelMsg.linear.x < MAX_LINEAR_VEL_REVERSE)
  {
    hatoxVelMsg.linear.x = MAX_LINEAR_VEL_REVERSE;
  }

  hatoxVelMsg.linear.y = (getLeftStickX() - 127) / 127.0f * linearVelocity;
  hatoxVelMsg.linear.z = 0;
  hatoxVelMsg.angular.x = 0;
  hatoxVelMsg.angular.y = 0;
  hatoxVelMsg.angular.z = (getRightStickX() - 127) / 127.0f * -angularVelocity;

  hatoxVelPub.publish(&hatoxVelMsg);
}

/*ROS Functions*/

void rosserialSetup()
{
  // Initialize ROS
  nh.initNode();
  //Advertise all topics
  nh.advertise(hatoxDataPub);
  nh.advertise(hatoxVelPub);
  nh.advertise(hatoxEnablePub);
  nh.advertise(mtd4ShutdownPub);
  //nh.advertise(mtd4TestPub);
  nh.subscribe(sub);
}

void rosserialPublish()
{
  if(nh.connected()){
  //Hatox data [PDO1_0,PDO1_1,PDO1_2,PDO1_3,PDO1_4,PDO2_0,PDO2_1]
  uint8_t data[] = {OD_statusRegister[ODA_statusRegister_analogDat0], OD_statusRegister[ODA_statusRegister_analogDat1], OD_statusRegister[ODA_statusRegister_analogDat2], OD_statusRegister[ODA_statusRegister_analogDat3], OD_statusRegister[ODA_statusRegister_analogDat4], OD_statusRegister[ODA_statusRegister_digitalDat0], OD_statusRegister[ODA_statusRegister_digitalDat1]};
  hatoxDataMsg.data = data; /**  */
  //Number of bytes in hatox data
  hatoxDataMsg.data_length = 7; /**  */
  hatoxDataPub.publish(&hatoxDataMsg);

  // mtd4TestMsg.id = 0xAF;
  // mtd4TestMsg.ip[0] = 0xDE;
  // mtd4TestMsg.ip[1] = 0xAD;
  // mtd4TestMsg.ip[2] = 0xAF;
  // mtd4TestMsg.ip[3] = 0xFE;
  // mtd4TestMsg.name = "AFFE";
  // mtd4TestMsg.power = 0xFE;

  //mtd4TestPub.publish(&mtd4TestMsg);

  handleButtons();
  handleSpeed();
  }
}

void NodeHandleSpin()
{
  nh.spinOnce();
}