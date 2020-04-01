/**
 * @file imslRos.cc
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Rosserial
 * @version 0.1
 * @date 2019-09-13
 * 
 * @copyright Copyright (c) 2019
 * 
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
extern "C"
{
#include "Hatox.h"
}

ros::NodeHandle nh; /** Rosserial nodehandle */

/*Messages*/
std_msgs::UInt8MultiArray hatoxDataMsg; /** Rosmessage for hatox data */
geometry_msgs::Twist hatoxVelMsg;       /** Rosmessage for twist data */
std_msgs::Bool hatoxEnableMsg;          /** Rosmessage for MxVk LOS Module data */
std_msgs::Int8 minimaxModulCtrlMsg;     /** Rosmessage for hatox data */
std_msgs::Bool mtd4ShutdownMsg;

/*Publisher*/
ros::Publisher hatoxDataPub("hatox_data", &hatoxDataMsg);             /** Rosserial publisher for topic "/hatox_data" */
ros::Publisher hatoxVelPub("cmd_vel", &hatoxVelMsg);                  /** Rosserial publisher for topic "/cmd_vel" */
ros::Publisher hatoxEnablePub("enable", &hatoxEnableMsg);             /** Rosserial publisher for topic "/enable" */
ros::Publisher minimaxModulCtrlPub("LOS_CMDS", &minimaxModulCtrlMsg); /** Rosserial publisher for topic "/LOS_CMDS" */
ros::Publisher mtd4ShutdownPub("shutdown", &mtd4ShutdownMsg);         /** Rosserial publisher for topic "/shutdown" */

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
      const char text[] = {0x02, 0x0A, 0x49, 0x64, 0x6C, 0x65, 0x00, 0x00};
      setText(2, 0x0A, text, 6);
      last_rob_status = rob_status;
    }
    if (rob_status == 1)
    {
      const char text[] = {0x02, 0x0A, 0x45, 0x2D, 0x53, 0x74, 0x6F, 0x70};
      setText(2, 0x0A, text, 6);
      last_rob_status = rob_status;
    }
    if (rob_status == 2)
    {
      const char text[] = {0x02, 0x0A, 0x54, 0x77, 0x69, 0x73, 0x74, 0x00};
      setText(2, 0x0A, text, 6);
      last_rob_status = rob_status;
    }
  }
}

//MxVk Module Status Callback
void sub_minimax_status_cb(const std_msgs::Int8 &status_msg)
{
  switch (status_msg.data)
  {
  case 1:
    setText(3, 5, "Stat 1", 6);
    break;
  case 2:
    setText(3, 5, "Alarm!", 6);
    break;
  case 3:
    setText(3, 5, "Alarm!", 6);
    break;
  case 100:
    setText(3, 5, "Idle  ", 6);
    break;

  default:
    setText(3, 5, "Error!", 6);
    break;
  }
}

/*Subscriber*/
ros::Subscriber<std_msgs::Byte> sub("ctrl_status", sub_status_cb);             /*Subscriber for Robot Status Message: /ctrl_status*/
ros::Subscriber<std_msgs::Int8> subMinimax("LOS_STAT", sub_minimax_status_cb); /*Subscriber for MxVk Module Status Message: LOS_STAT*/

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

    linearVelocity = (MAX_LINEAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
    angularVelocity = (MAX_ANGULAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
    if (linearVelocity > MAX_LINEAR_VEL)
    {
      linearVelocity = MAX_LINEAR_VEL;
    }
    if (angularVelocity > MAX_ANGULAR_VEL)
    {
      angularVelocity = MAX_ANGULAR_VEL;
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

    linearVelocity = (MAX_LINEAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
    angularVelocity = (MAX_ANGULAR_VEL / MAX_SPEED_LEVEL) * speedLevel;
    if (linearVelocity < 0)
    {
      linearVelocity = 0;
    }
    if (angularVelocity < 0)
    {
      angularVelocity = 0;
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

  //Minimax SEND 1 (Button 3)
  if (getButtonStatus() & HATOX_BTN_3 && hatoxButtonsReleased == true)
  {
    minimaxModulCtrlMsg.data = 1;
    minimaxModulCtrlPub.publish(&minimaxModulCtrlMsg);
  }
  //Minimax SEND 2 (Button 4)
  if (getButtonStatus() & HATOX_BTN_4 && hatoxButtonsReleased == true)
  {
    minimaxModulCtrlMsg.data = 2;
    minimaxModulCtrlPub.publish(&minimaxModulCtrlMsg);
  }
  //Minimax SEND 3 (Button 5)
  if (getButtonStatus() & HATOX_BTN_5 && hatoxButtonsReleased == true)
  {
    hatoxButtonsReleased = false;
    minimaxModulCtrlMsg.data = 3;
    minimaxModulCtrlPub.publish(&minimaxModulCtrlMsg);
  }
  //Shutdown MT-D4 (Button 6)
  if (getButtonStatus() & HATOX_BTN_6 && hatoxButtonsReleased == true)
  {
    setText(2, 10, "SHDWN!", 6);
    hatoxButtonsReleased = false;
    mtd4ShutdownMsg.data = true;
    mtd4ShutdownPub.publish(&mtd4ShutdownMsg);
  }

  // //Minimax SEND 4 (Button 6)
  // if (data[6] & 0b0000010 && hatoxButtonsReleased == true)
  // {
  //   hatoxButtonsReleased = false;
  //   minimaxModulCtrlMsg.data = 4;
  //   minimaxModulCtrlPub.publish(&minimaxModulCtrlMsg);
  // }

  /*No Button Pressed*/
  if (getButtonStatus() == 128)
  {
    hatoxButtonsReleased = true;
    minimaxModulCtrlMsg.data = 5;
    minimaxModulCtrlPub.publish(&minimaxModulCtrlMsg);
  }
}

/* Handle Joysticks*/
void handleSpeed()
{
  if (last_speedLevel != speedLevel)
  {
    const char text[] = {0x53, 0x3A, (unsigned char)(0x30 + speedLevel), 0, 0, 0};
    setText(1, 14, text, 1);
    last_speedLevel = speedLevel;
  }

  //Set values in twist message based on hatox data
  hatoxVelMsg.linear.x = (getLeftStickY() - 127) / 127.0f * -linearVelocity;
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
  nh.advertise(minimaxModulCtrlPub);
  nh.advertise(mtd4ShutdownPub);
  nh.subscribe(sub);
  nh.subscribe(subMinimax);
}

void rosserialPublish()
{
  //Hatox data [PDO1_0,PDO1_1,PDO1_2,PDO1_3,PDO1_4,PDO2_0,PDO2_1]
  uint8_t data[] = {OD_statusRegister[ODA_statusRegister_analogDat0], OD_statusRegister[ODA_statusRegister_analogDat1], OD_statusRegister[ODA_statusRegister_analogDat2], OD_statusRegister[ODA_statusRegister_analogDat3], OD_statusRegister[ODA_statusRegister_analogDat4], OD_statusRegister[ODA_statusRegister_digitalDat0], OD_statusRegister[ODA_statusRegister_digitalDat1]};
  hatoxDataMsg.data = data; /**  */
  //Number of bytes in hatox data
  hatoxDataMsg.data_length = 7; /**  */
  hatoxDataPub.publish(&hatoxDataMsg);

  handleButtons();
  handleSpeed();
}

void NodeHandleSpin()
{
  nh.spinOnce();
}