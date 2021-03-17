#pragma once
#include "DynamicArray.h"
#include "Domain.h"
using namespace std;

class PlantRepository
{
private:
	DynamicVector<Plant> listOfPlants;
public:
	
	PlantRepository& operator=(PlantRepository& copyRepository);
	PlantRepository(PlantRepository& copyRepository);
	PlantRepository();
	/*
	Returns the position of the element int the list. If it is not found it returns -1;
	*/
	int findIndexOfElement(string& codeNameToFind);
	/*
	Stores a new Plant in the list, if the plant with the code name already exists 
	it throws an expcetion;
	*/
	void storeNewPlant(Plant& newPlantToStore);
	/*
	Updates a Plant in the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	void updatePlant(Plant& plantToUpdateWith);
	/*
	Removes a Plant from the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	void removePlant(string& codeNameToRemove);
	/*
	Returns a dynamic vector containing the elements int the list
	*/

	DynamicVector<Plant> listofPlantsBySpecies(const string& species);
	/*
	Retruns an integers representing the number of plants in the repository
	*/
	int getNumberOfPlants();
	/*
	Returns a reference to the plant by it's index in the list of plants. If the index is invalid it throws an exception.
	*/
	Plant& getElementByIndex(int index);
	/*
	Returns a reference to the dynamic vector of the list of plants.
	*/
	DynamicVector<Plant>& listAllElements();
};

