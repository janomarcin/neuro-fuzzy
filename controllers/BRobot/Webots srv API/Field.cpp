/*******************************************************************************************************/
/* File:         Field.cpp                                                                             */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/supervisor.h>
#include <webots/Field.hpp>
#include <map>

using namespace std;
using namespace webots;

static map<WbFieldRef,Field*> fieldMap;

Field *Field::findField(WbFieldRef ref) {

  if (! ref)
    return NULL;

  map<WbFieldRef,Field*>::iterator iter = fieldMap.find(ref);
  if (iter != fieldMap.end())
    return iter->second;

  Field *field = new Field(ref);
  fieldMap.insert(pair<WbFieldRef,Field*>(ref, field));
  return field;
}

void Field::cleanup() {
  map<WbFieldRef,Field*>::iterator iter;
  for (iter = fieldMap.begin(); iter != fieldMap.end(); iter++)
    delete (*iter).second;

  fieldMap.clear();
}

Field::Field(WbFieldRef ref) {
  fieldRef = ref;
}

int Field::getType() const {
  return wb_supervisor_field_get_type(fieldRef);
}

std::string Field::getTypeName() const {
  return string(wb_supervisor_field_get_type_name(fieldRef));
}

int Field::getCount() const {
  return wb_supervisor_field_get_count(fieldRef);
}

bool Field::getSFBool() const {
  return wb_supervisor_field_get_sf_bool(fieldRef);
}

int Field::getSFInt32() const {
  return wb_supervisor_field_get_sf_int32(fieldRef);
}

double Field::getSFFloat() const {
  return wb_supervisor_field_get_sf_float(fieldRef);
}

const double *Field::getSFVec2f() const {
  return wb_supervisor_field_get_sf_vec2f(fieldRef);
}

const double *Field::getSFVec3f() const {
  return wb_supervisor_field_get_sf_vec3f(fieldRef);
}

const double *Field::getSFRotation() const {
  return wb_supervisor_field_get_sf_rotation(fieldRef);
}

const double *Field::getSFColor() const {
  return wb_supervisor_field_get_sf_color(fieldRef);
}

string Field::getSFString() const {
  return string(wb_supervisor_field_get_sf_string(fieldRef));
}

Node *Field::getSFNode() const {
  WbNodeRef nodeRef = wb_supervisor_field_get_sf_node(fieldRef);
  return Node::findNode(nodeRef);
}

int Field::getMFInt32(int index) const {
  return wb_supervisor_field_get_mf_int32(fieldRef,index);
}

double Field::getMFFloat(int index) const {
  return wb_supervisor_field_get_mf_float(fieldRef,index);
}

const double *Field::getMFVec2f(int index) const {
  return wb_supervisor_field_get_mf_vec2f(fieldRef,index);
}

const double *Field::getMFVec3f(int index) const {
  return wb_supervisor_field_get_mf_vec3f(fieldRef,index);
}

const double *Field::getMFColor(int index) const {
  return wb_supervisor_field_get_mf_color(fieldRef,index);
}

string Field::getMFString(int index) const {
  return string(wb_supervisor_field_get_mf_string(fieldRef,index));
}

Node *Field::getMFNode(int index) const {
  WbNodeRef nodeRef = wb_supervisor_field_get_mf_node(fieldRef,index);
  return Node::findNode(nodeRef);
}

void Field::setSFBool(bool value) {
  wb_supervisor_field_set_sf_bool(fieldRef, value);
}

void Field::setSFInt32(int value) {
  wb_supervisor_field_set_sf_int32(fieldRef, value);
}

void Field::setSFFloat(double value) {
  wb_supervisor_field_set_sf_float(fieldRef, value);
}

void Field::setSFVec2f(const double *values) {
  wb_supervisor_field_set_sf_vec2f(fieldRef, values);
}

void Field::setSFVec3f(const double *values) {
  wb_supervisor_field_set_sf_vec3f(fieldRef, values);
}

void Field::setSFRotation(const double *values) {
  wb_supervisor_field_set_sf_rotation(fieldRef, values);
}

void Field::setSFColor(const double *values) {
  wb_supervisor_field_set_sf_color(fieldRef, values);
}

void Field::setSFString(const string &value) {
  wb_supervisor_field_set_sf_string(fieldRef, value.c_str());
}

void Field::setMFInt32(int index, int value) {
  wb_supervisor_field_set_mf_int32(fieldRef, index, value);
}

void Field::setMFFloat(int index, double value) {
  wb_supervisor_field_set_mf_float(fieldRef, index, value);
}

void Field::setMFVec2f(int index, const double *values) {
  wb_supervisor_field_set_mf_vec2f(fieldRef, index, values);
}

void Field::setMFVec3f(int index, const double *values) {
  wb_supervisor_field_set_mf_vec3f(fieldRef, index, values);
}

void Field::setMFColor(int index, const double *values) {
  wb_supervisor_field_set_mf_color(fieldRef, index, values);
}

void Field::setMFString(int index, const string &value) {
  wb_supervisor_field_set_mf_string(fieldRef, index, value.c_str());
}

void Field::importMFNode(int position, const std::string &filename){
  wb_supervisor_field_import_mf_node(fieldRef, position, filename.c_str());
}
