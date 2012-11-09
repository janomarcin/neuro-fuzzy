/*******************************************************************************************************/
/* File:         Node.cpp                                                                              */
/* Date:         May 08                                                                                */
/* Description:  C++ file for the OO interface                                                         */
/* Author:       fabien.rohrer@cyberbotics.com                                                         */
/* Copyright (c) 2008 Cyberbotics - www.cyberbotics.com                                                */
/*******************************************************************************************************/

#define WB_ALLOW_MIXING_C_AND_CPP_API
#include <webots/supervisor.h>
#include <webots/Node.hpp>
#include <iostream>
#include <map>

using namespace std;
using namespace webots;

static map<WbNodeRef,Node*> nodeMap;

Node *Node::findNode(WbNodeRef ref) {

  if (! ref)
    return NULL;

  map<WbNodeRef,Node*>::iterator iter = nodeMap.find(ref);
  if (iter != nodeMap.end())
    return iter->second;

  Node *node = new Node(ref);
  nodeMap.insert(pair<WbNodeRef,Node*>(ref, node));
  return node;
}

void Node::cleanup() {
  map<WbNodeRef,Node*>::iterator iter;
  for (iter = nodeMap.begin(); iter != nodeMap.end(); iter++)
    delete (*iter).second;

  nodeMap.clear();
}

Node::Node(WbNodeRef ref) {
  nodeRef = ref;
}

int Node::getType() const {
  return wb_supervisor_node_get_type(nodeRef);
}

// deprecated function: should be removed some day
std::string Node::getName() const {
  cerr << "The function Node::getName() is deprecated: please use Node::getTypeName() instead.\n";
  return string(wb_supervisor_node_get_type_name(nodeRef));
}

std::string Node::getTypeName() const {
  return string(wb_supervisor_node_get_type_name(nodeRef));
}

Field *Node::getField(const std::string &fieldName) const {
  WbFieldRef fieldRef = wb_supervisor_node_get_field(nodeRef, fieldName.c_str());
  return Field::findField(fieldRef);
}

const double *Node::getPosition() const {
  return wb_supervisor_node_get_position(nodeRef);
}

const double *Node::getOrientation() const {
  return wb_supervisor_node_get_orientation(nodeRef);
}
