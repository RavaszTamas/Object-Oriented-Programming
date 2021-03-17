#include "Domain.h"
#include <string.h>

char* getState(Robot* robot)
{
	return robot->state;
}
char* getSpecialization(Robot* robot)
{
	return robot->specialization;
}
int compareState(Robot* robotOne, Robot* robotTwo)
{
	return strcmp(getState(robotOne), getState(robotTwo));
}
int compareSpecialization(Robot* robotOne, Robot* robotTwo)
{
	return strcmp(getSpecialization(robotOne), getSpecialization(robotTwo));
}