#include "Validator.h"

bool Validator::ValidateInteger(int integerToValidate)
{
	if (integerToValidate < 0)
		return false;
	return true;
}

bool Validator::ValidateMode(string & modeToCheck)
{
	for (auto it = this->modes.begin(); it != this->modes.end(); ++it)
	{
		if (*it == modeToCheck)
			return true;
	}
	return false;
}
