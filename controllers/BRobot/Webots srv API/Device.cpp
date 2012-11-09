/*******************************************************************************************************/
/* File:         Device.cpp                                                                            */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Device.hpp>
#include <webots/robot.h>

using namespace std;
using namespace webots;

Device::Device(const string &deviceName) : name(deviceName) {
  tag = wb_robot_get_device(name.c_str());
}

bool Device::exists(const std::string &name) {
  return wb_robot_get_device(name.c_str()) != 0;
}
