#pragma once
#include<stdio.h>
#include<vector>
#include "Individuum.h"

using namespace std;

class EvolutionaryAlgorithm
{
public:
	EvolutionaryAlgorithm(int length,int numberOfIndividuums);
	~EvolutionaryAlgorithm(void);

	void initPopulation(); //random init
	/*virtual*/ void fitness();
	int selection();
	void crossing();
	void mutation();
	void substitution(); 


private:
	
	vector<Individuum *> population;
	int individuumLength;
	int numberOfIndividuums;

};

