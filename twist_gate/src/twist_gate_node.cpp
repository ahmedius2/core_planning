/*
 * Copyright 2015-2019 Autoware Foundation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// ROS Includes
#include <ros/ros.h>

// User defined includes
#include "twist_gate/twist_gate.h"
#include "sched_server/sched_client.hpp"
#include "sched_server/time_profiling_spinner.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "twist_gate");
  ros::NodeHandle nh;
  ros::NodeHandle private_nh("~");

  TwistGate twist_gate(nh, private_nh);

  //ros::spin();
  //const int pure_pursuit_default_freq=30;
  const int lattice_twist_convert_freq=10;
  SchedClient::ConfigureSchedOfCallingThread();
  TimeProfilingSpinner spinner(DEFAULT_CALLBACK_FREQ_HZ,
		        false);
  spinner.spinAndProfileUntilShutdown();
  spinner.saveProfilingData();
  return 0;
}
