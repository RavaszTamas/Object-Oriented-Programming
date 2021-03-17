#include "Utilities.h"

bool CheckIfAllDigits(string & stringtToCheck)
{
	for (int i = 0; i < stringtToCheck.size(); ++i)
	{
		if (!isdigit(stringtToCheck[i]))
			return false;
	}
	return true;
}
