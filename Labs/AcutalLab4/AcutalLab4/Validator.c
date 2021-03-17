#include "validator.h"
#include <string.h>

int checkIfInteger(char * stringOfCharactersToCheck)
{
	int i =0;
	if(stringOfCharactersToCheck[0] == '-')
		i = 1;
	int auxilliaryLengthOfString = strlen(stringOfCharactersToCheck);
	for(i; i < auxilliaryLengthOfString; i++)
		if(isdigit(stringOfCharactersToCheck[i]) == 0)
			return 0;
	return 1;
}
