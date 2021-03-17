#pragma once
#include "Repository.h"

class PlantFileRepository : public PlantRepository
{
protected:
	string filename;
	void readFromFile();

	void saveToFile();


public:
	PlantFileRepository();

	/*
	Stores a new Plant in the list, stores the new data in a file if the plant with the code name already exists
	it throws an expcetion;
	*/
	void storeNewPlant(Plant& newPlantToStore)override;
	/*
	Updates a Plant in the list, stores the new data in a file if the plant with the code name is not found
	it throws an expcetion;
	*/
	void updatePlant(const Plant& plantToUpdateWith) override;
	/*
	Removes a Plant from the list, stores the new data in a file if the plant with the code name is not found
	it throws an expcetion;
	*/
	void removePlant(string& codeNameToRemove) override;
	/*
	Sets the new file location, the data will be read and evaluated/from/to here.
	*/
	virtual void setFile(string newFileName);
	/*
	Creates a new file and also sets the file location to this
	*/
	virtual void createFile(string newFilename);

};

class FakePlantRepository :public PlantFileRepository
{
	int findIndexOfElement(string codeNameToFind) override;
	/*
	Stores a new Plant in the list, if the plant with the code name already exists
	it throws an expcetion;
	*/
	void storeNewPlant(Plant& newPlantToStore) override;
	/*
	Updates a Plant in the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	void updatePlant(const Plant& plantToUpdateWith) override;
	/*
	Removes a Plant from the list, if the plant with the code name is not found
	it throws an expcetion;
	*/
	void removePlant(string& codeNameToRemove) override;
	/*
	Returns a dynamic vector containing the elements int the list
	*/

	vector<Plant> listofPlantsBySpecies(const string& species) override;
	/*
	Retruns an integers representing the number of plants in the repository
	*/
	int getNumberOfPlants() override;
	/*
	Returns a reference to the plant by it's index in the list of plants. If the index is invalid it throws an exception.
	*/
	Plant& getElementByIndex(int index) override;
	/*
	Returns a reference to the dynamic vector of the list of plants.
	*/
	vector<Plant> listAllElements() override;

	void setFile(string newFileName) override;
	/*
	Creates a new file and also sets the file location to this
	*/
	void createFile(string newFilename) override;

};