/*******************************************************************************************************/
/* File:         LED.cpp                                                                               */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/LED.hpp>
#include <webots/led.h>

using namespace webots;

void LED::set(int value){
  wb_led_set(getTag(),value);
}
