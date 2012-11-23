#pragma once
#include<vector>
#include<stdio.h>

using namespace std;

class Individuum
{
public:
	Individuum(int length);
	~Individuum(void);

	void setLength(int value);
	int getLength();
	void setFitness(double value);
	double getFitness();
	vector<double> getIndividuum();
	void setIndividuum(vector<double> values);

private:
	int length;
	double fitness;
	vector<double> individuum;

};

