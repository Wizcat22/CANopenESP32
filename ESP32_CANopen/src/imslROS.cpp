/**
 * @file imslROS.cpp
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @brief Rosserial
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

ros::NodeHandle nh; /** Rosserial nodehandle */

/*Messages*/

/*Publisher*/

/*Variables*/

void rosserialSetup()
{
  nh.initNode();
}

void rosserialPublish()
{
}

void NodeHandleSpin()
{
  nh.spinOnce();
}