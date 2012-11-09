/*******************************************************************************************************/
/* File:         Robot.cpp                                                                             */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Robot.hpp>
#include <webots/Device.hpp>
#include <webots/robot.h>

using namespace std;
using namespace webots;

Robot::Robot(){
  wb_robot_init();
}

Robot::~Robot(){
  map<const string,Device *>::iterator it;
  for (it=deviceList.begin(); it!=deviceList.end(); it++ )
    delete (*it).second;
  deviceList.clear();
  wb_robot_cleanup();
}

int Robot::step(int ms){
  return wb_robot_step(ms);
}

string Robot::getName() const {
  return string(wb_robot_get_name());
}

double Robot::getTime() const {
  return wb_robot_get_time();
}

int Robot::getMode() const {
  return wb_robot_get_mode();
}

int Robot::getLicense() const {
  return wb_robot_get_license();
}

bool Robot::getSynchronization() const {
  return wb_robot_get_synchronization();
}

string Robot::getProjectPath() const {
  return string(wb_robot_get_project_path());
}

double Robot::getBasicTimeStep() const {
  return wb_robot_get_basic_time_step();
}

void Robot::batterySensorEnable(int ms){
  wb_robot_battery_sensor_enable(ms);
}
 
void Robot::batterySensorDisable(){
  wb_robot_battery_sensor_disable();
}
 
double Robot::batterySensorGetValue(){
  return wb_robot_battery_sensor_get_value();
}
 
void Robot::keyboardEnable(int ms){
  wb_robot_keyboard_enable(ms);
}
 
void Robot::keyboardDisable(){
  wb_robot_keyboard_disable();
}
 
int Robot::keyboardGetKey(){
  return wb_robot_keyboard_get_key();
}

Accelerometer* Robot::getAccelerometer(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<Accelerometer*>(device);

  if (! Device::exists(name))
    return NULL;

  Accelerometer *accelerometer = createAccelerometer(name);
  insertDevice(accelerometer);
  return accelerometer;
}

Accelerometer *Robot::createAccelerometer(const string &name) const {
  return new Accelerometer(name);
}

Camera *Robot::getCamera(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<Camera*>(device);

  if (! Device::exists(name))
    return NULL;

  Camera *camera = createCamera(name);
  insertDevice(camera);
  return camera;
}

Camera* Robot::createCamera(const string &name) const {
  return new Camera(name);
}

Compass *Robot::getCompass(const string &name) {
  Device *device = getDevice(name);
  if (device!=NULL)
    return dynamic_cast<Compass*>(device);

  if (! Device::exists(name))
    return NULL;

  Compass *compass = createCompass(name);
  insertDevice(compass);
  return compass;
}

Compass *Robot::createCompass(const string &name) const {
  return new Compass(name);
}

Connector *Robot::getConnector(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<Connector*>(device);

  if (! Device::exists(name))
    return NULL;

  Connector *connector = createConnector(name);
  insertDevice(connector);
  return connector;
}

Connector *Robot::createConnector(const string &name) const {
  return new Connector(name);
}

Display *Robot::getDisplay(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<Display*>(device);

  if (! Device::exists(name))
    return NULL;

  Display *display = createDisplay(name);
  insertDevice(display);
  return display;
}

Display *Robot::createDisplay(const string &name) const {
  return new Display(name);
}

DistanceSensor *Robot::getDistanceSensor(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<DistanceSensor*>(device);

  if (! Device::exists(name))
    return NULL;

  DistanceSensor *distanceSensor = createDistanceSensor(name);
  insertDevice(distanceSensor);
  return distanceSensor;
}

DistanceSensor* Robot::createDistanceSensor(const string &name) const {
  return new DistanceSensor(name);
}

Emitter *Robot::getEmitter(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<Emitter*>(device);

  if (! Device::exists(name))
    return NULL;

  Emitter *emitter = createEmitter(name);
  insertDevice(emitter);
  return emitter;
}

Emitter *Robot::createEmitter(const string &name) const {
  return new Emitter(name);
}

GPS *Robot::getGPS(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<GPS*>(device);

  if (! Device::exists(name))
    return NULL;

  GPS *gps = createGPS(name);
  insertDevice(gps);
  return gps;
}

GPS *Robot::createGPS(const string &name) const {
  return new GPS(name);
}

Gyro *Robot::getGyro(const string &name) {
  Device* device = getDevice(name);
  if (device)
    return dynamic_cast<Gyro*>(device);

  if (! Device::exists(name))
    return NULL;

  Gyro *gyro = createGyro(name);
  insertDevice(gyro);
  return gyro;
}

Gyro *Robot::createGyro(const string &name) const {
  return new Gyro(name);
}

LED *Robot::getLED(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<LED*>(device);

  if (! Device::exists(name))
    return NULL;

  LED *led = createLED(name);
  insertDevice(led);
  return led;
}

LED *Robot::createLED(const string &name) const {
  return new LED(name);
}

LightSensor *Robot::getLightSensor(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<LightSensor*>(device);

  if (! Device::exists(name))
    return NULL;

  LightSensor *lightSensor = createLightSensor(name);
  insertDevice(lightSensor);
  return lightSensor;
}

LightSensor *Robot::createLightSensor(const string &name) const {
  return new LightSensor(name);
}

Pen *Robot::getPen(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<Pen*>(device);

  if (! Device::exists(name))
    return NULL;

  Pen *pen = createPen(name);
  insertDevice(pen);
  return pen;
}

Pen *Robot::createPen(const string &name) const {
  return new Pen(name);
}

Receiver *Robot::getReceiver(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<Receiver*>(device);

  if (! Device::exists(name))
    return NULL;

  Receiver *receiver = createReceiver(name);
  insertDevice(receiver);
  return receiver;
}

Receiver *Robot::createReceiver(const string &name) const {
  return new Receiver(name);
}

Servo *Robot::getServo(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<Servo*>(device);

  if (! Device::exists(name))
    return NULL;

  Servo *servo = createServo(name);
  insertDevice(servo);
  return servo;
}

Servo* Robot::createServo(const string &name) const {
  return new Servo(name);
}

TouchSensor *Robot::getTouchSensor(const string &name) {
  Device *device = getDevice(name);
  if (device)
    return dynamic_cast<TouchSensor*>(device);

  if (! Device::exists(name))
    return NULL;

  TouchSensor *touchSensor = createTouchSensor(name);
  insertDevice(touchSensor);
  return touchSensor;
}

TouchSensor *Robot::createTouchSensor(const string &name) const {
  return new TouchSensor(name);
}

Device *Robot::getDevice(const string &name){
  map<const string,Device*>::iterator it = deviceList.find(name);
  if (it==deviceList.end()) return NULL;
  return it->second;
}

void Robot::insertDevice(Device* device){
  deviceList.insert( pair<const string,Device*>(device->getName(),device) );
}
