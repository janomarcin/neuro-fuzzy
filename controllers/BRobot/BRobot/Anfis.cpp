#include "Anfis.h"


Anfis::Anfis(int numberOfInputs, int numberOfLingvisticVariables,vector<vector<int>> rules,vector<vector<vector<double>>> MFsparameters,vector<vector<double>> adaptationFunctionParameters,vector<double> inputs)
{
	//konfiguracia celeho anfisu - len raz
	setNumberOfInputs(numberOfInputs);
	setNumberLingvisticVariables(numberOfLingvisticVariables);
	setRules(rules);

	//nastavenie parametrov, ktore sa Anfis uci
	setLingvisticVariablesValues(MFsparameters);
	setAdaptationFunctionValues(adaptationFunctionParameters);

	//vstupy
	setInputValues(inputs);
}

double Anfis::getOutputValue()
{
	countLayerTwoOutput();
	countLayerThreeOutput();
	countLayerFourOutput();
	return countOutputLayer();
}

double Anfis::countOutputLayer()
{
	double sum = 0;
	for(int i = 0; i < numberAnfisInputs; i++){
		sum = sum + layerFourOutputs[i];
	}
	return sum;
}

void Anfis::countLayerFourOutput()
{
	double layerOutputNoWeight,sum;
	layerFourOutputs.resize(numberAnfisInputs);

	for(int i = 0; i < numberAnfisInputs; i++){
		sum = 0;
		for(int j = 1; j < numberAnfisInputs; j++){//menovatel zacina od 1 nie 0
			sum = sum + adaptationFunctionValues[i][j] * inputValues[j];
		}
		if(sum == 0)
			printf("suma je nulova!!!");

		layerOutputNoWeight = (adaptationFunctionValues[i][0] * inputValues[0])/sum;
		layerFourOutputs[i] = layerOutputNoWeight * layerThreeOutputs[i];
	}
}

void Anfis::countLayerThreeOutput() 
{// do normalization
	layerThreeOutputs.resize(numberAnfisInputs);

	double sum = 0;
	for(int i = 0; i < numberAnfisInputs; i++){
		sum = sum + layerTwoOutputs[i];
	}

	for(int i = 0; i < numberAnfisInputs; i++){
		layerThreeOutputs[i] = layerTwoOutputs[i]/sum;
	}
}

void Anfis::countLayerTwoOutput()
{
	double degree;

	layerTwoOutputs.resize(numberAnfisInputs);
	//initialize vector
	for(int i = 0; i < numberAnfisInputs; i++){
		layerTwoOutputs[i] = 1;
	}

	for(int i = 0; i < numberAnfisInputs; i++){
		for(int j = 0; j < rules.size(); j++){
			//for each rule do this cycle
			if (rules[j][2] == i){

				//lingvisticVariablesValues[vstup][MF][0] - dolna hodnota - x1
				//lingvisticVariablesValues[vstup][MF][1] - horna hodnota - x2
				//rules[cislo_pravidla][0] - ktory vstup
				//rules[cislo_pravidla][1] - ktora MF z daneho vstupu
				//rules[cislo_pravidla][2] - ktoreho vystupu sa tyka dane pravidlo
				//adaptationFunctionValues[vstup][0...pocet_vstupov-parametre adapt. funkcie] - parametre adaptacnej funkcie,   

				degree = getDegreeMF(lingvisticVariablesValues[i][rules[j][1]][0],lingvisticVariablesValues[i][rules[j][1]][1],inputValues[i]);
				layerTwoOutputs[i] = layerTwoOutputs[i] * degree;
			}
		}
	}
}

void Anfis::setRules(vector<vector<int>> rules)
{
	this->rules = rules;
}

double Anfis::getDegreeMF(double x1, double x2, double x)
{	//triangle function
	//if x1 > x2 switch it, should be x1<x2
	double pom,k;
	if (x1 > x2){
		pom = x1;
		x1 = x2;
		x2 = pom;
	}

	if (x <= x1)
		return 0;

	if (x <= (x1+x2)/2){
		k = 1/(((x2+x1)*0.5)-x1);
		return k*x-k*x1;
	}

	if (x < x2){
		k = 1/(((x2+x1)*0.5)-x2);
		return k*x-k*x2;
	}

	else
		return 0;
}

void Anfis::setAdaptationFunctionValues(vector<vector<double>> adaptation)
{
	adaptationFunctionValues = adaptation;
}

void Anfis::setLingvisticVariablesValues()
{
	//settings of random values
	int i,j;
	lingvisticVariablesValues.resize(numberAnfisInputs);
	for(i = 0; i < numberAnfisInputs; i++){
		lingvisticVariablesValues[i].resize(numberLingvisticVariables);	

		for(j = 0; j < numberLingvisticVariables; j++){
			lingvisticVariablesValues[i][j].resize(2);
			lingvisticVariablesValues[i][j][0] = rand(); //nastavenie random pre sklon
			lingvisticVariablesValues[i][j][1] = rand();
		}
	}
}

void Anfis::setLingvisticVariablesValues(vector<vector<vector<double>>> values)
{
	lingvisticVariablesValues = values;
}

void Anfis::setInputValues(std::vector<double> values)
{
	inputValues = values;
}

void Anfis::setNumberOfInputs(int count)
{
	numberAnfisInputs = count;
}

void Anfis::setNumberLingvisticVariables(int count)
{
	numberLingvisticVariables = count;
}


Anfis::~Anfis(void)
{
}

