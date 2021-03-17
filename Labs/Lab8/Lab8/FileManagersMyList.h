#pragma once
#include <string>
#include <vector>
#include "Domain.h"

class FileManagerMyList
{
protected:
	std::string filename;
public:
	FileManagerMyList(std::string newFileName);
	/*
	Reads the file and retuns the content of it in a vector of Plants;
	*/
	virtual std::vector<Plant> readFile() = 0;
	/*
	Saves the current element to the list of plants;
	*/
	virtual void saveToFile(Plant elementsToSave) = 0;
	/*
	Opens the file for viewing using a specific application, browser or any specified view application
	*/
	virtual void openFile() = 0;
	virtual ~FileManagerMyList() {};
};

class CsvFileManagerMyList : public FileManagerMyList
{
public:
	CsvFileManagerMyList(std::string newFileName);
	void openFile();
	std::vector<Plant> readFile() override;
	virtual void saveToFile(Plant elementToSave)override;

};

class HTMLFileManagerMyList : public FileManagerMyList
{
private:
	std::string HTMLTableRow(Plant& PlantToConvert);

public:
	HTMLFileManagerMyList(std::string newFileName);
	void openFile();

	std::vector<Plant> readFile() override;
	virtual void saveToFile(Plant elementToSave)override;

};