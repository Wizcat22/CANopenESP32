/**
 * @file imslROS.cpp
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Rossserial 
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

#include "ros.h"
#include "geometry_msgs/Pose.h"
#include "sensor_msgs/Temperature.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Float32.h"
#include "driver/can.h"
#include "imslROS.h"
extern "C"
{
#include "Gyro.h"
}

ros::NodeHandle nh; /** Rosserial nodehandle */

geometry_msgs::Pose GyroAngleMsg;
ros::Publisher GyroAnglePub("gyro_angle", &GyroAngleMsg);

std_msgs::Float32 GyroTemperatureMsg;
ros::Publisher GyroTemperaturePub("gyro_temperature", &GyroTemperatureMsg);

std_msgs::UInt8 GyroLifeCounterMsg;
ros::Publisher GyroLifeCounterPub("gyro_lifeCounter", &GyroLifeCounterMsg);

std_msgs::Bool GyroDriftCompensationActiveMsg;
ros::Publisher GyroDriftCompensationActivePub("gyro_driftCompensationActive", &GyroDriftCompensationActiveMsg);

std_msgs::Bool GyroDriftCompensationCompleteMsg;
ros::Publisher GyroDriftCompensationCompletePub("gyro_driftCompensationActive", &GyroDriftCompensationCompleteMsg);

std_msgs::Bool GyroConfirmAngleSetZeroMsg;
ros::Publisher GyroConfirmAngleSetZeroPub("gyro_GyroConfirmAngleSetZero", &GyroConfirmAngleSetZeroMsg);

std_msgs::Bool GyroParameterErrorMsg;
ros::Publisher GyroParameterErrorPub("gyro_GyroParameterError", &GyroParameterErrorMsg);

bool old_angle_to_zero_status = false;
bool old_drift_compensation_status = false;


void sub_angle_to_zero(const std_msgs::Bool &activateAngleToZeroMsg)
{
  if (old_angle_to_zero_status != activateAngleToZeroMsg.data)
  {
    if (activateAngleToZeroMsg.data == true)
    {
      enableAngleToZero();
    }
    else
    {
      disableAngleToZero();
    }
    old_angle_to_zero_status = activateAngleToZeroMsg.data;
  } else
  {
    //Do Nothing
  }
}
ros::Subscriber<std_msgs::Bool> subAngleToZero("gyro_command_angle_to_zero", sub_angle_to_zero);

void sub_DriftCompensation(const std_msgs::Bool &activateDriftCompensationMsg)
{
  if (old_drift_compensation_status != activateDriftCompensationMsg.data)
  {
    if (activateDriftCompensationMsg.data == true)
    {
      enableAngleToZero();
    }
    else
    {
      disableAngleToZero();
    }
    old_drift_compensation_status = activateDriftCompensationMsg.data;
  } else
  {
    //Do Nothing
  }

}
ros::Subscriber<std_msgs::Bool> subDriftCompensation("gyro_command_drift_compensation", sub_DriftCompensation);

void rosserialSetup()
{
  nh.initNode();
  nh.advertise(GyroAnglePub);
  nh.advertise(GyroTemperaturePub);
  nh.advertise(GyroLifeCounterPub);
  nh.advertise(GyroDriftCompensationActivePub);
  nh.advertise(GyroDriftCompensationCompletePub);
  nh.advertise(GyroConfirmAngleSetZeroPub);
  nh.advertise(GyroParameterErrorPub);
  nh.subscribe(subAngleToZero);
  nh.subscribe(subDriftCompensation);
}

void rosserialPublish()
{
  GyroAngleMsg.orientation.z = getAngle(false);
  GyroAnglePub.publish(&GyroAngleMsg);
  GyroTemperatureMsg.data = getTemperature();
  GyroTemperaturePub.publish(&GyroTemperatureMsg);
  GyroLifeCounterMsg.data = getLifeCounter();
  GyroLifeCounterPub.publish(&GyroLifeCounterMsg);
  GyroDriftCompensationActiveMsg.data = (bool)(isDriftCompenstaionActive());
  GyroDriftCompensationActivePub.publish(&GyroDriftCompensationActiveMsg);
  GyroDriftCompensationCompleteMsg.data = (bool)(isDriftCompenstaionComplete());
  GyroDriftCompensationCompletePub.publish(&GyroDriftCompensationCompleteMsg);
  GyroConfirmAngleSetZeroMsg.data = (bool)(confirmAngleSetToZero());
  GyroConfirmAngleSetZeroPub.publish(&GyroConfirmAngleSetZeroMsg);
  GyroParameterErrorMsg.data = (bool)(GyroParameterError());
  GyroParameterErrorPub.publish(&GyroParameterErrorMsg);
}

void NodeHandleSpin()
{
  nh.spinOnce();
}