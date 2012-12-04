#pragma once
#include <webots/robot.h>
#include <webots/supervisor.h>
#include <webots/emitter.h>
#include "Individuum.h"
#include <string.h>
#include <vector>

using namespace std;

class SupervisorController {
public:
	SupervisorController(int length,int numberOfIndividuums);
	~SupervisorController(void);
	void init(double[], double[]);
	void run(vector<Individuum*> &);

private:
	void run_seconds(double);
	int individuumLength;
	int numberOfIndividuums;
	int time_step;
	vector<double> init_rot;
	vector<double> init_trans;
};