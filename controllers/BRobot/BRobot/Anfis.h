#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Anfis
{
public:
	Anfis(int numberOfInputs, int numberOfLingvisticVariables,vector< vector< int > > &rules,vector< vector< vector< double > > > &MFsparameters,vector< vector < double > > &adaptationFunctionParameters,vector< double > &inputs);
	~Anfis(void);
	
	void setInputValues(vector< double > inputs);
	void setLingvisticVariablesValues(vector< vector < vector < double > > > values);
	void setLingvisticVariablesValues(); //random
	void setAdaptationFunctionValues(vector< vector < double > > adaptation);
	double getOutputValue();
	

//private:
	void setRules(vector< vector < int > > rules); //co s cim
	void setNumberOfRules();
	void setNumberLingvisticVariables(int count);
	void setNumberOfInputs(int count);

	double getDegreeMF(double x1,double x2,double x); //x1 - start support, x2 - end of support, x - position on x axis
	void countLayerTwoOutput(); //output is set in layerTwoOutputs
	void countLayerThreeOutput(); //output is set in layerThreeOutputs
	void countLayerFourOutput(); //output is set in layerFourOutputs multiplyed with output three
	double countOutputLayer();

	//membership variables private;
	vector<double> layerTwoOutputs;
	vector<double> layerThreeOutputs;
	vector<double> layerFourOutputs;
	
	vector< vector <int> > rules;
	int numberAnfisInputs;
	int numberOfRules; //pocet neuronov na druhej vrstve
	int numberLingvisticVariables;
	vector<double> inputValues;
	vector< vector <vector <double> > > lingvisticVariablesValues;
	vector< vector <double> > adaptationFunctionValues;

};

