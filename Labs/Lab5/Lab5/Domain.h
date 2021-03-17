#pragma once
#include <iostream>
using namespace std;
/*
Plant object
codeName - string, unique representing the cluster
species -string
ageInmonths - integer
digitizedScan - string
*/
class Plant
{
private:
	string codeName;
	string species;
	int ageInMonths;
	string digitizedScan;
public:
	/*
	Constructor for the plant object
	*/
	Plant(string newCodeName, string newSpecies, int newAgeInMonths, string newDigitizedScan);
	/*
	Assignment constructor for the plant object
	*/
	Plant& operator=(Plant& copyPlant);
	/*
	Default constructor for the plant object
	*/
	Plant();
	string& getCodeName();
	string& getSpecies();
	int getAgeInMonths();
	string& getDigitizedScan();

	void setCodeName(string newCodeName);
	void setSpecies(string newSpecies);
	void setAgeInMonths(int newAgeInMonths);
	void setDigitizedScan(string newDigitizedScan);

};