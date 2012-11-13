#pragma once
#include <webots/Robot.hpp>
#include <webots/LED.hpp>
#include <webots/DistanceSensor.hpp>

#include <iostream>
#include <fstream>

#include "RobotIO.h"

class MyRobot : webots::Robot
{
private:
	int numberOfInputs;
	int numberOfLingvisticVariables;
	std::vector<std::vector<int>> rules;

	RobotIO robotIO;
	std::vector<std::string> fileData;
	static const int STEP = 32;
public:
	MyRobot();
	virtual ~MyRobot();
	void loadFileData(std::string fileName);

public:
	void run(); 

	friend std::istream& operator>>(std::istream &subor, MyRobot &robot); 
};

