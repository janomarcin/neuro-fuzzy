/*******************************************************************************************************/
/* File:         GPS.cpp                                                                               */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/GPS.hpp>
#include <webots/gps.h>

using namespace webots;

void GPS::enable(int ms){
  wb_gps_enable(getTag(),ms);
}

void GPS::disable(){
  wb_gps_disable(getTag());
}

const double *GPS::getValues() const {
  return wb_gps_get_values(getTag());
}
