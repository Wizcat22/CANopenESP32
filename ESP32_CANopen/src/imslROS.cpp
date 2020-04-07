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

#include "ros.h"
#include "geometry_msgs/Pose.h"
#include "sensor_msgs/Temperature.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Float32.h"
#include "driver/can.h"
#include "imslROS.h"

ros::NodeHandle nh; /** Rosserial nodehandle */

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