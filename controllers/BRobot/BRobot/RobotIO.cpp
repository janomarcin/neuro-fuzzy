#include "RobotIO.h"

RobotIO::RobotIO(void) : Robot ()
{
	wheel[0] = Robot::getServo("wheel1");
	wheel[1] = Robot::getServo("wheel2");
	wheel[2] = Robot::getServo("wheel3");
	wheel[3] = Robot::getServo("wheel4");
}


RobotIO::~RobotIO(void)
{
}

void RobotIO::getSensorData(std::vector<double> &sensorData)
{

}

void RobotIO::setSpeed(double value)
{
	wheel[0]->setPosition(9999999999999999999999999999999.0);
	wheel[0]->setVelocity(1.5);
	wheel[1]->setPosition(9999999999999999999999999999999.0);
	wheel[1]->setVelocity(1.5);
	wheel[2]->setPosition(9999999999999999999999999999999.0);
	wheel[2]->setVelocity(1.5);
	wheel[3]->setPosition(9999999999999999999999999999999.0);
	wheel[3]->setVelocity(1.5);
}
