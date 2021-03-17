#include "Validator.h"
#include <fstream>
#include "myexceptions.h"

void Validator::ValidateInteger(int integerToValidate)
{
	if (integerToValidate < 0)
		throw ValidationException("Invalid integer!");
	return;
}

void Validator::ValidateMode(string & modeToCheck)
{
	for (auto iteratorMode = this->modes.begin(); iteratorMode != this->modes.end(); ++iteratorMode)
	{
		if (*iteratorMode == modeToCheck)
			return;
	}
	throw ValidationException("Invalid mode!");
}

void Validator::ValidateFile(string & filename)
{
	fstream file(filename);
	if (file.fail())
		throw ValidationException("Invalid file");
}
