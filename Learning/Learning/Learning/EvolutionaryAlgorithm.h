#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include "Individuum.h"
#include "CompareIndividuum.h"
#include <iostream>  // I/O 
#include <fstream>   // file I/O
#include <iomanip>   // format manipulation
#include <string>
#include <sstream>
#include <ctime>
#include<algorithm>

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

	bool compareIndividuums(const Individuum * ind1, const Individuum * ind2);
	

};

