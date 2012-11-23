#include "EvolutionaryAlgorithm.h"
#include <iostream>  // I/O 
#include <fstream>   // file I/O
#include <iomanip>   // format manipulation
#include <string>
#include <sstream>

const int tournament = 2;
//const int crossingProbability = 1

EvolutionaryAlgorithm::EvolutionaryAlgorithm(int length,int numberOfIndividuums)
{
	individuumLength = length;
	this->numberOfIndividuums = numberOfIndividuums;
	//initialization population
	for (int i = 0; i < numberOfIndividuums; i++){
		population.push_back(new Individuum(length));
	}
}

void EvolutionaryAlgorithm::crossing()
{
    //uniform crossing
    int i,k,mask[individum_content],sel1,sel2;
    
    //crossing
    for(i=number_of_individum;i<number_of_working_individum;i=i+2){
        if(((double)rand()/(double)RAND_MAX) < crossing_probability){
            //generating mask
            for(k=0;k<individum_content;k++){
                mask[k] = rand() % 2;
            }
            sel1 = selection(1); //selection only from parents part
            sel2 = selection(1); //selection only from parents part
            
            for(k=0;k<individum_content;k++){
                if(mask[k] == 1){
                    //gens from 1. individum
                    population[i][k] = population[sel1][k];
                }
                else{
                    //gens from 2. individum
                    population[i][k] = population[sel2][k];
                }
            }
        }
    }
} 

int EvolutionaryAlgorithm::selection(){ //vrati index jedinca

	//selection of max fitness individuum

	int winner,vector<int> selParents;
	selParents.resize(tournament);
    
    for(int i = 0; i < tournament; i++){
            selParents[i]= rand() % numberOfIndividuums;           
    }

    winner = selParents[0];
    for(int i = 1; i < tournament; i++){
		if(population[winner]->getFitness() > population[selParents[i]]->getFitness())
            winner = selParents[i];
    }
    return winner; 
}


void EvolutionaryAlgorithm::initPopulation()
{
	vector<double> jedinec;
	jedinec.resize(individuumLength);

	for(int i = 0; i < numberOfIndividuums; i++){

		for(int j = 0; j < individuumLength; j++){
			jedinec[j] = rand();
		}

		population[i]->setIndividuum(jedinec);
	}
}



EvolutionaryAlgorithm::~EvolutionaryAlgorithm(void)
{
}