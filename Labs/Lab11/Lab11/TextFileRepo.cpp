#include "TextFileRepo.h"
#include <fstream>
#include "myexceptions.h"
#include <algorithm>

using namespace std;

string PlantFileRepository::getType()
{
	return string("textfile");
}


PlantFileRepository::PlantFileRepository() : PlantRepository{}
{

}

void PlantFileRepository::storeNewPlant(Plant & newPlantToStore)
{
	if (this->filename == "")
		throw RepositoryException("No filename");

	vector<Plant> plants = this->readFromFile();

	if (this->findIndexOfElement(newPlantToStore.getCodeName()) == -1)
	{
		plants.push_back(newPlantToStore);
	}
	else
	{
		throw RepositoryException("Invalid code name, plant cluster already exists!");
	}

	this->saveToFile(plants);
}

Plant PlantFileRepository::updatePlant(const Plant & plantToUpdateWith)
{
	if (this->filename == "")
		throw RepositoryException("No filename");

	string codename = plantToUpdateWith.getCodeName();
	vector<Plant> plants = this->readFromFile();

	auto iteratorPlant = find_if(plants.begin(), plants.end(), [plantToUpdateWith](Plant& plant) {return plant == plantToUpdateWith; });
	Plant oldPlant;
	if (iteratorPlant != plants.end())
	{
		oldPlant = plants.at(distance(plants.begin(), iteratorPlant));
		plants.at(distance(plants.begin(), iteratorPlant)) = plantToUpdateWith;
		//this->listOfPlants.update(indexToUpdate, plantToUpdateWith);
	}
	else
	{
		throw RepositoryException("Invalid code name, plant cluster doesn't exists!");
	}


	this->saveToFile(plants);
	return oldPlant;
}

Plant PlantFileRepository::removePlant(const string & codeNameToRemove)
{
	if (this->filename == "")
		throw RepositoryException("No filename");

	vector<Plant> plants = this->readFromFile();

	auto iteratorPlant = find_if(plants.begin(), plants.end(), [codeNameToRemove](Plant& plant) {return plant.getCodeName() == codeNameToRemove; });
	Plant removedPlant;
	if (iteratorPlant != plants.end())
	{
		removedPlant = *iteratorPlant;

		plants.erase(iteratorPlant);
	}
	else
	{
		throw RepositoryException("Invalid code name, plant cluster doesn't exists!");
	}

	this->saveToFile(plants);
	return removedPlant;
}



void PlantFileRepository::setFile(string newFileName)
{
	this->filename = newFileName;
	//this->readFromFile();
}

void PlantFileRepository::createFile(string newFilename)
{
	ofstream outputfile{ newFilename };
	outputfile.close();
	ofstream outputfileAgain{ newFilename };
	if (outputfileAgain.fail())
		throw RepositoryException("File can't be created!");
	this->filename = newFilename;
	outputfileAgain.close();

}

int PlantFileRepository::findIndexOfElement(string codeNameToFind)
{
	vector<Plant> plants = this->readFromFile();
	int indexToReturn = 0;
	for (auto iteratorPlant = plants.begin(); iteratorPlant != plants.end(); ++iteratorPlant)
	{
		if (codeNameToFind == iteratorPlant->getCodeName())
			return indexToReturn;
		indexToReturn++;
	}
	return -1;

}

vector<Plant> PlantFileRepository::listofPlantsBySpecies(const string & species)
{
	vector<Plant> plants = this->readFromFile();

	vector<Plant> vectorToReturn(plants.size());
	if (species == "")
	{
		//vectorToReturn = this->listOfPlants;
		copy(plants.begin(), plants.end(), vectorToReturn.begin());
	}
	else
	{
		auto iteratorPlant = copy_if(plants.begin(), plants.end(), vectorToReturn.begin(), [species](Plant& plant) {return species == plant.getSpecies(); });
		vectorToReturn.resize(distance(vectorToReturn.begin(), iteratorPlant));
	}
	return vectorToReturn;
}

int PlantFileRepository::getNumberOfPlants()
{
	return this->readFromFile().size();
}

Plant PlantFileRepository::getElementByIndex(int index)
{
	vector<Plant> plants = this->readFromFile();
	if (plants.size() == 0)
		return Plant{};

	if (index >= (int)plants.size() || index < 0)
		throw RepositoryException("Invalid index!");
	return plants[index];
}

vector<Plant> PlantFileRepository::listAllElements()
{
	vector<Plant> plants = this->readFromFile();

	vector<Plant> elementsToPrint(plants.size());
	copy(plants.begin(), plants.end(), elementsToPrint.begin());
	return elementsToPrint;
}

vector<Plant> PlantFileRepository::readFromFile()
{

	ifstream inputFile{ this->filename };
	if (inputFile.fail())
		throw RepositoryException("Invalid file");

	vector<Plant> Plants;


	Plant auxilliaryPlant;


	while(!inputFile.eof())
	{

		inputFile >> auxilliaryPlant;
		if (auxilliaryPlant.getCodeName() != "")
		{
			Plants.push_back(auxilliaryPlant);
		}

		auxilliaryPlant.setCodeName("");
	}
	inputFile.close();

	return Plants;
}

void PlantFileRepository::saveToFile(vector<Plant> plants)
{
	ofstream outputfile{ this->filename };
	if (outputfile.fail())
		throw RepositoryException("Can't create the file");
	for (auto iteratorPlant : plants)
	{
		outputfile << iteratorPlant << endl;
	}
	/*
	auto it = this->listOfPlants.begin();

	for (; it != this->listOfPlants.end()-1; ++it)
		outputfile << *it << endl;
	outputfile << *it;
	*/
	outputfile.close();
}


/*

int FakePlantRepository::findIndexOfElement(string codeNameToFind)
{
	return PlantRepository::findIndexOfElement(codeNameToFind);
}

void FakePlantRepository::storeNewPlant(Plant & newPlantToStore)
{
	PlantRepository::storeNewPlant(newPlantToStore);
}

void FakePlantRepository::updatePlant(const Plant & plantToUpdateWith)
{
	PlantRepository::updatePlant(plantToUpdateWith);
}

void FakePlantRepository::removePlant(const string & codeNameToRemove)
{
	PlantRepository::removePlant(codeNameToRemove);
}

vector<Plant> FakePlantRepository::listofPlantsBySpecies(const string & species)
{
	return PlantRepository::listofPlantsBySpecies(species);
}

int FakePlantRepository::getNumberOfPlants()
{
	return PlantRepository::getNumberOfPlants();
}

Plant & FakePlantRepository::getElementByIndex(int index)
{
	return PlantRepository::getElementByIndex(index);
	// TODO: insert return statement here
}

vector<Plant> FakePlantRepository::listAllElements()
{
	return PlantRepository::listAllElements();
}

void FakePlantRepository::setFile(string newFileName)
{
	this->filename = newFileName;
}

void FakePlantRepository::createFile(string newFilename)
{
	
}
*/