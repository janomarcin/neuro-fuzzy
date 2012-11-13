#include "MyRobot.h"


MyRobot::MyRobot(void) : Robot()
{
}


MyRobot::~MyRobot(void)
{
}

void MyRobot::run() 
{
	while (step(STEP) != -1) 
	{
		std::cout << "Ahoj " << std::endl << robotIO << std::endl;
	}
}

std::istream& operator>>(std::istream &subor, MyRobot &robot)
{
	while(!subor.eof())
	{
		subor >> robot.fileData;
		robot.fileDatas.push_back(robot.fileData);
	}

	return subor;
}