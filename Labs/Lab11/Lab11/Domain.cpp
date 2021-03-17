#include "Domain.h"
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

Plant::Plant(string newCodeName, string newSpecies, int newAgeInMonths, string newDigitizedScan)
{
	this->codeName = newCodeName;
	this->species = newSpecies;
	this->ageInMonths = newAgeInMonths;
	this->digitizedScan = newDigitizedScan;
}

Plant & Plant::operator=(const Plant & copyPlant)
{
	this->codeName = copyPlant.getCodeName();
	this->species = copyPlant.getSpecies();
	this->ageInMonths = copyPlant.getAgeInMonths();
	this->digitizedScan = copyPlant.getDigitizedScan();
	return *this;
}

bool Plant::operator==(const Plant & plantToCheck) const
{
	return this->codeName == plantToCheck.codeName;

}

Plant::Plant()
{
	this->codeName = "";
	this->species = "";
	this->ageInMonths = 0;
	this->digitizedScan = "";

}

string Plant::getCodeName() const
{
	return this->codeName;
}

string Plant::getSpecies() const
{
	return this->species;
}

int Plant::getAgeInMonths() const
{
	return this->ageInMonths;
}

string Plant::getDigitizedScan() const 
{
	return this->digitizedScan;
}

string Plant::toString()
{
	stringstream buffer;
	buffer << this->codeName << " " << this->species << " " << this->ageInMonths << " " << this->digitizedScan;
	return buffer.str();

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

istream & operator>>(istream & stream, Plant & plant)
{
	stream >> plant.codeName >> plant.species >> plant.ageInMonths >> plant.digitizedScan;
	return stream;
	// TODO: insert return statement here
}

ostream & operator<<(ostream & stream, const Plant & plant)
{
	stream << plant.codeName << " " << plant.species << " " << plant.ageInMonths << " " << plant.digitizedScan;
	return stream;
}

std::string Command::getType() const
{
	return this->type;
}

std::vector<std::string> Command::getParameters() const
{
	return std::vector<std::string>();
}
