#include "Repository.h"
#include "FunctionCall.h"
#include <stdio.h>

int checkForExistingRobotBySerial(int serialOfRobot, DynamicVector* RobotRepository)
{
	int i = 0;
	for(i = 0; i < RobotRepository->size; i++)
	{
		if(getSerialNumber(RobotRepository->elements[i]) == serialOfRobot)
			return i;
	}
	return -1;//-1 index as for an element not in the list
}

int storeNewRobot(Robot* newRobot, DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{
	if ((checkForExistingRobotBySerial(getSerialNumber(newRobot),RobotRepository)) != -1)
		return 1;//Failed

	addToVector(RobotRepository,newRobot);
	return 0;//Successful Storage
}

TElem* updateExistingRobot(DynamicVector* RobotRepository,Robot* newRobot,DynamicVector* UndoRedoStackOfVectors)
{
	
	int i = 0;
	int indexOfRobot = checkForExistingRobotBySerial(getSerialNumber(newRobot),RobotRepository);
	if(indexOfRobot != -1)
	{
		Robot* returnElement = (Robot*)updateElementOfVector(RobotRepository,newRobot,indexOfRobot);
		return returnElement;//Successful update
	}
	return NULL;//Failed update
}

int robotsWithSpecialization(char * specializationToFind, int * listofValidIndexes, DynamicVector* RobotRepository)
{
	
	int i = 0;
	int lengthOfListOfValidIndexes = 0;
	for(i = 0; i < RobotRepository->size; i++)
	{
		if(strcmp(specializationToFind,getSpecialization(RobotRepository->elements[i]))==0)
			listofValidIndexes[lengthOfListOfValidIndexes++] = i;
	}
	return lengthOfListOfValidIndexes;
}

TElem* deleteRobot(int serialNumberToDelete, DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{
	int indexOfRobot = checkForExistingRobotBySerial(serialNumberToDelete,RobotRepository);
	if(indexOfRobot == -1)
		return NULL;

	return removeFromVector(RobotRepository,indexOfRobot);

}

int robotsByMaxEnergyCapacity(int maxEnergyCapacity, int * listofValidIndexes, DynamicVector* RobotRepository)
{
	int i = 0;
	int lengthOfListOfValidIndexes = 0;
	for(i = 0; i < RobotRepository->size; i++)
	{
		if(getEnergyCapacity(RobotRepository->elements[i]) < maxEnergyCapacity)
			listofValidIndexes[lengthOfListOfValidIndexes++] = i;
	}
	return lengthOfListOfValidIndexes;

	return 0;
}

void addUndoAction(DynamicVector* UndoRedoStackOfVectors, DynamicVector * RobotRepository)
{
	UndoRedoStackOfVectors->stackIndex++;
	addToVector(UndoRedoStackOfVectors,RobotRepository);
}

void addUndoFunction(DynamicVector* UndoRedoStackOfFunctions,functionCall* newFunctionCall)
{
	UndoRedoStackOfFunctions->stackIndex++;

	addToVector(UndoRedoStackOfFunctions,newFunctionCall);
}
