/*******************************************************************************************************/
/* File:         Pen.cpp                                                                               */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Pen.hpp>
#include <webots/pen.h>

using namespace webots;

void Pen::write(bool write){
  wb_pen_write(getTag(),write);
}

void Pen::setInkColor(int color,double density){
  wb_pen_set_ink_color(getTag(),color,density); 
}

