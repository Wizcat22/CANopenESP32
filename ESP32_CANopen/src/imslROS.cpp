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
#include "std_msgs/Int32.h"
#include "std_msgs/UInt8MultiArray.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_srvs/SetBool.h"
#include "drz_mod_bus_msgs/ModuleMsg.h"
//#include "ros_custom_messages/modul_info.h"
#include "modul_identification/modul_identification_msg.h"

extern "C"
{
#include "Hatox.h"
}

ros::NodeHandle nh;     /** Rosserial nodehandle */
bool sendIdent = false; /** ModulIdentMsg has been send */
/*Messages*/
geometry_msgs::Twist hatoxVelMsg;      /** Rosmessage for twist data */
geometry_msgs::Twist hatoxVelMsgPTU;   /** Rosmessage for PTU twist data */
std_msgs::Bool hatoxEnableMsg;         /** Rosmessage for MxVk LOS Module data */
std_msgs::Bool mtd4ShutdownMsg;        /** Rosmessage for Shutdown data */
drz_mod_bus_msgs::ModuleMsg modBusMsg; /** Rosmessage for Enable */
modul_identification::modul_identification_msg modulIdentMsg;
std_msgs::Int32 losMsg; /** Rosmessage for Shutdown data */

/*Publisher*/
ros::Publisher modulIdentPub("modulIdent", &modulIdentMsg);
ros::Publisher losPub("LOS/setValveStatus", &losMsg);
//asd = new ros::Publisher("hatox_data", &hatoxDataMsg);
ros::Publisher *hatoxVelPub = nullptr;     /** Rosserial publisher for topic "/cmd_vel" */
ros::Publisher *hatoxVelPubPTU = nullptr;  /** Rosserial publisher for topic "/cmd_vel" */
ros::Publisher *hatoxEnablePub = nullptr;  /** Rosserial publisher for topic "/enable" */
ros::Publisher *mtd4ShutdownPub = nullptr; /** Rosserial publisher for topic "/shutdown" */
ros::Publisher *modBusPub = nullptr;       /** Rosserial publisher for topic "/drz_mod_bus" */
//ros::Publisher mtd4TestPub("modul_info", &mtd4TestMsg);         /** Rosserial publisher for topic "/shutdown" */

/*Variables*/
uint8_t rob_status = 0;        /* Robot Status*/
uint8_t last_rob_status = 254; /* Last used Robot Status*/
uint8_t speedLevel = 1;        /* Robot Speed Multiplier*/
uint8_t last_speedLevel = 0;   /* Last used Robot Speed Multiplier*/
bool toggle = false;

int32_t mxvk_data[] = {0, 0, 0, 0, 0};

double linearVelocity = (MAX_LINEAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
double angularVelocity = (MAX_ANGULAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
bool hatoxButtonsReleased = true;
uint32_t pressDuration = 0; //Amount of time in microseconds since last buttonpress
uint8_t lastPressed = 127;  //Last pressed button (127 if no button pressed)

/*Callbacks*/

//Robot Status Callback
void sub_status_cb(const std_msgs::Byte &status_msg)
{
  rob_status = status_msg.data;
  if (last_rob_status != rob_status)
  {
    switch (rob_status)
    {
    case 0: //IDLE
      setText(3, 7, "Idle..", 6);
      break;
    case 1: //ESTOP
      setText(3, 7, "E-Stop", 6);
      break;
    case 2: //TWIST
      setText(3, 7, "Twist ", 6);
      break;
    case 3: //AUTO
      setText(3, 7, "AUTO ", 6);
      break;
    default: //UNKNOWN
      setText(3, 7, "??????", 6);
      break;
    }
    last_rob_status = rob_status;
  }
}

/*Subscriber*/
ros::Subscriber<std_msgs::Byte> sub("/D4/drz_mob/status", sub_status_cb); /*Subscriber for Robot Status Message: /ctrl_status*/

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
    if (modBusPub != nullptr)
    {
      modBusMsg.from = "HAN";
      modBusMsg.to = "MOB";
      modBusMsg.command = "engine";
      if (rob_status == 0) //ROBOT IS IDLE
      {
        modBusMsg.i1 = 1; //ENABLE TWIST
      }
      else // if (rob_status == 2) //ROBOT IS IN TWIST
      {
        modBusMsg.i1 = 0; //DISABLE
      }
      modBusPub->publish(&modBusMsg);
      hatoxButtonsReleased = false;
    }
  }

  //Toggle AUTO-Mode (Button 2)
  if (getButtonStatus() & HATOX_BTN_2 && hatoxButtonsReleased == true)
  {
    if (modBusPub != nullptr)
    {
      modBusMsg.from = "HAN";
      modBusMsg.to = "MOB";
      modBusMsg.command = "engine";
      if (rob_status == 0) //ROBOT IS IDLE
      {
        modBusMsg.i1 = 2; //ENABLE AUTO
      }
      else // if (rob_status == 2) //ROBOT IS IN AUTO
      {
        modBusMsg.i1 = 0; //DISABLE
      }
      modBusPub->publish(&modBusMsg);
      hatoxButtonsReleased = false;
    }
  }

  //(Button 3)
  if (getButtonStatus() & HATOX_BTN_3 && hatoxButtonsReleased == true)
  {
    pressDuration = esp_timer_get_time();
    lastPressed = 3;
    hatoxButtonsReleased = false;
  }

  // (Button 4)
  if (getButtonStatus() & HATOX_BTN_4 && hatoxButtonsReleased == true)
  {
    pressDuration = esp_timer_get_time();
    lastPressed = 4;
    hatoxButtonsReleased = false;
  }

  //Toggle Monitor Motor(Button 5)
  if (getButtonStatus() & HATOX_BTN_5 && hatoxButtonsReleased == true)
  {
    if (modBusPub != nullptr)
    {
      modBusMsg.from = "HAN";
      modBusMsg.to = "Monitor";
      modBusMsg.command = "motorToggle";
      modBusPub->publish(&modBusMsg);
      hatoxButtonsReleased = false;
    }
  }

  //Shutdown MT-D4 (Button 6)
  if (getButtonStatus() & HATOX_BTN_6 && hatoxButtonsReleased == true)
  {
    if (mtd4ShutdownPub != nullptr)
    {
      setText(3, 7, "SHDWN!", 6);
      hatoxButtonsReleased = false;
      mtd4ShutdownMsg.data = true;
      mtd4ShutdownPub->publish(&mtd4ShutdownMsg);
    }
  }
  /*No Button Pressed*/
  if (getButtonStatus() == 128 && hatoxButtonsReleased == false)
  {
    hatoxButtonsReleased = true;
    pressDuration = esp_timer_get_time() - pressDuration;
    bool longpress = false;

    if (pressDuration > 2000000)
    {
      longpress = true;
    }
    else
    {
      longpress = false;
    }

    switch (lastPressed)
    {
    case 3:
      if (!longpress)
      {
        //MINIMAX Druckventil 1 öffnen/schließen
        losMsg.data = 0;
        losPub.publish(&losMsg);
      }
      else
      {
        //MINIMAX Löschmittelventil 1 öffnen/schließen
        losMsg.data = 2;
        losPub.publish(&losMsg);
      }
      break;
    case 4:
      if (!longpress)
      {
        //MINIMAX Druckventil 2 öffnen/schließen
        losMsg.data = 1;
        losPub.publish(&losMsg);
      }
      else
      {
        //MINIMAX Löschmittelventil 2 öffnen/schließen
        losMsg.data = 3;
        losPub.publish(&losMsg);
      }
      break;

    default:
      break;
    }

    lastPressed = 127;
    pressDuration = 0;
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

  hatoxVelMsg.linear.y = 0; //(getLeftStickX() - 127) / 127.0f * linearVelocity;
  hatoxVelMsg.linear.z = 0;
  hatoxVelMsg.angular.x = 0;
  hatoxVelMsg.angular.y = 0; //(getRightStickY() - 127) / 127.0f * -angularVelocity;
  hatoxVelMsg.angular.z = (getLeftStickX() - 127) / 127.0f * -angularVelocity;

  if (hatoxVelPubPTU != nullptr)
  {
    hatoxVelMsgPTU.angular.x = -(getRightStickX() - 127) / 127.0f * 100;
    hatoxVelMsgPTU.angular.y = -(getRightStickY() - 127) / 127.0f * 100;
    hatoxVelPubPTU->publish(&hatoxVelMsgPTU);
  }
  if (hatoxVelPub != nullptr && rob_status == 2) //Publish in TWIST Mode only
  {
    hatoxVelPub->publish(&hatoxVelMsg);
  }
}

/*ROS Functions*/

void rosserialSetup()
{
  // Initialize ROS
  nh.initNode();
  //Advertise all topics
  hatoxVelPub = new ros::Publisher("drz_han/cmd_vel", &hatoxVelMsg);            /** Rosserial publisher for topic "/cmd_vel" */
  hatoxVelPubPTU = new ros::Publisher("controller/direction", &hatoxVelMsgPTU); /** Rosserial publisher for topic "/cmd_vel" */
  hatoxEnablePub = new ros::Publisher("enable", &hatoxEnableMsg);               /** Rosserial publisher for topic "/enable" */
  mtd4ShutdownPub = new ros::Publisher("shutdown", &mtd4ShutdownMsg);           /** Rosserial publisher for topic "/shutdown" */
  modBusPub = new ros::Publisher("drz_mod_bus", &modBusMsg);                    /** Rosserial publisher for topic "/drz_mod_bus" */

  nh.advertise(*hatoxVelPub);
  nh.advertise(*hatoxVelPubPTU);
  nh.advertise(*hatoxEnablePub);
  nh.advertise(*mtd4ShutdownPub);
  nh.advertise(*modBusPub);
  nh.advertise(losPub);
  //nh.negotiateTopics();

  nh.advertise(modulIdentPub);

  nh.subscribe(sub);
}

void rosserialPublish()
{
  if (nh.connected())
  {
    if (sendIdent == false)
    {
      vTaskDelay(500 / portTICK_PERIOD_MS); //Delay is neccessary because first messages after advertisement of publisher may get lost
      modulIdentMsg.power = 10;
      modulIdentMsg.modul_id = "5E00011225AB9801";
      modulIdentMsg.modul_name = "drz_han";
      modulIdentMsg.connectors_used = 1;
      modulIdentPub.publish(&modulIdentMsg);

      sendIdent = true;
    }

    handleButtons();
    handleSpeed();
  }
}

void NodeHandleSpin()
{
  nh.spinOnce();
}