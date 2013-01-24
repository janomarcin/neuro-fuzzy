#include <cstdlib>

#include "Anfis.h"


Anfis::Anfis(int numberOfInputs, int numberOfLingvisticVariables,vector< vector< int > > &rules,vector< vector< vector< double > > > &MFsparameters,vector< vector < double > > &adaptationFunctionParameters,vector< double > &inputs)
{
	//konfiguracia celeho anfisu - len raz
	setNumberOfInputs(numberOfInputs);
	setNumberLingvisticVariables(numberOfLingvisticVariables);
	setRules(rules);
	setNumberOfRules();

	//nastavenie parametrov, ktore sa Anfis uci
	setLingvisticVariablesValues(MFsparameters);
	setAdaptationFunctionValues(adaptationFunctionParameters);

	//vstupy
	setInputValues(inputs);
}

double Anfis::getOutputValue()
{
	countLayerTwoOutput();
	/*for(int i = 0; i < layerTwoOutputs.size(); i++)
	{
		std::cout << "vystup na druhej vrstve z neuronu " << i << " je " << layerTwoOutputs[i] << std::endl;
	}*/
	countLayerThreeOutput();
	/*for(int i = 0; i < layerThreeOutputs.size(); i++)
	{
		std::cout << "vystup na tretej vrstve z neuronu " << i << " je " << layerThreeOutputs[i] << std::endl;
	}*/
	countLayerFourOutput();
	/*for(int i = 0; i < layerFourOutputs.size(); i++)
	{
		std::cout << "vystup na stvrtej vrstve z neuronu " << i << " je " << layerFourOutputs[i] << std::endl;
	}*/
	return countOutputLayer();  //nedorobena normalizacia na - hodnota 0 hodnota + hodnota !!!!!!!!!
}

double Anfis::countOutputLayer()
{
	double sum = 0;
	for(int i = 0; i < numberOfRules; i++){
		sum = sum + layerFourOutputs[i];
	}
	return sum;
}

void Anfis::countLayerFourOutput()
{
	double layerOutputNoWeight,sum;
	layerFourOutputs.resize(numberOfRules);

	for(int i = 0; i < layerFourOutputs.size(); i++){
		sum = 0;
		for(int j = 1; j < numberAnfisInputs; j++){//menovatel zacina od 1 nie 0
			sum = sum + adaptationFunctionValues[i][j] * inputValues[j];
			//std::cout << "adaptationFunctionValues[i][j] " << adaptationFunctionValues[i][j] << std::endl;
		}
		if(sum == 0.0)
		{
			std::cout << "chyba pri vypocte adaptacnej funkcie, menovatel je nulovy!!!" << std::endl;
			system("pause");
			exit(1);
		}

		layerOutputNoWeight = (adaptationFunctionValues[i][0] * inputValues[0])/sum;
		layerFourOutputs[i] = layerOutputNoWeight * layerThreeOutputs[i];
		//std::cout << "vystup na stvrtej vrstve z neuronu " << i << " je " << layerFourOutputs[i] << std::endl;
	}
}

void Anfis::countLayerThreeOutput() 
{// do normalization
	layerThreeOutputs.resize(numberOfRules);

	double sum = 0;
	for(int i = 0; i < layerThreeOutputs.size(); i++){
		sum = sum + layerTwoOutputs[i];
	}
	if (sum == 0)
	{
		std::cout << "nemozem urobit normalizaciu, menovatel je nulovy!!!" << std::endl;
		system("pause");
		exit(1);
		//sum = 1;
	}

	for(int i = 0; i < layerThreeOutputs.size(); i++){
		layerThreeOutputs[i] = layerTwoOutputs[i]/sum;
		//std::cout << "vystup na tretej vrstve z neuronu " << i << " je " << layerThreeOutputs[i] << std::endl;
	}
}

void Anfis::countLayerTwoOutput()
{
	double degree;

	layerTwoOutputs.resize(numberOfRules);
	//initialize vector
	for(int i = 0; i < layerTwoOutputs.size(); i++){
		layerTwoOutputs[i] = 1;
	}

	for(int i = 0; i < layerTwoOutputs.size(); i++){
		for(int j = 0; j < rules.size(); j++){
			//for each rule do this cycle
			if (rules[j][2] == i){

				//lingvisticVariablesValues[vstup][MF][0] - dolna hodnota - x1
				//lingvisticVariablesValues[vstup][MF][1] - horna hodnota - x2
				//rules[cislo_pravidla][0] - ktory vstup
				//rules[cislo_pravidla][1] - ktora MF z daneho vstupu
				//rules[cislo_pravidla][2] - ktoreho vystupu sa tyka dane pravidlo
				//adaptationFunctionValues[vstup][0...pocet_vstupov-parametre adapt. funkcie] - parametre adaptacnej funkcie,   

				degree = getDegreeMF(lingvisticVariablesValues[rules[j][0]][rules[j][1]][0],lingvisticVariablesValues[rules[j][0]][rules[j][1]][1],inputValues[rules[j][0]]);
				//std::cout << "Miera prislusnosti " << degree << std::endl;
				layerTwoOutputs[i] = layerTwoOutputs[i] * degree;
				//std::cout << "vystup na druhej vrstve z neuronu " << i << " je " << layerTwoOutputs[i] << std::endl;
			}
		}
	}
}

void Anfis::setRules(vector< vector < int > > ruless)
{
	rules = ruless;
}

void Anfis::setNumberOfRules()
{
	int max = 0;
	for(int i = 0; i < rules.size(); i++){
		if(max < rules[i][2]){
			max = rules[i][2];
		}
	}

	numberOfRules = max + 1;
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

void Anfis::setAdaptationFunctionValues(vector< vector < double > > adaptation)
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
			lingvisticVariablesValues[i][j][0] = std::rand(); //nastavenie random pre sklon
			lingvisticVariablesValues[i][j][1] = std::rand();
		}
	}
}

void Anfis::setLingvisticVariablesValues(vector< vector < vector < double > > > values)
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

