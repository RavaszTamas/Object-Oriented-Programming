#pragma once
#include "Domain.h"
#include <vector>
#include "FileManagersMyList.h"


using namespace std;

class PlantRepository
{
protected:
	virtual vector<Plant> readFromFile() =0;

	virtual void saveToFile(vector<Plant>) = 0;


public:

	virtual string getType() = 0;

	virtual int findIndexOfElement(string codeNameToFind) = 0;
	/*
	Stores a new Plant in the list, if the plant with the code name already exists
	it throws an expcetion;
	*/
	virtual void storeNewPlant(Plant& newPlantToStore) = 0;
	/*
	Updates a Plant in the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	virtual Plant updatePlant(const Plant& plantToUpdateWith) = 0;
	/*
	Removes a Plant from the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	virtual Plant removePlant(const string& codeNameToRemove) = 0;
	/*
	Returns a dynamic vector containing the elements int the list
	*/

	virtual vector<Plant> listofPlantsBySpecies(const string& species) = 0;
	/*
	Retruns an integers representing the number of plants in the repository
	*/
	virtual int getNumberOfPlants() = 0;
	/*
	Returns a reference to the plant by it's index in the list of plants. If the index is invalid it throws an exception.
	*/
	virtual Plant getElementByIndex(int index) = 0;
	/*
	Returns a reference to the dynamic vector of the list of plants.
	*/
	virtual vector<Plant> listAllElements() = 0;
	/*
	Sets the new file location, the data will be read and evaluated/from/to here.
	*/
	virtual void setFile(string newFileName) = 0;
	/*
	Creates a new file and also sets the file location to this
	*/
	virtual void createFile(string newFilename) = 0;


};

class PlantRepositoryMemory: public PlantRepository
{
private:
	vector<Plant> listOfPlants;
	virtual vector<Plant> readFromFile() override;

	virtual void saveToFile(vector<Plant>) override;

public:
	
	virtual string getType() override;


	PlantRepositoryMemory();
	/*
	Returns the position of the element int the list. If it is not found it returns -1;
	*/
	virtual int findIndexOfElement(string codeNameToFind) override;
	/*
	Stores a new Plant in the list, if the plant with the code name already exists 
	it throws an expcetion;
	*/
	virtual void storeNewPlant(Plant& newPlantToStore) override;
	/*
	Updates a Plant in the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	virtual Plant updatePlant(const Plant& plantToUpdateWith) override;
	/*
	Removes a Plant from the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	virtual Plant removePlant(const string& codeNameToRemove) override;
	/*
	Returns a dynamic vector containing the elements int the list
	*/

	virtual vector<Plant> listofPlantsBySpecies(const string& species) override;
	/*
	Retruns an integers representing the number of plants in the repository
	*/
	virtual int getNumberOfPlants() override;
	/*
	Returns a reference to the plant by it's index in the list of plants. If the index is invalid it throws an exception.
	*/
	virtual Plant getElementByIndex(int index) override;
	/*
	Returns a reference to the dynamic vector of the list of plants.
	*/
	virtual vector<Plant> listAllElements() override;

	/*
	Sets the new file location, the data will be read and evaluated/from/to here.
	*/
	virtual void setFile(string newFileName) override;
	/*
	Creates a new file and also sets the file location to this
	*/
	virtual void createFile(string newFilename) override;

};

