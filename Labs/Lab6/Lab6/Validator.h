#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Validator
{
	vector<string> modes = { "A" , "B" };
public:
	/*
	Returns true if the integer is has a non-negative value
	*/
	bool ValidateInteger(int integerToValidate);
	/*
	Returns true if the given string is in the vector of modes
	*/
	bool ValidateMode(string& modeToCheck);
};