#include "Service.h"
#include <algorithm>
#include <iterator>
#include "myexceptions.h"
#include "Utilities.h"
#include <fstream>

void AppController::AddNewPlant(const string & newCodeName, const string & newSpecies, const int newAgeInMonths, const string & newDigitizedScan)
{
	if (this->mode != "A")
		throw ServiceException("Invalid mode, no permission!");
	this->validator.ValidateInteger(newAgeInMonths);
	Plant plantToStore(newCodeName, newSpecies, newAgeInMonths, newDigitizedScan);
	this->repositoryOfPlants.storeNewPlant(plantToStore);
	undoRedoStackIndex++;
	this->undoList.erase(this->undoList.begin() + undoRedoStackIndex, this->undoList.end());
	this->undoList.push_back(make_unique<UndoAdd>(plantToStore, this->repositoryOfPlants));
}

void AppController::UpdatePlant(const string & newCodeName, const string & newSpecies, const int newAgeInMonths, const string & newDigitizedScan)
{
	if (this->mode != "A")
		throw ServiceException("Invalid mode, no permission!");
	this->validator.ValidateInteger(newAgeInMonths);
	Plant plantToUpdateWith(newCodeName, newSpecies, newAgeInMonths, newDigitizedScan);

	Plant oldPlant = this->repositoryOfPlants.updatePlant(plantToUpdateWith);
	undoRedoStackIndex++;
	this->undoList.erase(this->undoList.begin() + undoRedoStackIndex, this->undoList.end());
	this->undoList.push_back(make_unique<UndoUpdate>(oldPlant,plantToUpdateWith, this->repositoryOfPlants));

}

void AppController::DeletePlant(const string & codeNameToDeleteBy)
{
	if (this->mode != "A")
		throw ServiceException("Invalid mode, no permission!\n");

	Plant removedPlant = this->repositoryOfPlants.removePlant(codeNameToDeleteBy);
	undoRedoStackIndex++;
	this->undoList.erase(this->undoList.begin() + undoRedoStackIndex, this->undoList.end());
	this->undoList.push_back(make_unique<UndoRemove>(removedPlant, this->repositoryOfPlants));

}

void AppController::saveToUprootList(const string & codeNameToAddBy)
{
	if (this->mode != "B")
		throw ServiceException("Invalid mode!");

	if(this->fileMyListManager == nullptr)
		throw ServiceException("No list file set!");

	/*
	if (codeNameToAddBy == "")
	{
		//(this->listOfChosenPlantClusters.find((this->repositoryOfPlants.getElementByIndex(currentIndexForNextFunctionality)).getCodeName()) != -1)
		
		if (find(this->listOfChosenPlantClusters.begin(),this->listOfChosenPlantClusters.end(),this->repositoryOfPlants.getElementByIndex(currentIndexForNextFunctionality).getCodeName()) != this->listOfChosenPlantClusters.end())
			throw ServiceException("Element already in the list\n");

		this->listOfChosenPlantClusters.push_back((this->repositoryOfPlants.getElementByIndex(currentIndexForNextFunctionality)).getCodeName());
	}
	else
	{*/
	/*if(find(this->listOfChosenPlantClusters.begin(),this->listOfChosenPlantClusters.end(),codeNameToAddBy) != this->listOfChosenPlantClusters.end())//this->listOfChosenPlantClusters.find(codeNameToAddBy) != -1)
		throw ServiceException("Element already in the list!\n");
	*/

	int indexToAdd = this->repositoryOfPlants.findIndexOfElement(codeNameToAddBy);

	if(indexToAdd == -1)
		throw ServiceException("Invalid code name!");

	Plant planttosave = this->repositoryOfPlants.getElementByIndex(indexToAdd);
	this->fileMyListManager->saveToFile(planttosave);

	undoRedoStackIndexUproot++;
	this->undoListUproot.erase(this->undoListUproot.begin() + undoRedoStackIndexUproot, this->undoListUproot.end());
	this->undoListUproot.push_back(make_unique<UndoAddUproot>(planttosave, this->fileMyListManager));
	//this->listOfChosenPlantClusters.push_back(codeNameToAddBy);
	//}
	
}

const Plant AppController::getCurrentPlantByNext()
{
	//if (this->mode != "B")
		//throw ServiceException("Invalid mode, no permission!");

	if (this->fileMyListManager == nullptr)
		throw ServiceException("No list file set!");

	++currentIndexForNextFunctionality;
	
	if (currentIndexForNextFunctionality == this->repositoryOfPlants.getNumberOfPlants())
	{
		currentIndexForNextFunctionality = 0;
	}

	const Plant returnElement = repositoryOfPlants.getElementByIndex(currentIndexForNextFunctionality);
	return returnElement;
	

}

void AppController::displayChosenPlantClusters()
{
	//if (this->mode != "B")
		//throw ServiceException("Invalid mode, no permission!");

	if (this->fileMyListManager == nullptr)
		throw ServiceException("No list file set!");

	this->fileMyListManager->openFile();

	/*
	vector<Plant> vectorToReturn;
	
	for (auto it = this->listOfChosenPlantClusters.begin(); it != this->listOfChosenPlantClusters.end(); it++)
	{
		vectorToReturn.push_back(this->repositoryOfPlants.getElementByIndex(this->repositoryOfPlants.findIndexOfElement(*it)));
	}
	
	vectorToReturn = this->fileMyListManager->readFile();

	return vectorToReturn;
	*/
	//return this->fileMyListManager->readFile();
}

vector<Plant> AppController::displayPlantClutersByAgeAndSpecies(const string & species, const int ageInMonths)
{
	//if (this->mode != "B")
		//throw ServiceException("Invalid mode, no permission!");

	if (ageInMonths <= 0)
		throw ServiceException("Invalid age!");
	vector<Plant> vectorToReturn = this->repositoryOfPlants.listofPlantsBySpecies(species);


	auto end = remove_if(vectorToReturn.begin(), vectorToReturn.end(), [ageInMonths](Plant& plant) {return plant.getAgeInMonths() >= ageInMonths; });

	vectorToReturn.resize(distance(vectorToReturn.begin(), end));

	return vectorToReturn;
}

void AppController::ApplyFileLocation(string & filename)
{
	try {
		this->validator.ValidateFile(filename);
		this->repositoryOfPlants.setFile(filename);
	}
	catch (ValidationException&)
	{
		this->repositoryOfPlants.createFile(filename);
	}
}

void AppController::ApplyMyListLocation(string & filename)
{

	if (this->fileMyListManager != nullptr)
		throw ServiceException("Invalid command! File can't be changed after set!");

	if (filename == "")
	{
		this->fileMyListManager = new MemoryMyList{ filename };
		return;
	}
	try {
		this->validator.ValidateFile(filename);

		string extention = getExtention(filename);

		if (extention == "csv")
			this->fileMyListManager = new CsvFileManagerMyList{ filename };
		else if (extention == "html")
			this->fileMyListManager = new HTMLFileManagerMyList{ filename };
		else
			throw ServiceException("Invalid format for file myList!");

	}
	catch (ValidationException&)
	{

		this->createFile(filename);

		string extention = getExtention(filename);

		if (extention == "csv")
			this->fileMyListManager = new CsvFileManagerMyList{ filename };
		else if (extention == "html")
			this->fileMyListManager = new HTMLFileManagerMyList{ filename };
		else
			throw ServiceException("Invalid format for file myList!");

	}


}

vector<Plant> AppController::listAll()
{
	//if (this->mode != "A")
		//throw ServiceException("Invalid mode, no permission!");
	return this->repositoryOfPlants.listAllElements();
}

vector<Plant> AppController::listAllUprootPlants()
{
	//if (this->mode != "A")
		//throw ServiceException("Invalid mode, no permission!");
	return this->fileMyListManager->readFile();
}


void AppController::createFile(std::string filename)
{
	ofstream file{ filename };
	file.close();
}

void AppController::undoAction()
{
	if (this->undoRedoStackIndex == -1)
		throw ServiceException("No more possible undos!");
	this->undoList[this->undoRedoStackIndex]->executeUndo();
	--undoRedoStackIndex;
}

void AppController::redoAction()
{
	if (this->undoRedoStackIndex == this->undoList.size()-1)
		throw ServiceException("No more possible redos!");
	this->undoList[this->undoRedoStackIndex+1]->executeRedo();
	++undoRedoStackIndex;
}

void AppController::undoActionUprootList()
{
	if (this->undoRedoStackIndexUproot == -1)
		throw ServiceException("No more possible undos!");
	this->undoListUproot[this->undoRedoStackIndexUproot]->executeUndo();
	--undoRedoStackIndexUproot;

}

void AppController::redoActionUprootList()
{
	if (this->undoRedoStackIndexUproot == this->undoListUproot.size() - 1)
		throw ServiceException("No more possible redos!");
	this->undoListUproot[this->undoRedoStackIndexUproot + 1]->executeRedo();
	++undoRedoStackIndexUproot;
}


AppController::~AppController()
{
	if (this->fileMyListManager != nullptr)
		delete this->fileMyListManager;
}


AppController::AppController(PlantRepository & plantRepository,Validator& validator):repositoryOfPlants(plantRepository),validator(validator)
{
}

void AppController::SetMode(string & modeToSet)
{
	this->validator.ValidateMode(modeToSet);
	
	this->mode = modeToSet;
	this->currentIndexForNextFunctionality = -1;
	//this->listOfChosenPlantClusters.empty();
	return;
}

