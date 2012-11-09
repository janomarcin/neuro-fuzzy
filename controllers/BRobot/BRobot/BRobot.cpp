#include <webots/Robot.hpp>
#include <webots/LED.hpp>
#include <webots/DistanceSensor.hpp>

#include <iostream>

using namespace webots;

#define TIME_STEP 32

class MyRobot : public Robot 
{
private:
	LED *led;
	DistanceSensor *distanceSensor;

public:
	MyRobot() : Robot() {
		led = getLED("ledName");
		
		distanceSensor = getDistanceSensor("ps1");
		distanceSensor->enable(TIME_STEP);
		}

	virtual ~MyRobot() { }

	void run() 
	{
		while (step(TIME_STEP) != -1) 
		{
			double val = distanceSensor->getValue();
			std::cout << val << std::endl;
		}
	}
};


int main(int argc, char **argv)
{
  MyRobot* controller = new MyRobot();
  controller->run();
  delete controller;
  return 0;
}
