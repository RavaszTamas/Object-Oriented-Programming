#pragma once
#include "Repository.h"
#include "Validator.h"

class AppController
{
private:
	PlantRepository& repositoryOfPlants;
	Validator& validator;
	string mode = "";
public:
	AppController operator=(AppController& copyController);
	//AppController(AppController& copyController);
	AppController(PlantRepository& plantRepository, Validator& validator);

	
	//Sets the mode the given modeToSet, if the mode is not valid an exception is thrown using the validator
	void SetMode(string& modeToSet);

	/*

	*/
	void AddNewPlant(string& newCodeName, string& newSpecies, int newAgeInMonths, string& newDigitizedScan);

	void UpdatePlant(string& newCodeName, string& newSpecies, int newAgeInMonths, string& newDigitizedScan);

	void DeletePlant(string& codeNameToDeleteBy);

	DynamicVector<Plant>& listAll();

};
