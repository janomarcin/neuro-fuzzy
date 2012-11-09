/*******************************************************************************************************/
/* File:         TouchSensor.cpp                                                                       */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/TouchSensor.hpp>
#include <webots/touch_sensor.h>

using namespace webots;

void TouchSensor::enable(int ms){
  wb_touch_sensor_enable(getTag(),ms);
}

void TouchSensor::disable(){
  wb_touch_sensor_disable(getTag());
}

double TouchSensor::getValue() const {
  return wb_touch_sensor_get_value(getTag());
}

const double *TouchSensor::getValues() const {
  return wb_touch_sensor_get_values(getTag());
}
