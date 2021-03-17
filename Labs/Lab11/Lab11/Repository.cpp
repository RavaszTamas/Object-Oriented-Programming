#include "Repository.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include "Domain.h"
#include "myexceptions.h"
using namespace std;

vector<Plant> PlantRepositoryMemory::readFromFile()
{
	throw RepositoryException("Not a file repository!");

	return vector<Plant>();
}

void PlantRepositoryMemory::saveToFile(vector<Plant>)
{
	throw RepositoryException("Not a file repository!");
}

string PlantRepositoryMemory::getType()
{
	return string("memory");
}

PlantRepositoryMemory::PlantRepositoryMemory() : PlantRepository{}
{
	
}

int PlantRepositoryMemory::findIndexOfElement(string codeNameToFind)
{
	int indexToReturn = 0;
	for (auto iteratorPlant = this->listOfPlants.begin(); iteratorPlant != this->listOfPlants.end(); ++iteratorPlant)
	{
		if (codeNameToFind == iteratorPlant->getCodeName())
			return indexToReturn;
		indexToReturn++;
	}
	return -1;
}

void PlantRepositoryMemory::storeNewPlant(Plant& newPlantToStore)
{
	if (this->findIndexOfElement(newPlantToStore.getCodeName()) == -1)
	{
		this->listOfPlants.push_back(newPlantToStore);
	}
	else
	{
		throw RepositoryException("Invalid code name, plant cluster already exists!");
	}
}

Plant PlantRepositoryMemory::updatePlant(const Plant & plantToUpdateWith)
{
	//int indexToUpdate = this->findIndexOfElement(plantToUpdateWith.getCodeName());
	string codename = plantToUpdateWith.getCodeName();
	
	auto iteratorPlant = find_if(this->listOfPlants.begin(), this->listOfPlants.end(), [plantToUpdateWith](Plant& plant) {return plant == plantToUpdateWith; });
	/*
	auto it = this->listOfPlants.begin();
	bool good = true;
	for (; it != this->listOfPlants.end() && good; ++it)
	{
		if (*it == plantToUpdateWith)
			good = false;
	}
	if (good == false)
		--it;
	*/
	Plant oldPLant;
	if (iteratorPlant != this->listOfPlants.end())
	{
		oldPLant = this->listOfPlants.at(distance(this->listOfPlants.begin(), iteratorPlant));
		this->listOfPlants.at(distance(this->listOfPlants.begin(), iteratorPlant)) = plantToUpdateWith;
		//this->listOfPlants.update(indexToUpdate, plantToUpdateWith);
	}
	else
	{
		throw RepositoryException("Invalid code name, plant cluster doesn't exists!");
	}
	return oldPLant;
}

Plant PlantRepositoryMemory::removePlant(const string & codeNameToRemove)
{
	//int indexToRemove = this->findIndexOfElement(codeNameToRemove);
	auto iteratorPlant = find_if(this->listOfPlants.begin(), this->listOfPlants.end(), [codeNameToRemove](Plant& plant) {return plant.getCodeName() == codeNameToRemove; });
	/*auto it = this->listOfPlants.begin();
	bool good = true;
	for (; it != this->listOfPlants.end() && good; ++it)
	{
		if (it->getCodeName() == codeNameToRemove)
			good = false;
	}
	if (good == false)
		--it;
	*/
	Plant removedPlant;
	if (iteratorPlant != this->listOfPlants.end())
	{
		removedPlant = *iteratorPlant;
		this->listOfPlants.erase(iteratorPlant);
	}
	else
	{
		throw RepositoryException("Invalid code name, plant cluster doesn't exists!");
	}
	return removedPlant;
}

vector<Plant> PlantRepositoryMemory::listofPlantsBySpecies(const string & species)
{
	vector<Plant> vectorToReturn (this->listOfPlants.size());
	if (species == "")
	{
		//vectorToReturn = this->listOfPlants;
		copy(this->listOfPlants.begin(), this->listOfPlants.end(), vectorToReturn.begin());
	}
	else
	{
		auto iteratorPlant = copy_if(this->listOfPlants.begin(), this->listOfPlants.end(), vectorToReturn.begin(), [species](Plant& plant) {return species == plant.getSpecies(); });
		vectorToReturn.resize(distance(vectorToReturn.begin(), iteratorPlant));
	}
	/*
	for (int i = 0; i < this->listOfPlants.getSize(); ++i)
	{
		if ((!(this->listOfPlants[i].getSpecies() == species)) != (!(species == "")))
		{
			vectorToReturn.add(this->listOfPlants[i]);
		}
	}
	*/
	return vectorToReturn;
}

int PlantRepositoryMemory::getNumberOfPlants()
{
	return this->listOfPlants.size();
}

Plant PlantRepositoryMemory::getElementByIndex(int index)
{
	if (listOfPlants.size() == 0)
		return Plant{};
	if (index >= (int)listOfPlants.size() || index < 0)
		throw RepositoryException("Invalid index!");

	return listOfPlants[index];
}

vector<Plant> PlantRepositoryMemory::listAllElements()
{
	vector<Plant> elementsToPrint(this->listOfPlants.size());
	copy(this->listOfPlants.begin(), this->listOfPlants.end(), elementsToPrint.begin());
	return elementsToPrint;
}

void PlantRepositoryMemory::setFile(string newFileName)
{
}

void PlantRepositoryMemory::createFile(string newFilename)
{
}

