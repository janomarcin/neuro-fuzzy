/*******************************************************************************************************/
/* File:         LightSensor.cpp                                                                       */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/LightSensor.hpp>
#include <webots/light_sensor.h>

using namespace webots;

void LightSensor::enable(int ms){
  wb_light_sensor_enable(getTag(),ms);
}

void LightSensor::disable(){
  wb_light_sensor_disable(getTag());
}

double LightSensor::getValue() const {
  return wb_light_sensor_get_value(getTag());
}

