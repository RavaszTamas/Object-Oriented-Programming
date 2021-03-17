#include "UI.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Utilities.h"
using namespace std;

void Console::UIList(vector<string>& inputParameters)
{
	if (inputParameters.size() == 1)
	{
		DynamicVector<Plant>& const listOfPlants = this->controller.listAll();
		for (int i = 0; i < listOfPlants.getSize(); ++i)
			cout << listOfPlants[i].getCodeName() << " " << listOfPlants[i].getSpecies() << " " << listOfPlants[i].getAgeInMonths() << " " << listOfPlants[i].getDigitizedScan() << "\n";
	}
	else if(inputParameters.size() == 2)
	{
		if (CheckIfAllDigits(inputParameters[1]))
		{
			int monthAge = atoi(inputParameters[1].c_str());
			string empty = "";
			DynamicVector<Plant> elementsToPrint = this->controller.displayPlantClutersByAgeAndSpecies(empty, monthAge);//Empty string, beacuse no species was specified
			for (int i = 0; i < elementsToPrint.getSize(); ++i)
				cout << elementsToPrint[i].getCodeName() << " " << elementsToPrint[i].getSpecies() << " " << elementsToPrint[i].getAgeInMonths() << " " << elementsToPrint[i].getDigitizedScan() << "\n";
		}
		else
		{
			cout << "Invalid parameter type for age!";
		}
	}
	else if (inputParameters.size() == 3)
	{
		if (CheckIfAllDigits(inputParameters[2]))
		{
			int monthAge = atoi(inputParameters[2].c_str());
			DynamicVector<Plant> elementsToPrint = this->controller.displayPlantClutersByAgeAndSpecies(inputParameters[1], monthAge);
			for (int i = 0; i < elementsToPrint.getSize(); ++i)
				cout << elementsToPrint[i].getCodeName() << " " << elementsToPrint[i].getSpecies() << " " << elementsToPrint[i].getAgeInMonths() << " " << elementsToPrint[i].getDigitizedScan() << "\n";

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
	DynamicVector<Plant> listOfPlants = this->controller.displayChosenPlantClusters();
	for (int i = 0; i < listOfPlants.getSize(); ++i)
		cout << listOfPlants[i].getCodeName() << " " << listOfPlants[i].getSpecies() << " " << listOfPlants[i].getAgeInMonths() << " " << listOfPlants[i].getDigitizedScan() << "\n";

}

void Console::UISave(vector<string>& inputParameters)
{
	if (inputParameters.size() == 1)
	{
		string empty = "";
		this->controller.saveToUprootList(empty);//Empty string for the current element in the next functionality's case
	}
	else if (inputParameters.size() == 2)
	{
		this->controller.saveToUprootList(inputParameters[1]);
	}
	else
	{
		cout << "Invalid number of parameters!\n";
	}
}

Console::Console(AppController & applicationController):controller(applicationController)
{
	//this->controller = applicationController;
}

void Console::run()
{
	string inputUser;
	vector<string> inputParameters;
	while (true)
	{
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
			else if (inputParameters[0] == "exit")
			{
				return;
			}
			else
				cout << "Invalid command!";
		}
		catch (const char* message)
		{
			cout << message << endl << endl;
		}


		//for (auto it = inputParameters.begin(); it != inputParameters.end(); ++it)
			//cout << (*it) << " ";
		//cout << endl;
		inputUser.clear();
		inputParameters.clear();
	}
}

