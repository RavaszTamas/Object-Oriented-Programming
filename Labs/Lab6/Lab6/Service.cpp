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
		throw "Invalid mode, no permission!\n";

	this->repositoryOfPlants.removePlant(codeNameToDeleteBy);
}

void AppController::saveToUprootList(string & codeNameToAddBy)
{
	if (this->mode != "B")
		throw "Invalid mode!";


	if (codeNameToAddBy == "")
	{
		if (this->listOfChosenPlantClusters.find((this->repositoryOfPlants.getElementByIndex(currentIndexForNextFunctionality)).getCodeName()) != -1)
			throw "Element already in the list\n";

		try 
		{
			this->listOfChosenPlantClusters.add((this->repositoryOfPlants.getElementByIndex(currentIndexForNextFunctionality)).getCodeName());
		}
		catch(const char* exception)
		{
			throw "Invalid element! Next not used!\n";
		}
	}
	else
	{
		if (this->listOfChosenPlantClusters.find(codeNameToAddBy) != -1)
			throw "Element already in the list!\n";


		if (this->repositoryOfPlants.findIndexOfElement(codeNameToAddBy) != -1)
			this->listOfChosenPlantClusters.add(codeNameToAddBy);
		else
			throw "Invalid code name!";
	}
}

const Plant& AppController::getCurrentPlantByNext()
{
	if (this->mode != "B")
		throw "Invalid mode, no permission!\n";
	++currentIndexForNextFunctionality;

	if (currentIndexForNextFunctionality == this->repositoryOfPlants.getNumberOfPlants())
	{
		currentIndexForNextFunctionality = 0;
	}
	try
	{
		const Plant& returnElement = repositoryOfPlants.getElementByIndex(currentIndexForNextFunctionality);
		return returnElement;
	}
	catch (const char* message)
	{
		throw "The list of plants is empty\n";
	}

}

DynamicVector<Plant> AppController::displayChosenPlantClusters()
{
	DynamicVector<Plant> vectorToReturn;
	for (int i = 0; i < this->listOfChosenPlantClusters.getSize(); i++)
	{
		vectorToReturn.add(this->repositoryOfPlants.getElementByIndex(this->repositoryOfPlants.findIndexOfElement(this->listOfChosenPlantClusters[i])));
	}
	return vectorToReturn;
}

DynamicVector<Plant> AppController::displayPlantClutersByAgeAndSpecies(string & species, int ageInMonths)
{
	if (ageInMonths <= 0)
		throw "Invalid age!\n";
	DynamicVector<Plant> vectorToReturn = this->repositoryOfPlants.listofPlantsBySpecies(species);
	for (int i = vectorToReturn.getSize(); i >= 0; --i)
	{
		if (vectorToReturn[i].getAgeInMonths() >= ageInMonths)
			vectorToReturn.remove(i);
	}
	return vectorToReturn;
}

DynamicVector<Plant>& AppController::listAll()
{
	if (this->mode != "A")
		throw "Invalid mode, no permission!\n";
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
		this->currentIndexForNextFunctionality = -1;
		this->listOfChosenPlantClusters.empty();
		return;
	}
	else
	{
		throw "Invalid mode!\n";
	}
}

