
#include <iostream>
#include <fstream>
#include "EvolutionaryAlgorithm.h"

int main(int argc, char **argv)
{
	printf("Testing text");
	EvolutionaryAlgorithm* evolution = new EvolutionaryAlgorithm(8,10);
	evolution->initPopulation();
	//evolution->crossing();
	//evolution->mutation();
	evolution->substitution();
	system("pause");
	

	return 0;
}

// vyuzitelne f-cie
/*
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
	std::cout << anfis[0]<< std::endl;	
	std::cout << anfis[1]<< std::endl;	
	return 0;


		population[0]->setFitness(5.86);
	population[1]->setFitness(5.885);
	population[2]->setFitness(5.812);
	population[3]->setFitness(5.89);
	population[4]->setFitness(5.252);

	std::cout << population[0]->getFitness() << std::endl;
	std::cout << population[1]->getFitness() << std::endl;
	std::cout << population[2]->getFitness() << std::endl;
	std::cout << population[3]->getFitness() << std::endl;
	std::cout << population[4]->getFitness() << std::endl;
}
*/