#include "MyRobot.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	MyRobot controller;
	controller.loadFileData();
	controller.run();

	return 0;
}
