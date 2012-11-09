/*******************************************************************************************************/
/* File:         Emitter.cpp                                                                           */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Emitter.hpp>
#include <webots/emitter.h>

using namespace webots;

int Emitter::send(const void *data, int size){
  return wb_emitter_send(getTag(), data, size);
}

int Emitter::getBufferSize() const {
  return wb_emitter_get_buffer_size(getTag());
}

void Emitter::setChannel(int channel) {
  wb_emitter_set_channel(getTag(), channel);
}

int Emitter::getChannel() const {
  return wb_emitter_get_channel(getTag());
}

double Emitter::getRange() const {
  return wb_emitter_get_range(getTag());
}

void Emitter::setRange(double range) {
  wb_emitter_set_range(getTag(), range);
}
