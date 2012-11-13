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
		//std::cout << "Ahoj " << std::endl << robotIO << std::endl;
	}
}

std::istream& operator>>(std::istream &subor, MyRobot &robot)
{
	std::string line;
	while(!subor.eof())
	{
		subor >> line;
		std::cout << line << std::endl;
	}

	return subor;
}

void MyRobot::loadFileData(std::string fileName)
{
	std::string line;
	char lines[20];
	std::ifstream ifs(fileName, std::ifstream::in);

	while(!ifs.eof())
	{
		ifs.getline(lines, 20);
		std::cout << lines << std::endl;
	}
}