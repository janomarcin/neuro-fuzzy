/*******************************************************************************************************/
/* File:         Compass.cpp                                                                           */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Compass.hpp>
#include <webots/compass.h>

using namespace webots;

void Compass::enable(int ms) {
  wb_compass_enable(getTag(),ms);
}

void Compass::disable() {
  wb_compass_disable(getTag());
}

const double *Compass::getValues() const {
  return wb_compass_get_values(getTag());
}
