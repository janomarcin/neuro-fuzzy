#pragma once
#include <webots/Robot.hpp>
#include <webots/LED.hpp>
#include <webots/DistanceSensor.hpp>

#include <iostream>
#include <fstream>
#include <vector>

#include "RobotIO.h"

class MyRobot : webots::Robot
{
private:
	int numberOfInputs;
	int numberOfLingvisticVariables;
	std::vector<std::vector<int> > rules;
	std::vector<std::vector<double> > Vrules1;
	std::vector<std::vector<double> > Vrules2;

	RobotIO robotIO;
	std::vector<std::string> fileData;
	static const int STEP = 32;

public:
	MyRobot();
	virtual ~MyRobot();

public:
	void run();
	void loadFileData();
};

