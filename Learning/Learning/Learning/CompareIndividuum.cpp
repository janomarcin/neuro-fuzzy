#include "CompareIndividuum.h"


CompareIndividuum::CompareIndividuum(void)
{
}

bool CompareIndividuum::operator() (Individuum *ind1, Individuum *ind2) 
{
	return (*ind1).getFitness() < (*ind2).getFitness();
}

