#pragma once
#include "Domain.h"
#include <vector>


using namespace std;

class PlantRepository
{
protected:
	vector<Plant> listOfPlants;
public:
	
	PlantRepository();
	/*
	Returns the position of the element int the list. If it is not found it returns -1;
	*/
	virtual int findIndexOfElement(string codeNameToFind);
	/*
	Stores a new Plant in the list, if the plant with the code name already exists 
	it throws an expcetion;
	*/
	virtual void storeNewPlant(Plant& newPlantToStore);
	/*
	Updates a Plant in the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	virtual void updatePlant(const Plant& plantToUpdateWith);
	/*
	Removes a Plant from the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	virtual void removePlant(string& codeNameToRemove);
	/*
	Returns a dynamic vector containing the elements int the list
	*/

	virtual vector<Plant> listofPlantsBySpecies(const string& species);
	/*
	Retruns an integers representing the number of plants in the repository
	*/
	virtual int getNumberOfPlants();
	/*
	Returns a reference to the plant by it's index in the list of plants. If the index is invalid it throws an exception.
	*/
	virtual Plant& getElementByIndex(int index);
	/*
	Returns a reference to the dynamic vector of the list of plants.
	*/
	virtual vector<Plant> listAllElements();
};

