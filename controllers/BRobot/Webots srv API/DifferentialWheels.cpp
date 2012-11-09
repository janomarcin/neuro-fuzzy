/*******************************************************************************************************/
/* File:         DifferentialWheels.cpp                                                                */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/differential_wheels.h>
#include <webots/DifferentialWheels.hpp>

using namespace webots;

void DifferentialWheels::setSpeed(double left, double right){
  wb_differential_wheels_set_speed(left, right);
}

void DifferentialWheels::enableEncoders(int ms){
  wb_differential_wheels_enable_encoders(ms);
}

void DifferentialWheels::disableEncoders(){
  wb_differential_wheels_disable_encoders();
}

double DifferentialWheels::getLeftEncoder() const {
  return wb_differential_wheels_get_left_encoder();
}

double DifferentialWheels::getRightEncoder() const {
  return wb_differential_wheels_get_right_encoder();
}

void DifferentialWheels::setEncoders(double left,double right){
  wb_differential_wheels_set_encoders(left, right);
}
