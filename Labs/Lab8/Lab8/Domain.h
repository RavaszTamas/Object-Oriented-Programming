#pragma once
#include <iostream>
#include <vector>
#include <string>

/*
Plant object
codeName - string, unique representing the cluster
species -string
ageInmonths - integer
digitizedScan - string
*/

class Command
{
private:
	std::string type;
	std::vector<std::string> parameters;
public:
	std::string getType() const;
	std::vector<std::string> getParameters() const;
};

class Plant
{

private:
	std::string codeName;
	std::string species;
	int ageInMonths;
	std::string digitizedScan;
public:

	/*
	Constructor for the plant object
	*/
	Plant(std::string newCodeName, std::string newSpecies, int newAgeInMonths, std::string newDigitizedScan);
	/*
	Assignment constructor for the plant object
	*/

	Plant& operator=(const Plant& copyPlant);

	bool operator==(const Plant & plantToCheck) const;

	/*
	Default constructor for the plant object
	*/
	Plant();
	std::string getCodeName() const;
	std::string getSpecies() const;
	int getAgeInMonths() const;
	std::string getDigitizedScan() const;

	friend std::istream & operator>>(std::istream & stream, Plant & plant);
	friend std::ostream & operator<<(std::ostream & stream, const Plant & plant);


	std::string toString();

	void setCodeName(std::string newCodeName);
	void setSpecies(std::string newSpecies);
	void setAgeInMonths(int newAgeInMonths);
	void setDigitizedScan(std::string newDigitizedScan);
	//bool Plant::operator==(Plant plantToCheck);

};
