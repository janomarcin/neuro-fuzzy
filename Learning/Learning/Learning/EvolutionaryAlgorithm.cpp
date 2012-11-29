#include "EvolutionaryAlgorithm.h"

const int tournament = 2;
const float mutationValue = 0.1;
const float mutationPowerValue = 0.3;

EvolutionaryAlgorithm::EvolutionaryAlgorithm(int length,int numberOfIndividuums)
{
	srand((unsigned)time(NULL)); 
	individuumLength = length;
	this->numberOfIndividuums = numberOfIndividuums;
	//initialization population
	for (int i = 0; i < numberOfIndividuums; i++){
		population.push_back(new Individuum(length));
	}
}

void EvolutionaryAlgorithm::crossing()
{
	vector<double> parent1;
	vector<double> parent2;

	Individuum* descendant1 = new Individuum(population[0]->getLength());
	Individuum* descendant2 = new Individuum(population[0]->getLength());
	vector<double> descendantGenes1;
	vector<double> descendantGenes2;

	
	for(int i = 0; i < (int) numberOfIndividuums/2; i++){

		
		parent1 = population[selection()]->getIndividuum();
		parent2 = population[selection()]->getIndividuum();
		descendantGenes1.resize(parent1.size());
		descendantGenes2.resize(parent2.size());

		for(int j = 0; j < parent1.size(); j++){
			descendantGenes1[j] = 0.5*parent1[j]+0.5*parent2[j];
			descendantGenes2[j] = 1.5*parent1[j]-0.5*parent2[j];
		}
		descendant1->setIndividuum(descendantGenes1);
		descendant2->setIndividuum(descendantGenes2);
		population.push_back(descendant1);
		population.push_back(descendant2);
	}
}

void EvolutionaryAlgorithm::substitution(){

	std::sort(population.begin(),population.end(),CompareIndividuum());
}


void EvolutionaryAlgorithm::mutation(){
	vector<double> values;
	for(int i = numberOfIndividuums; i < population.size(); i++){
		if(((double)rand()/(double)RAND_MAX) < mutationValue){
			values.resize(population[i]->getLength());
			values = population[i]->getIndividuum();

			for(int j = 0; j < population[i]->getLength(); j++){
				if(((double)rand()/(double)RAND_MAX) < mutationPowerValue){
					values[j] = rand(); //new value
				}
			}
			population[i]->setIndividuum(values);
		}
	}
}

int EvolutionaryAlgorithm::selection(){ //vrati index jedinca

	//selection of max fitness individuum

	int winner;
	vector<int> selParents;
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
			jedinec[j] = (double)rand()/(double)RAND_MAX;
		}

		population[i]->setIndividuum(jedinec);
		population[i]->setFitness(rand());
	}
}



EvolutionaryAlgorithm::~EvolutionaryAlgorithm(void)
{
}