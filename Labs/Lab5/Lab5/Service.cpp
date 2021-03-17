#include "Service.h"

void AppController::AddNewPlant(string & newCodeName, string & newSpecies, int newAgeInMonths, string & newDigitizedScan)
{
	if (this->mode != "A")
		throw "Invalid mode, no permission!";
	if (!this->validator.ValidateInteger(newAgeInMonths))
		throw "Invalid input for month!";
	 Plant plantToStore(newCodeName, newSpecies, newAgeInMonths, newDigitizedScan);
	 this->repositoryOfPlants.storeNewPlant(plantToStore);
}

void AppController::UpdatePlant(string & newCodeName, string & newSpecies, int newAgeInMonths, string & newDigitizedScan)
{
	if (this->mode != "A")
		throw "Invalid mode, no permission!";
	if (!this->validator.ValidateInteger(newAgeInMonths))
		throw "Invalid input for month!";
	Plant plantToUpdateWith(newCodeName, newSpecies, newAgeInMonths, newDigitizedScan);
	this->repositoryOfPlants.updatePlant(plantToUpdateWith);

}

void AppController::DeletePlant(string & codeNameToDeleteBy)
{
	if (this->mode != "A")
		throw "Invalid mode, no permission!";

	this->repositoryOfPlants.removePlant(codeNameToDeleteBy);
}

DynamicVector<Plant>& AppController::listAll()
{
	if (this->mode != "A")
		throw "Invalid mode, no permission!";
	return this->repositoryOfPlants.listAllElements();
}

AppController AppController::operator=(AppController & copyController)
{
	//this->repositoryOfPlants = copyController.repositoryOfPlants;
	return *this;
}

/*AppController::AppController(AppController& copyController):AppController(copyController)
{
	//this->repositoryOfPlants = copyController.repositoryOfPlants;
}*/

AppController::AppController(PlantRepository & plantRepository,Validator& validator):repositoryOfPlants(plantRepository),validator(validator)
{
}

void AppController::SetMode(string & modeToSet)
{
	if (this->validator.ValidateMode(modeToSet))
	{
		this->mode = modeToSet;
		return;
	}
	else
	{
		throw "Invalid mode!";
	}
}

