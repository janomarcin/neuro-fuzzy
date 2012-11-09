#include "RobotIO.h"

RobotIO::RobotIO(void) : Robot ()
{
	for(int i = 0; i < 8; i++)
	{
		std::ostringstream numberToString;
		numberToString << i;
		std::string sensorNumber = numberToString.str();
		std::string sensor = "ps";
		sensorNames.push_back(std::string(sensor + sensorNumber));
	}
		sensorData.resize(8); 
}


RobotIO::~RobotIO(void)
{
}

std::vector<double> RobotIO::getSensorData()
{
	for(int i = 0; i < 8; i++)
	{
		distanceSensor = Robot::getDistanceSensor(sensorNames[i]);
		distanceSensor->enable(STEP);
		sensorData[i] = distanceSensor->getValue();
	}
	return sensorData;
}

void RobotIO::setSpeed(double value)
{
	differentialWheels.setSpeed(value, value);
}

std::ostream& operator<<(std::ostream &os, RobotIO &robot)
{
	robot.getSensorData();
	for(int i = 0; i < 8; i++)
	{
		os << robot.sensorData[i] << std::endl;
	}
	return os;
}