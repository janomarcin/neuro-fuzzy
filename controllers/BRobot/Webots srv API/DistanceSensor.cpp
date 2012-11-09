/*******************************************************************************************************/
/* File:         DistanceSensor.cpp                                                                    */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/DistanceSensor.hpp>
#include <webots/distance_sensor.h>

using namespace webots;

void DistanceSensor::enable(int ms){
  wb_distance_sensor_enable(getTag(),ms);
}

void DistanceSensor::disable(){
  wb_distance_sensor_disable(getTag());
}

double DistanceSensor::getValue() const {
  return wb_distance_sensor_get_value(getTag());
}
