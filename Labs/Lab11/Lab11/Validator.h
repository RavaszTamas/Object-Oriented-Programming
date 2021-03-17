#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Validator
{
private:
	vector<string> modes = { "A" , "B" };
public:
	/*
	Throw a validation exception if the integer is negative
	*/
	virtual void ValidateInteger(int integerToValidate);
	/*
	Throw a validation exception if the mode is invalid
	*/
	virtual void ValidateMode(string& modeToCheck);
	/*
	Throw a validation exception if the mode is invalid
	*/
	virtual void ValidateFile(string& filename);
};

class FakeValidator : public Validator
{

};