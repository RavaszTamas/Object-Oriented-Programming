#include "UI.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Utilities.h"
#include <exception>
#include "myexceptions.h"

using namespace std;

void Console::UIList(vector<string>& inputParameters)
{
	if (inputParameters.size() == 1)
	{
		vector<Plant> const listOfPlants = this->controller.listAll();
		for (auto iteratorPlant : listOfPlants)
			cout << iteratorPlant << endl;
	}
	else if(inputParameters.size() == 2)
	{
		if (CheckIfAllDigits(inputParameters[1]))
		{
			int monthAge = atoi(inputParameters[1].c_str());
			string empty = "";
			vector<Plant> elementsToPrint = this->controller.displayPlantClutersByAgeAndSpecies(empty, monthAge);//Empty string, beacuse no species was specified
			for (auto iteratorPlant : elementsToPrint)
				cout << iteratorPlant << endl;
		}
		else
		{
			cout << "Invalid parameter type for age!\n";
		}
	}
	else if (inputParameters.size() == 3)
	{
		if (CheckIfAllDigits(inputParameters[2]))
		{
			int monthAge = atoi(inputParameters[2].c_str());
			vector<Plant> elementsToPrint = this->controller.displayPlantClutersByAgeAndSpecies(inputParameters[1], monthAge);
			for (auto iteratorPlant : elementsToPrint)
				cout << iteratorPlant << endl;

		}
		else
		{
			cout << "Invalid parameter type for age!\n";
		}

	}
	else
	{
		cout << ("Invalid number of parameters\n");
		return;
	}
}

void Console::UIDeletePlant(vector<string>& inputParameters)
{
	if (inputParameters.size() != 2)
	{
		cout << ("Invalid number of parameters\n");
		return;
	}
	this->controller.DeletePlant(inputParameters[1]);
}


void Console::UIUpdatePlant(vector<string>& inputParameters)
{
	if (inputParameters.size() != 5)
	{
		cout << ("Invalid number of parameters\n");
		return;
	}
	if (!CheckIfAllDigits(inputParameters[3]))
	{
		cout << "Invalid numerical input\n";
		return;
	}
	int monthAge = atoi(inputParameters[3].c_str());

	this->controller.UpdatePlant(inputParameters[1], inputParameters[2], monthAge, inputParameters[4]);

}


void Console::UIAddPlant(vector<string>& inputParameters)
{
	if (inputParameters.size() != 5)
	{
		cout << "Invalid number of parameters\n";
		return;
	}
	if (!CheckIfAllDigits(inputParameters[3]))
	{
		cout << "Invalid numerical input\n";
		return;
	}

	int monthAge = atoi(inputParameters[3].c_str());

	this->controller.AddNewPlant(inputParameters[1], inputParameters[2], monthAge, inputParameters[4]);

}

void Console::UIChooseMode(vector<string>& inputParameters)
{
	if (inputParameters.size() != 2)
	{
		cout << ("Invalid number of parameters\n");
		return;
	}
	this->controller.SetMode(inputParameters[1]);
}

void Console::ProcessInput(vector<string>& inputParameters, string& inputData)
{
	string delimiter = ", ";
	size_t positionOfParameter = 0;
	string tokenOfInput = inputData.substr(0, inputData.find(" "));

	inputParameters.push_back(tokenOfInput);

	inputData.erase(0, tokenOfInput.length()+1);
	
	while ((positionOfParameter = inputData.find(delimiter)) != string::npos)
	{
		tokenOfInput = inputData.substr(0, positionOfParameter);
		inputParameters.push_back(tokenOfInput);
		inputData.erase(0, positionOfParameter + delimiter.length());
	}
	inputData.erase(inputData.find_last_not_of(" \n\r\t") + 1);
	if(inputData != "")
		inputParameters.push_back(inputData);
}

void Console::UINext()
{
	Plant currentPlant = this->controller.getCurrentPlantByNext();
	cout << currentPlant.getCodeName() << " " << currentPlant.getSpecies() << " " << currentPlant.getAgeInMonths() << " " << currentPlant.getDigitizedScan() << "\n";
}

void Console::UIMylist()
{
	//this->controller.displayChosenPlantClusters();
	
	vector<Plant> listOfPlants = this->controller.displayChosenPlantClusters();
	for (auto iteratorPlant : listOfPlants)
		cout << iteratorPlant << endl;
	
}

void Console::UISave(vector<string>& inputParameters)
{
	if (inputParameters.size() == 2)
	{
		this->controller.saveToUprootList(inputParameters[1]);
	}
	else
	{
		cout << "Invalid number of parameters!\n";
	}
}

void Console::UIFileLocation(string inputUser)
{	
	this->controller.ApplyFileLocation(inputUser);
	//cout << "Invalid number of parameters!\n";
}

void Console::UIMylistLocation(string inputUser)
{
	this->controller.ApplyMyListLocation(inputUser);
}


Console::Console(AppController & applicationController):controller(applicationController)
{
	//this->controller = applicationController;
}

void Console::PrintHeader()
{
	string header =  "\n   _____                      _        _____       _             __               \n";
		   header += "  / ____|                    | |      |_   _|     | |           / _|              \n";
	       header += " | |     ___  _ __  ___  ___ | | ___    | |  _ __ | |_ ___ _ __| |_ __ _  ___ ___ \n";
		   header += " | |    / _ \\| '_ \\/ __|/ _ \\| |/ _ \\   | | | '_ \\| __/ _ \\ '__|  _/ _` |/ __/ _ \\\n";
		   header += " | |___| (_) | | | \\__ \\ (_) | |  __/  _| |_| | | | ||  __/ |  | || (_| | (_|  __/\n";
		   header += "  \\_____\\___/|_| |_|___/\\___/|_|\\___| |_____|_| |_|\\__\\___|_|  |_| \\__,_|\\___\\___|\n";
		   header += "\n";
		   cout << header;
}

void Console::run()
{
	string inputUser;
	vector<string> inputParameters;
	while (true)
	{
		//PrintHeader();
		getline(cin, inputUser);

		ProcessInput(inputParameters, inputUser);
		try
		{

			if (inputParameters.size() == 0)
			{
				cout << "Invalid input!\n";
			}
			else if (inputParameters[0] == "mode")
			{
				UIChooseMode(inputParameters);
			}
			else if (inputParameters[0] == "add")
			{
				UIAddPlant(inputParameters);
			}
			else if (inputParameters[0] == "update")
			{
				UIUpdatePlant(inputParameters);

			}
			else if (inputParameters[0] == "delete")
			{
				UIDeletePlant(inputParameters);

			}
			else if (inputParameters[0] == "list")
			{
				UIList(inputParameters);
			}
			else if (inputParameters[0] == "next")
			{
				UINext();
			}
			else if (inputParameters[0] == "save")
			{
				UISave(inputParameters);
			}
			else if (inputParameters[0] == "mylist")
			{
				UIMylist();
			}
			else if (inputParameters[0] == "mylistLocation")
			{
				UIMylistLocation(inputUser);
			}
			else if (inputParameters[0] == "fileLocation")
			{
				UIFileLocation(inputUser);
			}
			else if (inputParameters[0] == "exit")
				return;
			else
				cout << "Invalid command!" << endl;
		}
		catch (ServiceException& except)
		{
			cout << except.what() << endl;
		}
		catch (ValidationException& except)
		{
			cout << except.what() << endl;
		}
		catch (RepositoryException& except)
		{
			cout << except.what() << endl;
		}

		//for (auto it = inputParameters.begin(); it != inputParameters.end(); ++it)
			//cout << (*it) << " ";
		//cout << endl;
		inputUser.clear();
		inputParameters.clear();
	}
}

