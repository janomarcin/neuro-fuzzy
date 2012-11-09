/*******************************************************************************************************/
/* File:         Accelerometer.cpp                                                                     */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Accelerometer.hpp>
#include <webots/accelerometer.h>

using namespace webots;

void Accelerometer::enable(int ms) {
  wb_accelerometer_enable(getTag(),ms);
}

void Accelerometer::disable() {
  wb_accelerometer_disable(getTag());
}

const double *Accelerometer::getValues() const {
  return wb_accelerometer_get_values(getTag());
}
