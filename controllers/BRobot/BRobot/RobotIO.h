#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/DifferentialWheels.hpp>
#include <webots/Device.hpp>

class RobotIO : webots::Robot
{
private:
	static const int STEP = 32;
	webots::DistanceSensor *distanceSensor;
	webots::DifferentialWheels differentialWheels;
	std::vector<double> sensorData;
	std::vector<std::string> sensorNames;
public:
	RobotIO(void);
	~RobotIO(void);

public:
	std::vector<double> getSensorData();
	void setSpeed(double value);

	friend std::ostream& operator<<(std::ostream &os, RobotIO &robot);
};

