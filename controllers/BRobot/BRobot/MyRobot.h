#pragma once
#include <webots/Supervisor.hpp>
#include <webots/Robot.hpp>
#include <webots/LED.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Node.hpp>
#include <webots/Field.hpp>

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "RobotIO.h"
#include "Anfis.h"
#include "EvolutionaryAlgorithm.h"

class MyRobot : webots::Supervisor
{
private:
	static const int pocetJedincov = 50;
	int numberOfInputs;
	int numberOfLingvisticVariables;
	EvolutionaryAlgorithm *evolutionaryAlgorithm;
	std::vector<std::vector<int> > rules;
	std::vector<std::vector<double> > Vrules1;
	std::vector<std::vector<double> > Vrules2;
	std::vector<std::vector<std::vector<double> > > mfparameter;
	std::vector<std::vector<double > > adaptation;
	vector<double> input;
	double speed;
	double side;

	RobotIO robotIO;
	webots::Node *rootNode;
	webots::Node *robotNode;
	webots::Field *field;
	webots::Field *rotation;

	std::vector<std::string> fileData;
	static const int STEP = 1000;
	Anfis* anfis;


public:
	MyRobot();
	virtual ~MyRobot();

public:
	void run();
	void loadFileData();
	void getFitness();
	void evaluateIndividuum(int index);
};

