#include "Repository.h"
#include <iostream>

using namespace std;


PlantRepository & PlantRepository::operator=(PlantRepository & copyRepository)
{
	// TODO: insert return statement here
	//this->listOfPlants = copyRepository.listOfPlants;
	return *this;
}

PlantRepository::PlantRepository(PlantRepository & copyRepository)
{
	//this->listOfPlants = copyRepository.listOfPlants;
}

PlantRepository::PlantRepository()
{
	
}

int PlantRepository::findIndexOfElement(string& codeNameToFind)
{
	for (int i = 0; i < this->listOfPlants.getSize(); ++i)
	{
		if (codeNameToFind == this->listOfPlants[i].getCodeName())
			return i;
	}
	return -1;
}

void PlantRepository::storeNewPlant(Plant& newPlantToStore)
{
	if (this->findIndexOfElement(newPlantToStore.getCodeName()) == -1)
	{
		this->listOfPlants.add(newPlantToStore);
	}
	else
	{
		throw "Invalid code name, plant cluster already exists!";
	}
}

void PlantRepository::updatePlant(Plant & plantToUpdateWith)
{
	int indexToUpdate = this->findIndexOfElement(plantToUpdateWith.getCodeName());
	if (indexToUpdate != -1)
	{
		this->listOfPlants.update(indexToUpdate, plantToUpdateWith);
	}
	else
	{
		throw "Invalid code name, plant cluster doesn't exists!";
	}
}

void PlantRepository::removePlant(string & codeNameToRemove)
{
	int indexToRemove = this->findIndexOfElement(codeNameToRemove);
	if(indexToRemove != -1)
	{
		this->listOfPlants.remove(indexToRemove);
	}
	else
	{
		throw "Invalid code name, plant cluster doesn't exists!";
	}
}

DynamicVector<Plant>& PlantRepository::listAllElements()
{
	return this->listOfPlants;
}


