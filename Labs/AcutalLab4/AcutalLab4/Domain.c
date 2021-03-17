#include "Domain.h"
#include <stdio.h>
#include <string.h>

int getSerialNumber(Robot * robot)
{
	return robot->serialNumber;
}

char* getState(Robot * robot)
{
	return robot->state;
}

char* getSpecialization(Robot * robot)
{
	return robot->specialization;
}

int getEnergyCapacity(Robot * robot)
{
	return robot->energyCapacity;
}

int compareEnergyCapacityBigger(void* elementOne, void* elementTwo, valueGetter getValue)
{
	if (getValue(elementOne) < getValue(elementTwo))
		return 1;
	else if (getValue(elementOne) > getValue(elementTwo))
		return -1;
	else
		return 0;
}

int compareEnergyCapacitySmaller(void* elementOne, void* elementTwo, valueGetter getValue)
{
	if (getValue(elementOne) > getValue(elementTwo))
		return 1;
	else if (getValue(elementOne) < getValue(elementTwo))
		return -1;
	else
		return 0;
}


Robot* createRobot(int serialNumber, char * state, char * specialization, int energyCapacity)
{
	Robot* newRobot = (Robot*)malloc(sizeof(Robot));
	newRobot->serialNumber = serialNumber;
	newRobot->state = (char*)malloc(sizeof(char) * (strlen(state)+1));
	strcpy(newRobot->state,state);
	newRobot->specialization = (char*)malloc(sizeof(char) * (strlen(specialization)+1));
	strcpy(newRobot->specialization,specialization);
	newRobot->energyCapacity = energyCapacity;
	return newRobot;
}

void destroyRobot(Robot * robotToDestroy)
{
	if(robotToDestroy == NULL)
		return;

	free(robotToDestroy->state);
	free(robotToDestroy->specialization);
	free(robotToDestroy);
}

Robot* copyRobot(Robot* robotToCopy)
{
	Robot* copyOfRobot = (Robot*)malloc(sizeof(Robot));
	copyOfRobot->serialNumber = robotToCopy->serialNumber;

	copyOfRobot->state = (char*)malloc(sizeof(char)*(strlen(robotToCopy->state)+1));
	strcpy(copyOfRobot->state,robotToCopy->state);

	copyOfRobot->specialization = (char*)malloc(sizeof(char)*(strlen(robotToCopy->specialization)+1));
	strcpy(copyOfRobot->specialization,robotToCopy->specialization);

	copyOfRobot->energyCapacity = robotToCopy->energyCapacity;

	return copyOfRobot;
}

void robotToString(Robot* robotToConvert,char* string)
{
	sprintf(string,"%d %s %s %d",robotToConvert->serialNumber,robotToConvert->state,robotToConvert->specialization,robotToConvert->energyCapacity);
}