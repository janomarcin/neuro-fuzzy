/*******************************************************************************************************/
/* File:         Display.cpp                                                                           */
/* Date:         February 09                                                                           */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/Display.hpp>
#include <webots/display.h>

using namespace std;
using namespace webots;

int Display::getWidth() const {
  return wb_display_get_width(getTag());
}

int Display::getHeight() const {
  return wb_display_get_height(getTag());
}

void Display::setColor(int color) {
  wb_display_set_color(getTag(),color);
}

void Display::setAlpha(double alpha) {
  wb_display_set_alpha(getTag(),alpha);  
}

void Display::setOpacity(double opacity) {
  wb_display_set_opacity(getTag(),opacity);  
}

void Display::drawPixel(int x,int y) {
  wb_display_draw_pixel(getTag(),x,y);
}

void Display::drawLine(int x1,int y1,int x2,int y2) {
  wb_display_draw_line(getTag(),x1,y1,x2,y2);
}

void Display::drawRectangle(int x,int y,int width,int height) {
  wb_display_draw_rectangle(getTag(),x,y,width,height);  
}

void Display::drawOval(int cx,int cy,int a,int b) {
  wb_display_draw_oval(getTag(),cx,cy,a,b);
}

void Display::drawPolygon(const int *x,const int* y,int size) {
  wb_display_draw_polygon(getTag(),x,y,size);
}

void Display::drawText(const std::string &txt,int x,int y) {
  wb_display_draw_text(getTag(),txt.c_str(),x,y);
}

void Display::fillRectangle(int x,int y,int width,int height) {
  wb_display_fill_rectangle(getTag(),x,y,width,height);  
}

void Display::fillOval(int cx,int cy,int a,int b) {
  wb_display_fill_oval(getTag(),cx,cy,a,b);
}

void Display::fillPolygon(const int *x,const int* y,int size) {
  wb_display_fill_polygon(getTag(),x,y,size);
}

ImageRef *Display::imageCopy(int x,int y,int width,int height) const {
  return new ImageRef(getTag(),wb_display_image_copy(getTag(),x,y,width,height));
}

ImageRef *Display::imageNew(int width,int height,const void *data,int format) const {
  return new ImageRef(getTag(),wb_display_image_new(getTag(),width,height,data,format));
}

void Display::imagePaste(ImageRef *ir,int x,int y) {
  wb_display_image_paste(getTag(),ir->getImageRef(),x,y);
}

ImageRef *Display::imageLoad(const std::string &filename) const {
  return new ImageRef(getTag(),wb_display_image_load(getTag(),filename.c_str()));  
}

void Display::imageSave(ImageRef *ir,const std::string &filename) const {
  wb_display_image_save(getTag(),ir->getImageRef(),filename.c_str());  
}

void Display::imageDelete(ImageRef *ir) const {
  wb_display_image_delete(getTag(),ir->getImageRef());
  delete ir;
  ir = 0;
}
