#include "EvolutionaryAlgorithm.h"
#define RANDOM_VALUE  (2*((double)rand()/(double)RAND_MAX) - 1)*10 //<-1;1>

const int tournament = 3;
const float mutationValue = 0.3;
const float mutationPowerValue = 0.4;

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
	cout << "Spustam crossing " << endl;
	vector<double> parent1;
	vector<double> parent2;

	vector<double> descendantGenes1;
	vector<double> descendantGenes2;

	for(int i = 0; i < (int) numberOfIndividuums/2; i++){

		int sel1,sel2;

		Individuum* descendant1 = new Individuum(population[0]->getLength());
		Individuum* descendant2 = new Individuum(population[0]->getLength());
		descendant1->setFitness(99999);
		descendant2->setFitness(99999);

		sel1 = selection();
		sel2 = selection();
		cout << "sel1" << sel1 << " sel2" << sel2 << endl;
		while (sel2 == sel1){
			std::cout << "selected identical" <<std::endl;
			sel2 = selection();
		}

		parent1 = population[sel1]->getIndividuum();
		parent2 = population[sel2]->getIndividuum();
		descendantGenes1.resize(parent1.size());
		descendantGenes2.resize(parent2.size());

		for(int j = 0; j < parent1.size(); j++){
			descendantGenes1[j] = 0.5*parent1[j]+0.5*parent2[j];
			descendantGenes2[j] = 0.7*parent1[j]+0.3*parent2[j];
		}
		descendant1->setIndividuum(descendantGenes1);
		descendant2->setIndividuum(descendantGenes2);
		population.push_back(descendant1);
		population.push_back(descendant2);
	}

	cout << "end crossing " << endl;
}

void EvolutionaryAlgorithm::substitution(){

	std::sort(population.begin(),population.end(),CompareIndividuum());
	population.erase(population.begin() + numberOfIndividuums,population.end());
}

void EvolutionaryAlgorithm::mutation(){
	vector<double> values;
	for(int i = numberOfIndividuums; i < population.size(); i++){
		if(((double)rand()/(double)RAND_MAX) < mutationValue){
			values.resize(population[i]->getLength());
			values = population[i]->getIndividuum();

			for(int j = 0; j < population[i]->getLength(); j++){
				if(((double)rand()/(double)RAND_MAX) < mutationPowerValue){
					values[j] = RANDOM_VALUE; //new value
				}
			}
			population[i]->setIndividuum(values);
		}
	}
}

int EvolutionaryAlgorithm::selection(){ //vrati index jedinca

	//selection of min fitness individuum

	int winner,newIndex;
	vector<int> selParents, indexes;
	selParents.resize(tournament);

	for(int i = 0; i < numberOfIndividuums; i++){
		indexes.push_back(i);
	}
    
    for(int i = 0; i < tournament; i++){
		newIndex = rand() % indexes.size(); 
	    selParents[i] = indexes[newIndex];
		indexes.erase(indexes.begin()+newIndex);
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
			jedinec[j] = RANDOM_VALUE;
		}

		population[i]->setIndividuum(jedinec);
		population[i]->setFitness(999999);
	}
}

EvolutionaryAlgorithm::~EvolutionaryAlgorithm(void)
{
}