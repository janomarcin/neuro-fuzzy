 /*******************************************************************************************************/
/* File:         Motion.cpp                                                                            */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/utils/Motion.hpp>
#include <webots/utils/motion.h>

using namespace std;
using namespace webots;

Motion::~Motion(){
  wbu_motion_delete(motionRef);
}

Motion::Motion(const string &fileName){
  motionRef = wbu_motion_new(fileName.c_str());
}

bool Motion::isValid() const {
  return motionRef ? true : false;
}

void Motion::play() {
  wbu_motion_play(motionRef);
}

void Motion::stop() {
  wbu_motion_stop(motionRef);
}

int Motion::getDuration() const {
  return wbu_motion_get_duration(motionRef);
}

int Motion::getTime() const {
  return wbu_motion_get_time(motionRef);
}

void Motion::setTime(int time){
  wbu_motion_set_time(motionRef,time);  
}

void Motion::setReverse(bool reverse){
  wbu_motion_set_reverse(motionRef,reverse);
}

void Motion::setLoop(bool loop){
  wbu_motion_set_loop(motionRef,loop);
}

bool Motion::isOver() const {
  return wbu_motion_is_over(motionRef);
}
