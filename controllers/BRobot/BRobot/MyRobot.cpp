#include "MyRobot.h"


MyRobot::MyRobot(void) : Supervisor()
{
	//loadFileData();
	rootNode = Supervisor::getRoot();
	robotNode = Supervisor::getFromDef("GA");
	field = robotNode->getField("translation");

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

	mfparameter.resize(2);
	for(int i = 0; i < 2; i++)
	{
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
}


MyRobot::~MyRobot(void)
{
	delete anfis;
}

void MyRobot::run() 
{
	//init(random nastavenie anfisu)
	for(int i = 0; i < 3; i++)
	{
		for (double t = 0.0; t < 14400.0; t+= STEP) 
		{
				//robotIO.setSpeed(3.0);
				robotIO.getSensorData(input); //vstup do anfisu
				anfis = new Anfis(2,2,rules,mfparameter,adaptation,input); //nastavenie anfisu
				/*for(int j = 0; j < input.size(); j++)
				{
					std::cout << input[j] << std::endl;
				}*/
				std::cout << anfis->getOutputValue() << std::endl; //vystup z anfisu
				//robotIO.setSpeed(anfis->getOutputValue());
				step(STEP);
				//evaluate fitness
		}

		//crossover

		const double *pos = field->getSFVec3f();
		double dist = sqrt(pos[0] * pos[0] + pos[2] * pos[2]);

		std::cout <<"dist = " << dist << std::endl;
		const double INITIAL[3] = { 0, 0.5, 0 };
		field->setSFVec3f(INITIAL);
	}
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