#include "MyRobot.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	MyRobot controller;
	controller.loadFileData("anfis.config.txt");
	controller.run();

	return 0;
}
