#include "EvolutionaryAlgorithm.h"
#include <iostream>  // I/O 
#include <fstream>   // file I/O
#include <iomanip>   // format manipulation
#include <string>
#include <sstream>

const int numberOfIndividuums = 10;

EvolutionaryAlgorithm::EvolutionaryAlgorithm(void)
{
	if(loadAnfisStructure() != -1){
		initPopulation();

	}
}

void EvolutionaryAlgorithm::initPopulation()
{
	population.resize(numberOfIndividuums);
	for(int i = 0; i < numberOfIndividuums; i++)
	{
		population[i].resize(genotypeLength);
		for(int j = 0; j < genotypeLength; j++)
		{
			population[i][j] = rand() % 3500;
		}
	}
}

int EvolutionaryAlgorithm::loadAnfisStructure()
{
	std::ifstream file_in("controller.config");
	if(!file_in)
	{
		std::cout << "Cannot open file controller.config" << std::endl;
		return -1;
	}
	anfis.resize(2);
	file_in >> anfis[0];
	file_in >> anfis[1];
	genotypeLength = anfis[0]*anfis[1]+anfis[0]*anfis[0]+1;
	fitnessPosition = genotypeLength-1;
	/*std::cout << anfis[0]<< std::endl;	
	std::cout << anfis[1]<< std::endl;	*/
	return 0;
}

EvolutionaryAlgorithm::~EvolutionaryAlgorithm(void)
{
}