#pragma once
#include <webots/Robot.hpp>
#include <webots/LED.hpp>
#include <webots/DistanceSensor.hpp>

#include <iostream>

#include "RobotIO.h"

class MyRobot : webots::Robot
{
private:
	RobotIO robotIO;
	double fileData;
	std::vector<double> fileDatas;
	static const int STEP = 32;
public:
	MyRobot();
	virtual ~MyRobot();

public:
	void run(); 

	friend std::istream& operator>>(std::istream &subor, MyRobot &robot); 
};

