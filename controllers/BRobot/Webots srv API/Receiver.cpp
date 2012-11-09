/*******************************************************************************************************/
/* File:         Receiver.cpp                                                                          */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Receiver.hpp>
#include <webots/receiver.h>

using namespace webots;

void Receiver::enable(int ms){
  wb_receiver_enable(getTag(), ms);
}

void Receiver::disable(){
  wb_receiver_disable(getTag());
}

void Receiver::setChannel(int channel){
  wb_receiver_set_channel(getTag(), channel);
}

int Receiver::getChannel() const {
  return wb_receiver_get_channel(getTag());
}

int Receiver::getQueueLength() const {
  return wb_receiver_get_queue_length(getTag());
}

void Receiver::nextPacket(){
  wb_receiver_next_packet(getTag());
}

int Receiver::getDataSize() const {
  return wb_receiver_get_data_size(getTag());
}

const void *Receiver::getData() const {
  return wb_receiver_get_data(getTag());
}

double Receiver::getSignalStrength() const {
  return wb_receiver_get_signal_strength(getTag());
}

const double *Receiver::getEmitterDirection() const {
  return wb_receiver_get_emitter_direction(getTag());
}
