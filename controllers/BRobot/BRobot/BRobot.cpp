#include "MyRobot.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::cout << "starting controller" << std::endl;

		vector< vector< int > > rules;
		rules.resize(8);
		for( int i = 0; i < rules.size(); i++)
		{
				rules[i].resize(3);
		}
		//subor

		rules[0][0] =0;
		rules[0][1] =0;
		rules[0][2] =0;

		rules[1][0] =1;
		rules[1][1] =0;
		rules[1][2] =0;

		rules[2][0] =0;
		rules[2][1] =0;
		rules[2][2] =2;

		rules[3][0] =1;
		rules[3][1] =1;
		rules[3][2] =2;

		rules[4][0] =0;
		rules[4][1] =1;
		rules[4][2] =1;

		rules[5][0] =1;
		rules[5][1] =1;
		rules[5][2] =1;

		rules[6][0] =0;
		rules[6][1] =1;
		rules[6][2] =3;

		rules[7][0] =1;
		rules[7][1] =0;
		rules[7][2] =3;

		vector< vector < vector <double> > >  mfparameter;
		mfparameter.resize(2);
		for(int i = 0; i < 2; i++){
				mfparameter[i].resize(2);
				for(int j = 0; j < 2; j++)
				{
						mfparameter[i][j].resize(2);			
				}
		}
		//receiver
		mfparameter[0][0][0] = -3;
		mfparameter[0][0][1] = 3;

		mfparameter[0][1][0] = 2;
		mfparameter[0][1][1] = 8;

		mfparameter[1][0][0] = 0;
		mfparameter[1][0][1] = 4;

		mfparameter[1][1][0] = 2;
		mfparameter[1][1][1] = 6;

		vector< vector< double > > adaptation;
		adaptation.resize(4);

		for(int i = 0; i < 4; i++)
		{
				adaptation[i].resize(2);	
		}
		//receiver
		adaptation[0][0] =1;
		adaptation[0][1] =2; //2

		adaptation[1][0] =3;
		adaptation[1][1] =4;

		adaptation[2][0] =-1;
		adaptation[2][1] =2;

		adaptation[3][0] =-3;
		adaptation[3][1] =4;

		vector<double> input;
		input.push_back(1);
		input.push_back(3);

		Anfis * anfis = new Anfis(2,2,rules,mfparameter,adaptation,input);
		std::cout << "anfis output" <<std::endl;
		std::cout << anfis->getOutputValue() <<std::endl;
		system("pause");


	MyRobot controller;
	controller.run();

	return 0;
}
