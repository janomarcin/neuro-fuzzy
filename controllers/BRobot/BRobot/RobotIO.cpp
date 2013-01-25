#include "RobotIO.h"

RobotIO::RobotIO(void) : Robot ()
{
	wheel[0] = Robot::getServo("wheel1");
	wheel[1] = Robot::getServo("wheel2");
	wheel[2] = Robot::getServo("wheel3");
	wheel[3] = Robot::getServo("wheel4");
	distanceSensor[0] = Robot::getDistanceSensor("sensor1");
	distanceSensor[1] = Robot::getDistanceSensor("sensor2");
	//distanceSensor[2] = Robot::getDistanceSensor("sensor3");
}


RobotIO::~RobotIO(void)
{
}

void RobotIO::getSensorData(std::vector<double> &sensorData)
{
	distanceSensor[0]->enable(STEP);
	distanceSensor[1]->enable(STEP);
	//distanceSensor[2]->enable(STEP);

	for(int i = 0; i < 2; i++)
	{
		sensorData.push_back(distanceSensor[i]->getValue());
	}
}

void RobotIO::setSpeed(double speed, double side)
{
	if(speed > 0)
	{
		wheel[0]->setPosition(9999999999999999999999999999999.0);
		wheel[0]->setVelocity(speed);
		wheel[1]->setPosition(9999999999999999999999999999999.0);
		wheel[1]->setVelocity(speed);
		wheel[2]->setPosition(9999999999999999999999999999999.0);
		wheel[2]->setVelocity(speed);
		wheel[3]->setPosition(9999999999999999999999999999999.0);
		wheel[3]->setVelocity(speed);
	}

	if(int (side) > 0)
	{
		wheel[0]->setPosition(9999999999999999999999999999999.0);
		wheel[0]->setVelocity(side);
		wheel[1]->setPosition(9999999999999999999999999999999.0);
		wheel[1]->setVelocity(side);
		wheel[2]->setPosition(9999999999999999999999999999999.0);
		wheel[2]->setVelocity(0.2);
		wheel[3]->setPosition(9999999999999999999999999999999.0);
		wheel[3]->setVelocity(0.2);
	}

	if(int (side) < 0)
	{
		wheel[0]->setPosition(9999999999999999999999999999999.0);
		wheel[0]->setVelocity(0.2);
		wheel[1]->setPosition(9999999999999999999999999999999.0);
		wheel[1]->setVelocity(0.2);
		wheel[2]->setPosition(9999999999999999999999999999999.0);
		wheel[2]->setVelocity(abs(side));
		wheel[3]->setPosition(9999999999999999999999999999999.0);
		wheel[3]->setVelocity(abs(side));
	}
}
