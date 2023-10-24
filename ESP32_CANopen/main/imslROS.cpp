/**
 * @file imslROS.cpp
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @author Mathias Parys    (mathias.parys@fh-dortmund.de)
 * @author Valerij Sekin    (valerij.sekin@fh-dortmund.de)
 * @brief Ros2
 * @version 0.1
 * @date 2023-10-24
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

// will only restart when initialization fails, restarting agent will not restart esp
#define RCCHECK(fn)                                                                      \
    {                                                                                    \
        rcl_ret_t temp_rc = fn;                                                          \
        if ((temp_rc != RCL_RET_OK))                                                     \
        {                                                                                \
            printf("Failed status on line %d: %d. Aborting.\n", __LINE__, (int)temp_rc); \
            esp_restart();                                                               \
            \   
                                                                             \
        }                                                                                \
    }
#define RCSOFTCHECK(fn)                                                                    \
    {                                                                                      \
        rcl_ret_t temp_rc = fn;                                                            \
        if ((temp_rc != RCL_RET_OK))                                                       \
        {                                                                                  \
            printf("Failed status on line %d: %d. Continuing.\n", __LINE__, (int)temp_rc); \
        }                                                                                  \
    }

#include "imslROS.h"
#include <string.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "soc/soc.h"
#include "driver/can.h"
#include "modul_config.h"

// ros2
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/timer.h>
#include <rclc/executor.h>
#include <geometry_msgs/msg/twist.h>
#include <std_msgs/msg/bool.h>    // for enable topic
#include <std_msgs/msg/byte.h>    // for ctrl_status
#include <std_msgs/msg/u_int8.h>  // for sick_status
#include <std_msgs/msg/u_int32.h> // for Virtual Bumper
#include <uros_network_interfaces.h>
#include <rmw_microros/rmw_microros.h>
#include <uxr/client/config.h>

extern "C"
{
#include "Hatox.h"
}

bool sendIdent = false; /** ModulIdentMsg has been send */


/*Subscriber*/
rcl_subscription_t sub_status;
std_msgs__msg__Byte status_msg;

static rcl_node_t node;
static rclc_executor_t executor;

/*Publisher*/
rcl_publisher_t hatoxVelPub;    /** Ros2 publisher for topic "/cmd_vel" */
rcl_publisher_t hatoxEnablePub; /** Ros2 publisher for topic "/enable" */

geometry_msgs__msg__Twist hatoxVelMsg; /** Rosmessage for twist data */
std_msgs__msg__Bool hatoxEnableMsg;    /** Rosmessage for MxVk LOS Module data */

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
uint32_t pressDuration = 0; // Amount of time in microseconds since last buttonpress
uint8_t lastPressed = 127;  // Last pressed button (127 if no button pressed)



void connectWifi()
  {
      /*Change: micro_ros_espidf_component -> colcon.meta to udp (Wifi) or custom (Serial)

          "rmw_microxrcedds":
                "-DRMW_UXRCE_TRANSPORT= ",

        Then also change in "idf.py menuconfig" the communication and
        run in Terminal "idf.py clean-microros" and "idf.py fullclean" before running "idf.py build"
      */

      #ifdef RMW_UXRCE_TRANSPORT_UDP
      int timeoutCounter = 0;         // Timeout counter ToDo: Instead of waiting for x iterations wait for specified Time -> save value in configuration file
      while (uros_network_interface_initialize() != ESP_OK) // Wait until Network is ready
      {
        printf(".");
        fflush(stdout);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        if (timeoutCounter++ > 50)
        {
          esp_restart(); // Restart ESP if network connection cant be established
        }
      }
      #endif
  }

/*Callbacks*/

// Robot Status Callback
void sub_status_cb(const void* status_msg)
{
    std_msgs__msg__Byte *msg = (std_msgs__msg__Byte *)status_msg;
    rob_status = msg->data;
    if (last_rob_status != rob_status)
    {
        switch (rob_status)
        {
        case 0: // IDLE
            setText(3, 7, "Idle..", 6);
            break;
        case 1: // ESTOP
            setText(3, 7, "E-Stop", 6);
            break;
        case 2: // TWIST
            setText(3, 7, "Twist ", 6);
            break;
        case 3: // AUTO
            setText(3, 7, "AUTO ", 6);
            break;
        default: // UNKNOWN
            setText(3, 7, "??????", 6);
            break;
        }
        last_rob_status = rob_status;
    }
}

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
    // Decrease speed (Button Turtle)
    if ((getButtonStatus() & HATOX_BTN_SLOW) && (hatoxButtonsReleased == true))
    {
        hatoxButtonsReleased = false;
        if (speedLevel > 1)
        {
            --speedLevel;
        }
    }

    // Enable Motors (Button 1)
    if (getButtonStatus() & HATOX_BTN_1 && hatoxButtonsReleased == true)
    {
        toggle = true;
        hatoxEnableMsg.data = true;
        hatoxButtonsReleased = false;

        // if (modBusPub != nullptr)
        // {
        //     modBusMsg.from = "HAN";
        //     modBusMsg.to = "MOB";
        //     modBusMsg.command = "engine";
        //     if (rob_status == 0) // ROBOT IS IDLE
        //     {
        //         modBusMsg.i1 = 1; // ENABLE TWIST
        //     }
        //     else // if (rob_status == 2) //ROBOT IS IN TWIST
        //     {
        //         modBusMsg.i1 = 0; // DISABLE
        //     }
        //     modBusPub->publish(&modBusMsg);
        //     hatoxButtonsReleased = false;
        // }
    }

    // // Toggle AUTO-Mode (Button 2)
    // if (getButtonStatus() & HATOX_BTN_2 && hatoxButtonsReleased == true)
    // {
    //     if (modBusPub != nullptr)
    //     {
    //         modBusMsg.from = "HAN";
    //         modBusMsg.to = "MOB";
    //         modBusMsg.command = "engine";
    //         if (rob_status == 0) // ROBOT IS IDLE
    //         {
    //             modBusMsg.i1 = 2; // ENABLE AUTO
    //         }
    //         else // if (rob_status == 2) //ROBOT IS IN AUTO
    //         {
    //             modBusMsg.i1 = 0; // DISABLE
    //         }
    //         modBusPub->publish(&modBusMsg);
    //         hatoxButtonsReleased = false;
    //     }
    // }

    // //(Button 3)
    // if (getButtonStatus() & HATOX_BTN_3 && hatoxButtonsReleased == true)
    // {
    //     pressDuration = esp_timer_get_time();
    //     lastPressed = 3;
    //     hatoxButtonsReleased = false;
    // }

    // // (Button 4)
    // if (getButtonStatus() & HATOX_BTN_4 && hatoxButtonsReleased == true)
    // {
    //     pressDuration = esp_timer_get_time();
    //     lastPressed = 4;
    //     hatoxButtonsReleased = false;
    // }

    // // Toggle Monitor Motor(Button 5)
    // if (getButtonStatus() & HATOX_BTN_5 && hatoxButtonsReleased == true)
    // {
    //     if (modBusPub != nullptr)
    //     {
    //         modBusMsg.from = "HAN";
    //         modBusMsg.to = "Monitor";
    //         modBusMsg.command = "motorToggle";
    //         modBusPub->publish(&modBusMsg);
    //         hatoxButtonsReleased = false;
    //     }
    // }

    // // Shutdown MT-D4 (Button 6)
    // if (getButtonStatus() & HATOX_BTN_6 && hatoxButtonsReleased == true)
    // {
    //     if (mtd4ShutdownPub != nullptr)
    //     {
    //         setText(3, 7, "SHDWN!", 6);
    //         hatoxButtonsReleased = false;
    //         mtd4ShutdownMsg.data = true;
    //         mtd4ShutdownPub->publish(&mtd4ShutdownMsg);
    //     }
    // }
    // /*No Button Pressed*/
    // if (getButtonStatus() == 128 && hatoxButtonsReleased == false)
    // {
    //     hatoxButtonsReleased = true;
    //     pressDuration = esp_timer_get_time() - pressDuration;
    //     bool longpress = false;

    //     if (pressDuration > 2000000)
    //     {
    //         longpress = true;
    //     }
    //     else
    //     {
    //         longpress = false;
    //     }

    //     switch (lastPressed)
    //     {
    //     case 3:
    //         if (!longpress)
    //         {
    //             // MINIMAX Druckventil 1 öffnen/schließen
    //             losMsg.data = 0;
    //             losPub.publish(&losMsg);
    //         }
    //         else
    //         {
    //             // MINIMAX Löschmittelventil 1 öffnen/schließen
    //             losMsg.data = 2;
    //             losPub.publish(&losMsg);
    //         }
    //         break;
    //     case 4:
    //         if (!longpress)
    //         {
    //             // MINIMAX Druckventil 2 öffnen/schließen
    //             losMsg.data = 1;
    //             losPub.publish(&losMsg);
    //         }
    //         else
    //         {
    //             // MINIMAX Löschmittelventil 2 öffnen/schließen
    //             losMsg.data = 3;
    //             losPub.publish(&losMsg);
    //         }
    //         break;

    //     default:
    //         break;
    //     }

    //     lastPressed = 127;
    //     pressDuration = 0;
    // }
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

    // Set values in twist message based on hatox data
    hatoxVelMsg.linear.x = (getLeftStickY() - 127) / 127.0f * linearVelocity;

    // Limit reverse velocity
    if (hatoxVelMsg.linear.x < MAX_LINEAR_VEL_REVERSE)
    {
        hatoxVelMsg.linear.x = MAX_LINEAR_VEL_REVERSE;
    }
    
    hatoxVelMsg.linear.y = 0; //(getLeftStickX() - 127) / 127.0f * linearVelocity;
    hatoxVelMsg.linear.z = 0;
    hatoxVelMsg.angular.x = 0;
    hatoxVelMsg.angular.y = 0; //(getRightStickY() - 127) / 127.0f * -angularVelocity;
    hatoxVelMsg.angular.z = (getLeftStickX() - 127) / 127.0f * -angularVelocity;
}

void cmd_cb(rcl_timer_t * timer, int64_t last_call_time)
{
    (void) last_call_time;
    if (timer != NULL) {
      RCSOFTCHECK(rcl_publish(&hatoxVelPub, &hatoxVelMsg, NULL));  
      if(toggle) {
        RCSOFTCHECK(rcl_publish(&hatoxEnablePub, &hatoxEnableMsg, NULL));
        toggle = false;
      }
    }
}

/*ROS Functions*/

void rosInit(void *pvParameter)
{
    rcl_allocator_t allocator = rcl_get_default_allocator();
    rclc_support_t support;

    rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();

    RCCHECK(rcl_init_options_init(&init_options, allocator));
    rmw_init_options_t *rmw_options = rcl_init_options_get_rmw_init_options(&init_options);

    RCCHECK(rmw_uros_options_set_udp_address("192.168.100.200", "8889", rmw_options));

    // Setup support structure.
    RCCHECK(rclc_support_init_with_options(&support, 0, NULL, &init_options, &allocator));

    //Create node for Odometry and Status
    node = rcl_get_zero_initialized_node();
    RCCHECK(rclc_node_init_default(&node, "RobotNode", "", &support));

    RCCHECK(rclc_subscription_init_default(&sub_status, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Byte), "D4_Max/ctrl_status"));
    RCCHECK(rclc_publisher_init_best_effort(&hatoxVelPub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist), "D4_Max/cmd_vel"));
    RCCHECK(rclc_publisher_init_best_effort(&hatoxEnablePub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Bool), "D4_Max/enable"));

    //Create timer.
    rcl_timer_t timer = rcl_get_zero_initialized_timer();
    const unsigned int timer_timeout = 10;
    RCCHECK(rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(timer_timeout), cmd_cb));

    //Create executor
    executor = rclc_executor_get_zero_initialized_executor();
    RCCHECK(rclc_executor_init(&executor, &support.context, 2, &allocator));

    RCCHECK(rclc_executor_add_timer(&executor, &timer));
    RCCHECK(rclc_executor_add_subscription(&executor, &sub_status, &status_msg, &sub_status_cb, ON_NEW_DATA));

    //start spinning
    while(true){
        RCCHECK(rclc_executor_spin_some(&executor, 100));
        handleButtons();
        handleSpeed();
    }

    RCCHECK(rcl_publisher_fini(&hatoxVelPub, &node));
    RCCHECK(rcl_publisher_fini(&hatoxEnablePub, &node));
    RCCHECK(rcl_subscription_fini(&sub_status, &node));
    RCCHECK(rcl_node_fini(&node));
}

// void rosserialPublish()
// {
//     if (nh.connected())
//     {
//         if (sendIdent == false)
//         {
//             vTaskDelay(500 / portTICK_PERIOD_MS); // Delay is neccessary because first messages after advertisement of publisher may get lost
//             modulIdentMsg.power = 10;
//             modulIdentMsg.modul_id = "5E00011225AB9801";
//             modulIdentMsg.modul_name = "drz_han";
//             modulIdentMsg.connectors_used = 1;
//             modulIdentPub.publish(&modulIdentMsg);

//             sendIdent = true;
//         }

//         handleButtons();
//         handleSpeed();
//     }
// }

// void NodeHandleSpin()
// {
//     nh.spinOnce();
// }