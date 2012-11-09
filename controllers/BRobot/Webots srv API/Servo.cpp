/*******************************************************************************************************/
/* File:         Servo.cpp                                                                             */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Servo.hpp>
#include <webots/servo.h>

using namespace webots;

void Servo::setAcceleration(double force){
  wb_servo_set_acceleration(getTag(),force);
}

void Servo::setVelocity(double vel){
  wb_servo_set_velocity(getTag(),vel);
}

void Servo::enablePosition(int ms){
  wb_servo_enable_position(getTag(),ms);
}

void Servo::disablePosition(){
  wb_servo_disable_position(getTag());
}

void Servo::setForce(double force){
  wb_servo_set_force(getTag(),force);
}

void Servo::setMotorForce(double motor_force){
  wb_servo_set_motor_force(getTag(),motor_force);
}

void Servo::setControlP(double p){
  wb_servo_set_control_p(getTag(),p);
}

void Servo::enableMotorForceFeedback(int ms){
  wb_servo_enable_motor_force_feedback(getTag(),ms);
}

void Servo::disableMotorForceFeedback(){
  wb_servo_disable_motor_force_feedback(getTag());
}

double Servo::getMotorForceFeedback() const {
  return wb_servo_get_motor_force_feedback(getTag());
}

double Servo::getPosition() const {
  return wb_servo_get_position(getTag());
}

void Servo::setPosition(double position){
  wb_servo_set_position(getTag(),position);
}
