#include "Domain.h"

Plant::Plant(string newCodeName, string newSpecies, int newAgeInMonths, string newDigitizedScan)
{
	this->codeName = newCodeName;
	this->species = newSpecies;
	this->ageInMonths = newAgeInMonths;
	this->digitizedScan = newDigitizedScan;
}

Plant & Plant::operator=(Plant & copyPlant)
{
	this->codeName = copyPlant.getCodeName();
	this->species = copyPlant.getSpecies();
	this->ageInMonths = copyPlant.getAgeInMonths();
	this->digitizedScan = copyPlant.getDigitizedScan();
	return *this;
}

Plant::Plant()
{
	this->codeName = "";
	this->species = "";
	this->ageInMonths = 0;
	this->digitizedScan = "";

}

string& Plant::getCodeName()
{
	return this->codeName;
}

string& Plant::getSpecies()
{
	return this->species;
}

int Plant::getAgeInMonths()
{
	return this->ageInMonths;
}

string& Plant::getDigitizedScan()
{
	return this->digitizedScan;
}

void Plant::setCodeName(string newCodeName)
{
	this->codeName = newCodeName;
}

void Plant::setSpecies(string newSpecies)
{
	this->species = newSpecies;
}

void Plant::setAgeInMonths(int newAgeInMonths)
{
	this->ageInMonths = newAgeInMonths;
}

void Plant::setDigitizedScan(string newDigitizedScan)
{
	this->digitizedScan = newDigitizedScan;
}

/*bool Plant::operator==(Plant plantToCheck)
{
	return this->codeName == plantToCheck.getCodeName();
}*/
