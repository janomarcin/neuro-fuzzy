#include "MyRobot.h"

int main(int argc, char **argv)
{
  MyRobot* controller = new MyRobot();
  controller->run();
  delete controller;
  return 0;
}
