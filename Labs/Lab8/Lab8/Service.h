#pragma once
#include "Repository.h"
#include "TextFileRepo.h"
#include "Validator.h"
#include "FileManagersMyList.h"

class AppController
{
private:
	PlantFileRepository& repositoryOfPlants;
	Validator& validator;
	string mode = "";
	int currentIndexForNextFunctionality = -1;
	//vector<string> listOfChosenPlantClusters;
	FileManagerMyList* fileMyListManager = nullptr;

public:
	//AppController operator=(AppController& copyController);
	//AppController(AppController& copyController);
	AppController(PlantFileRepository& plantRepository, Validator& validator);

	
	//Sets the mode the given modeToSet, if the mode is not valid an exception is thrown using the validator
	void SetMode(string& modeToSet);

	/*
	Adds a new plant to the plant repository.
	*/
	void AddNewPlant(string& newCodeName, string& newSpecies, int newAgeInMonths, string& newDigitizedScan);
	/*
	Updates a  plant int the plant repository  by creatinga new plant using the parameters
	*/
	void UpdatePlant(string& newCodeName, string& newSpecies, int newAgeInMonths, string& newDigitizedScan);
	/*
	Deletes a  plant int the plant repository by it's code name.
	*/
	void DeletePlant(string& codeNameToDeleteBy);
	/*
	Saves the curretly chosen plant to the Uproot list, if the string is empty it adds the current plant after using the next command.
	*/
	void saveToUprootList(string& codeNameToAddBy);
	/*
	Gets the current plant which was displayed by the next command.
	*/
	const Plant& getCurrentPlantByNext();
	/*
	Retruns a list representing the saved, for uprooting plant clusters as a copy.
	*/
	vector<Plant> displayChosenPlantClusters();
	/*
	Returns a list representing all the plant clusters as a copy, by filtering with species and age. If the species is an empty string
	it returns only filtering by age. The filtering by age means that, they all have a smaller age than that integer. if the integer is negative it throws an exception.
	*/
	vector<Plant> displayPlantClutersByAgeAndSpecies(string& species, int ageInMonths);
	/*
	Returns a list representing all the plant clusters as a copy.
	*/
	/*
	Set's the file which would used for further functionalities
	*/
	void ApplyFileLocation(string& filename);

	void ApplyMyListLocation(string& filename);

	vector<Plant> listAll();

	void createFile(std::string filename);

	~AppController();

};
