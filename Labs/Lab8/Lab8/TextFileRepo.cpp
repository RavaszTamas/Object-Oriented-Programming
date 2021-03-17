#include "TextFileRepo.h"
#include <fstream>
#include "myexceptions.h"

using namespace std;

PlantFileRepository::PlantFileRepository() : PlantRepository{}
{

}

void PlantFileRepository::storeNewPlant(Plant & newPlantToStore)
{
	if (this->filename == "")
		throw RepositoryException("No filename");
	PlantRepository::storeNewPlant(newPlantToStore);
	this->saveToFile();
}

void PlantFileRepository::updatePlant(const Plant & plantToUpdateWith)
{
	if (this->filename == "")
		throw RepositoryException("No filename");

	PlantRepository::updatePlant(plantToUpdateWith);
	this->saveToFile();

}

void PlantFileRepository::removePlant(string & codeNameToRemove)
{
	if (this->filename == "")
		throw RepositoryException("No filename");

	PlantRepository::removePlant(codeNameToRemove);
	this->saveToFile();

}



void PlantFileRepository::setFile(string newFileName)
{
	this->filename = newFileName;
	this->readFromFile();
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

void PlantFileRepository::readFromFile()
{
	this->listOfPlants.clear();

	ifstream inputFile{ this->filename };
	if (inputFile.fail())
		throw RepositoryException("Invalid file");

	Plant auxilliaryPlant;


	while(!inputFile.eof())
	{

		inputFile >> auxilliaryPlant;
		if(auxilliaryPlant.getCodeName() != "")
		PlantRepository::storeNewPlant(auxilliaryPlant);
		auxilliaryPlant.setCodeName("");
	}
	inputFile.close();
}

void PlantFileRepository::saveToFile()
{
	ofstream outputfile{ this->filename };
	if (outputfile.fail())
		throw RepositoryException("Can't create the file");
	for (auto iteratorPlant : this->listOfPlants)
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

void FakePlantRepository::removePlant(string & codeNameToRemove)
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
