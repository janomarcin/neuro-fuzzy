#pragma once
#include <webots/Supervisor.hpp>
#include <webots/Robot.hpp>
#include <webots/LED.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Node.hpp>
#include <webots/Field.hpp>

#include <iostream>
#include <fstream>
#include <vector>

#include "RobotIO.h"
#include "Anfis.h"

class MyRobot : webots::Supervisor
{
private:
	int numberOfInputs;
	int numberOfLingvisticVariables;
	std::vector<std::vector<int> > rules;
	std::vector<std::vector<double> > Vrules1;
	std::vector<std::vector<double> > Vrules2;

	RobotIO robotIO;
	webots::Node *rootNode;
	webots::Node *robotNode;
	webots::Field *field;

	std::vector<std::string> fileData;
	static const int STEP = 25;
	Anfis* anfis;


public:
	MyRobot();
	virtual ~MyRobot();

public:
	void run();
	void loadFileData();
};

