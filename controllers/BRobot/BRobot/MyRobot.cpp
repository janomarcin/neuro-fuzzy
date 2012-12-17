#include "MyRobot.h"


MyRobot::MyRobot(void) : Supervisor()
{
	//loadFileData();
	rootNode = Supervisor::getRoot();
	robotNode = Supervisor::getFromDef("GA");
	field = robotNode->getField("translation");
}


MyRobot::~MyRobot(void)
{
}

void MyRobot::run() 
{
	//const double *position = field->getSFVec3f();
	//std::cout << "X = " << position[0] << " Y = " << position[1] << " Z = " << position[2] << std::endl; 

		//std::cout << rootNode->getTypeName() << std::endl;
		//std::cout << robotNode->getTypeName() << std::endl;
		//std::cout << robotNode->getPosition() << std::endl;
		//robotNode->getField("Translation");

		for (double t = 0.0; t < 14400.0; t+= STEP) 
		{
				robotIO.setSpeed(3.0);
				step(STEP);
		}

		const double *pos = field->getSFVec3f();
		double dist = sqrt(pos[0] * pos[0] + pos[2] * pos[2]);

		std::cout <<"dist = " << dist << std::endl;
		const double INITIAL[3] = { 0, 0.5, 0 };
		field->setSFVec3f(INITIAL);
		Supervisor::simulationRevert();
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