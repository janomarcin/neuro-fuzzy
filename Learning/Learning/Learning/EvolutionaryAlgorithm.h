#pragma once
#include<stdio.h>
#include<vector>

using namespace std;
class EvolutionaryAlgorithm
{
public:
	EvolutionaryAlgorithm(void);
	~EvolutionaryAlgorithm(void);

	int loadAnfisStructure(); //from file
	void initPopulation(); //random init

	void loadFitness(); //from File
	
	double getFitness(); //from file
	void selection();
	void crossing();
	void mutation();
	void substitution(); 
	void saveResultsToFile();

private:
	double fitness;
	int genotypeLength;
	int fitnessPosition;
	vector<vector<double>> population;
	vector<double> anfis; //0 - number of inputs, 1 - number of MF per input
};

