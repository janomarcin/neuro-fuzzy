#include "SupervisorController.h"

using namespace std;

SupervisorController::SupervisorController(int length, int numberOfIndividuums)
{
	this->individuumLength = length;
	this->numberOfIndividuums = numberOfIndividuums;
}

void SupervisorController::init(double trans[], double rot[]){
	init_rot.resize(4);
	init_trans.resize(3);
	for(int i = 0; i < init_rot.size(); i++)
		init_rot[i] = rot[i];
	for(int i = 0; i < init_trans.size(); i++){
		init_trans[i] = trans[i];
		
	}
}

void SupervisorController::run(vector<Individuum*> &population){
	// for reading or setting the robot's position and orientation
	population[0];
	static WbFieldRef robot_translation;
	static WbFieldRef robot_rotation;
	const double INITIAL_TRANS[3] = {init_trans[0], init_trans[1], init_trans[2]};
	const double INITIAL_ROT[4] = {init_rot[0], init_rot[1], init_rot[2], init_rot[3]};
	// robot init
	wb_robot_init();
	// get time_step
	time_step = wb_robot_get_basic_time_step();
	// the emitter to send genotype to robot
    WbDeviceTag emitter = wb_robot_get_device("emitter");
	// find robot node and get robot translation + robot rotation
	WbNodeRef robot_node = wb_supervisor_node_get_from_def("MY_ROBOT");
	WbFieldRef robot_translation = wb_supervisor_node_get_field(robot_node, "translation");
	WbFieldRef robot_rotation = wb_supervisor_node_get_field(robot_node, "rotation");
	// run behaviors
	for (int i = 0; i < numberOfIndividuums; i++) {
		// send genotype to robot for evaluation
		//wb_emitter_send(emitter, genotype, individuumLength * sizeof(double));
		// reset robot to initial position
		wb_supervisor_field_set_sf_vec3f(robot_translation, INITIAL_TRANS);
		wb_supervisor_field_set_sf_rotation(robot_rotation, INITIAL_ROT);
		
		run_seconds(10);
		printf("individuum: %d\n", i);
	}
}

void SupervisorController::run_seconds(double seconds){
	int i, n = 1000.0 * seconds / time_step;
	for (i = 0; i < n; i++) { 
		wb_robot_step(time_step);
	}
}