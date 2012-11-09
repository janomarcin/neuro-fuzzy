/*******************************************************************************************************/
/* File:         Camera.cpp                                                                             */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Camera.hpp>
#include <webots/camera.h>
#include <stdio.h>

using namespace std;
using namespace webots;

void Camera::enable(int ms){
  wb_camera_enable(getTag(),ms);
}

void Camera::disable(){
  wb_camera_disable(getTag());
}

const unsigned char *Camera::getImage() const {
  return wb_camera_get_image(getTag());
}

unsigned char Camera::imageGetRed(const unsigned char* image, int width, int x, int y){
  return wb_camera_image_get_red(image,width,x,y);
}

unsigned char Camera::imageGetGreen(const unsigned char* image, int width, int x, int y){
  return wb_camera_image_get_green(image,width,x,y);
}

unsigned char Camera::imageGetBlue(const unsigned char* image, int width, int x, int y){
  return wb_camera_image_get_blue(image,width,x,y);
}

unsigned char Camera::imageGetGrey(const unsigned char* image, int width, int x, int y){
  return wb_camera_image_get_grey(image,width,x,y);
}

const float *Camera::getRangeImage() const {
  return wb_camera_get_range_image(getTag());
}

float Camera::rangeImageGetValue(const float *image, double near, double far, int width, int x, int y){
  fprintf(stderr,"Camera::rangeImageGetValue is deprecated, please use Camera::rangeImageGetDepth instead\n");
  return (float) wb_camera_range_image_get_depth(image,width,x,y);
}

float Camera::rangeImageGetDepth(const float *image, int width, int x, int y){
  return (float) wb_camera_range_image_get_depth(image,width,x,y);
}

int Camera::getWidth() const {
  return wb_camera_get_width(getTag());
}

int Camera::getHeight() const {
  return wb_camera_get_height(getTag());
}

double Camera::getFov() const {
  return wb_camera_get_fov(getTag());
}

void Camera::setFov(double fov){
  wb_camera_set_fov(getTag(),fov);
}

int Camera::getType() const {
  return wb_camera_get_type(getTag());
}

double Camera::getNear() const {
  return wb_camera_get_near(getTag());
}

double Camera::getMaxRange() const {
  return wb_camera_get_max_range(getTag());
}

int Camera::saveImage(const string &filename,int quality) const {
  return wb_camera_save_image(getTag(),filename.c_str(),quality); 
}
