#include "MyRobot.h"


MyRobot::MyRobot(void) : Supervisor()
{
	//loadFileData();
	rootNode = Supervisor::getRoot();
	robotNode = Supervisor::getFromDef("GA");
	field = robotNode->getField("translation");
	Supervisor::keyboardEnable(20);
	evolutionaryAlgorithm = new EvolutionaryAlgorithm(18, 3);
	input.push_back(10.0);
	input.push_back(10.0);
	speed = 2.0;
	side = 0.0;

	rules.resize(18);
	for( int i = 0; i < rules.size(); i++)
	{
		rules[i].resize(3);
	}
	//subor

	rules[0][0] =0;
	rules[0][1] =0;
	rules[0][2] =0;

	rules[1][0] =0;
	rules[1][1] =0;
	rules[1][2] =1;

	rules[2][0] =0;
	rules[2][1] =0;
	rules[2][2] =2;

	rules[3][0] =0;
	rules[3][1] =1;
	rules[3][2] =3;

	rules[4][0] =0;
	rules[4][1] =1;
	rules[4][2] =4;

	rules[5][0] =0;
	rules[5][1] =1;
	rules[5][2] =5;

	rules[6][0] = 0;
	rules[6][1]	= 2;
	rules[6][2]	= 6;

	rules[7][0] = 0;
	rules[7][1] = 2;
	rules[7][2]	= 7;

	rules[8][0] = 0;
	rules[8][1] = 2;
	rules[8][2] = 8;

	rules[9][0] = 1;
	rules[9][1]	= 0;
	rules[9][2] = 0;

	rules[10][0] = 1;
	rules[10][1] = 1;
	rules[10][2] = 1;

	rules[11][0] = 1;
	rules[11][1] = 2;
	rules[11][2] = 2;

	rules[12][0] = 1;
	rules[12][1] = 0;
	rules[12][2] = 3;

	rules[13][0] = 1;
	rules[13][1] = 1;
	rules[13][2] = 4;

	rules[14][0] = 1;
	rules[14][1] = 2;
	rules[14][2] = 5;

	rules[15][0] = 1;
	rules[15][1] = 0;
	rules[15][2] = 6;

	rules[16][0] = 1;
	rules[16][1] = 1;
	rules[16][2] = 7;

	rules[17][0] = 1;
	rules[17][1] = 2;
	rules[17][2] = 8;


	/*rules[6][0] =0;
	rules[6][1] =1;
	rules[6][2] =3;

	rules[7][0] =1;
	rules[7][1] =0;
	rules[7][2] =3;*/

	mfparameter.resize(2);
	for(int i = 0; i < 2; i++)
	{
		mfparameter[i].resize(3);
		for(int j = 0; j < 3; j++)
		{
			mfparameter[i][j].resize(2);
		}
	}
	//receiver
	mfparameter[0][0][0] = -5;
	mfparameter[0][0][1] = 5;

	mfparameter[0][1][0] = 2;
	mfparameter[0][1][1] = 8;
	
	mfparameter[0][2][0] = 5;
	mfparameter[0][2][1] = 15;

	mfparameter[1][0][0] = -5;
	mfparameter[1][0][1] = 5;

	mfparameter[1][1][0] = 2;
	mfparameter[1][1][1] = 8;
	
	mfparameter[1][2][0] = 5;
	mfparameter[1][2][1] = 15;

	adaptation.resize(9);

	for(int i = 0; i < 9; i++)
	{
		adaptation[i].resize(2);
	}
	//receiver
	adaptation[0][0] =1;
	adaptation[0][1] =1; //2

	adaptation[1][0] =3;
	adaptation[1][1] =4;

	adaptation[2][0] =-1;
	adaptation[2][1] =2;

	//adaptation[3][0] =-3;
	//adaptation[3][1] =4;
	anfis = new Anfis(2,3,rules,mfparameter,adaptation,input); 
}


MyRobot::~MyRobot(void)
{
	delete anfis;
}

void MyRobot::run() 
{
	input.clear();
	std::vector<double> adaptations;
	//Supervisor::startMovie("Roman", 400, 600, 1, 100);
	evolutionaryAlgorithm->initPopulation();

for(int pocet = 0; pocet < 10; pocet++)
{
	const double INITIAL[3] = { 0, 0.5, 0 };
	field->setSFVec3f(INITIAL);

	for(int i = 0; i < 3; i++)
	{
		adaptations = evolutionaryAlgorithm->population[i]->getIndividuum();
		/*for(int j = 0; j < adaptations.size(); j++)
		{
			cout << adaptations[j] << " ";
		}*/

		int s = 0;
		for(int j = 0; j < adaptations.size()/2; j++)
		{
				adaptation[j][0] = adaptations[s];
				std::cout << "adaptation[j][0] " << adaptation[j][0] << endl;
				s++;
				adaptation[j][1] = adaptations[s];
				std::cout << "adaptation[j][1] " << adaptation[j][1] << endl;
				s++;
		}

		/*for(int j = 0; j < adaptations.size(); j++)
		{
			cout << adaptations[j] << " ";
		}*/

		anfis->setAdaptationFunctionValues(adaptation);

		for (double t = 0.0; t < 14400.0; t+= STEP) 
		{
			input.clear();
			robotIO.setSpeed(speed, side);
			/*
			char key = Supervisor::keyboardGetKey();
			if(key == 'W')
				speed += 0.2;
			if(key == 'S')
				speed += -0.2;
			if(key == 'D')
				side += 0.2;
			if(key == 'A')
				side -= 0.2;*/
			robotIO.getSensorData(input);

			for(int j = 0; j < input.size(); j++)
			{
				if(input[j] > 0)
				{
					input[j] = input[j];
					//std::cout << input[j] << std::endl;
				}
				else
				{
					input[j] = 5.0;
					//std::cout << input[j] << std::endl;
				}
			}

			//std::cout << std::endl;

			anfis->setInputValues(input);
			//std::cout << std::endl;
			//std::cout << " anfis " << anfis->getOutputValue() << std::endl; //vystup z anfisu
			evolutionaryAlgorithm->population[i]->setFitness(rand());
			robotIO.setSpeed(speed,anfis->getOutputValue());
			step(STEP);
		}
		const double *pos = field->getSFVec3f();
		double dist = sqrt(pos[0] * pos[0] + pos[2] * pos[2]);

		std::cout <<"dist = " << dist << std::endl;
		const double INITIAL[3] = { 0, 0.5, 0 };
		field->setSFVec3f(INITIAL);
		//Supervisor::stopMovie();
	}

	for(int ds = 0; ds < 3; ds++)
	{
		evolutionaryAlgorithm->crossing();
		//evolutionaryAlgorithm->mutation();
		//evolutionaryAlgorithm->population[i]->setFitness(rand());
		//evolutionaryAlgorithm->substitution();
	}
	//step(STEP);
}
	//Supervisor::stopMovie();
}

void MyRobot::loadFileData()
{
	std::ifstream inFileConfig;
    inFileConfig.open("controller.config", std::ifstream::in);

    std::string line;
    std::vector<std::string> file;
    std::vector<int> znalost;
	std::vector<double> rules1;
	std::vector<double> rules2;

    while(!inFileConfig.eof())
    {
        getline(inFileConfig, line);
        file.push_back(line);
    }

    int numberOfInputs = atoi(file[0].c_str());
    file.erase(file.begin());
    int numberOfLingvisticVariables = atoi(file[0].c_str());
    file.erase(file.begin());

    for(unsigned int i = 0; i < file.size(); i++)
    {
        znalost.clear();
        for(unsigned int j = 0; j < file[i].size(); j+=2)
        {
            znalost.push_back(atoi(file[i].c_str() + j));
        }
        rules.push_back(znalost);
    }

    for(unsigned int i = 0; i < rules.size(); i++)
    {
        for(unsigned int j = 0; j < rules[i].size(); j++)
        {
            std::cout << rules[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    //--------------------------------------------------------------------------

    std::ifstream inFileParams;
    inFileParams.open("controller.params", std::ifstream::in);

    file.clear();

    while(!inFileParams.eof())
    {
        getline(inFileParams, line);
        file.push_back(line);
    }

	unsigned int index = 0;
	while(!(file[index] == "-"))
	{
		rules1.clear();
		for(unsigned int j = 0; j < file[index].size(); j+=2)
        {
            rules1.push_back(atof(file[index].c_str() + j));
		}
		Vrules1.push_back(rules1);
		index++;
	}

	index++;

	while(!(index == file.size()))
	{
		rules2.clear();
		for(unsigned int j = 0; j < file[index].size(); j+=2)
        {
            rules2.push_back(atof(file[index].c_str() + j));
		}
		Vrules2.push_back(rules2);
		index++;
	}

	for(unsigned int i = 0; i < Vrules1.size(); i++)
    {
        for(unsigned int j = 0; j < Vrules1[i].size(); j++)
        {
            std::cout << Vrules1[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

	for(unsigned int i = 0; i < Vrules2.size(); i++)
    {
        for(unsigned int j = 0; j < Vrules2[i].size(); j++)
        {
            std::cout << Vrules2[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    inFileParams.close();
    inFileConfig.close();
}