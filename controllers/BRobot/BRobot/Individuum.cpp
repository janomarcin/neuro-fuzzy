#include "Individuum.h"


Individuum::Individuum(int length)
{
	individuum.resize(length);
	this->length = length;
	fitness = 0;
}


int Individuum::getLength()
{
	return length;
}

void Individuum::setFitness(double value)
{
	fitness = value;
}

double Individuum::getFitness()
{
	return fitness;
}

vector<double> Individuum::getIndividuum()
{
	return individuum;
}

void Individuum::setIndividuum(vector<double> values)
{
	individuum = values;
}

Individuum::~Individuum(void)
{
}
