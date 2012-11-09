/*******************************************************************************************************/
/* File:         Connector.cpp                                                                         */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Connector.hpp>
#include <webots/connector.h>

using namespace webots;

void Connector::enablePresence(int ms){
  wb_connector_enable_presence(getTag(),ms);
}

void Connector::disablePresence(){
  wb_connector_disable_presence(getTag());
}

int Connector::getPresence() const {
  return wb_connector_get_presence(getTag());
}

void Connector::lock(){
  wb_connector_lock(getTag());
}

void Connector::unlock(){
  wb_connector_unlock(getTag());
}

