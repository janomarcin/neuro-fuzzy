#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Servo.hpp>
#include <webots/Device.hpp>

class RobotIO : webots::Robot
{
private:
	static const int STEP = 1000;
	webots::Servo *wheel[4];
	webots::DistanceSensor *distanceSensor[2];

public:
	RobotIO(void);
	~RobotIO(void);

public:
	void getSensorData(std::vector<double> &sensorData);
	void setSpeed(double value, double side);
};

