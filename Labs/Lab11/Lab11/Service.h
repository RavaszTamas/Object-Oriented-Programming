#pragma once
#include "Repository.h"
#include "TextFileRepo.h"
#include "Validator.h"
#include "FileManagersMyList.h"
#include <memory>
#include "Undo.h"

class AppController
{
private:
	PlantRepository& repositoryOfPlants;
	Validator& validator;
	string mode = "";
	int currentIndexForNextFunctionality = -1;
	//vector<string> listOfChosenPlantClusters;

	std::vector<std::unique_ptr<UndoAction>> undoList;
	std::vector<std::unique_ptr<UndoAction>> undoListUproot;

	int undoRedoStackIndex = -1;
	int undoRedoStackIndexUproot = -1;

public:
	FileManagerMyList* fileMyListManager = nullptr;

	//AppController operator=(AppController& copyController);
	//AppController(AppController& copyController);
	AppController(PlantRepository& plantRepository, Validator& validator);

	
	//Sets the mode the given modeToSet, if the mode is not valid an exception is thrown using the validator
	void SetMode(string& modeToSet);

	/*
	Adds a new plant to the plant repository.
	*/
	void AddNewPlant(const string& newCodeName, const string& newSpecies, const int newAgeInMonths, const string& newDigitizedScan);
	/*
	Updates a  plant int the plant repository  by creatinga new plant using the parameters
	*/
	void UpdatePlant(const string& newCodeName, const string& newSpecies,const int newAgeInMonths, const string& newDigitizedScan);
	/*
	Deletes a  plant int the plant repository by it's code name.
	*/
	void DeletePlant(const string& codeNameToDeleteBy);
	/*
	Saves the curretly chosen plant to the Uproot list, if the string is empty it adds the current plant after using the next command.
	*/
	void saveToUprootList(const string& codeNameToAddBy);
	/*
	Gets the current plant which was displayed by the next command.
	*/
	const Plant getCurrentPlantByNext();
	/*
	Retruns a list representing the saved, for uprooting plant clusters as a copy.
	*/
	void displayChosenPlantClusters();
	/*
	Returns a list representing all the plant clusters as a copy, by filtering with species and age. If the species is an empty string
	it returns only filtering by age. The filtering by age means that, they all have a smaller age than that integer. if the integer is negative it throws an exception.
	*/
	vector<Plant> displayPlantClutersByAgeAndSpecies(const string& species, const int ageInMonths);
	/*
	Returns a list representing all the plant clusters as a copy.
	*/
	/*
	Set's the file which would used for further functionalities
	*/
	void ApplyFileLocation(string& filename);

	void ApplyMyListLocation(string& filename);

	vector<Plant> listAll();

	vector<Plant> listAllUprootPlants();

	void createFile(std::string filename);

	void undoAction();

	void redoAction();

	void redoActionUprootList();

	void undoActionUprootList();

	~AppController();

};
