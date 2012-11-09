/*******************************************************************************************************/
/* File:         Supervisor.cpp                                                                        */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/supervisor.h>
#include <webots/Supervisor.hpp>

using namespace std;
using namespace webots;

Supervisor::~Supervisor() {
  Field::cleanup();
  Node::cleanup();
}

void Supervisor::simulationQuit(int status){
  wb_supervisor_simulation_quit(status);
}

void Supervisor::simulationRevert(){
  wb_supervisor_simulation_revert();
}

void Supervisor::simulationPhysicsReset(){
  wb_supervisor_simulation_physics_reset();
}

void Supervisor::exportImage(const string &file, int quality) const {
  wb_supervisor_export_image(file.c_str(), quality);
}

void Supervisor::startMovie(const string &file,int width,int height,int type,int quality) {
  wb_supervisor_start_movie(file.c_str(),width,height,type,quality);
}

void Supervisor::stopMovie() {
  wb_supervisor_stop_movie();
}

void Supervisor::setLabel(int id,const string &label,double xpos,double ypos,double size,int color,double transparency){
  wb_supervisor_set_label(id,label.c_str(),xpos,ypos,size,color,transparency);
}

Node *Supervisor::getRoot() const {
  WbNodeRef nodeRef = wb_supervisor_node_get_root();
  return Node::findNode(nodeRef);
}

Node *Supervisor::getFromDef(const std::string &name) const {
  WbNodeRef nodeRef = wb_supervisor_node_get_from_def(name.c_str());
  return Node::findNode(nodeRef);
}
