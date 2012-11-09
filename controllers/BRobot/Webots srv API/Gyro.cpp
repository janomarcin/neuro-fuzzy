/*******************************************************************************************************/
/* File:         Gyro.cpp                                                                              */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Gyro.hpp>
#include <webots/gyro.h>

using namespace webots;

void Gyro::enable(int ms) {
  wb_gyro_enable(getTag(),ms);
}

void Gyro::disable() {
  wb_gyro_disable(getTag());
}

const double *Gyro::getValues() const {
  return wb_gyro_get_values(getTag());
}
