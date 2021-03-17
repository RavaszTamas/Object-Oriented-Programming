#include "Service.h"
#include "Repository.h"
#include "Domain.h"
#include <malloc.h>
#include <string.h>
#include "validator.h"

int addNewRobot(int serialNumber, char * state, char * specialization, int energyCapacity,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{
	Robot* newRobot = createRobot(serialNumber,state,specialization,energyCapacity);

	int result =  storeNewRobot(newRobot,RobotRepository,UndoRedoStackOfVectors);

	destroyRobot(newRobot);
	return result;
}
 
int updateRobot(int serialNumber, char * newState, char * newSpecialization, int newEnergyCapacity, DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{	
	Robot* newRobot = createRobot(serialNumber,newState,newSpecialization,newEnergyCapacity);


	int result =  updateExistingRobot(RobotRepository,newRobot,UndoRedoStackOfVectors);

	destroyRobot(newRobot);
	return result;
}

int filterRobotsWithSpecialization(char* specialization,int* listofValidIndexes,DynamicVector* RobotRepository)
{
	return robotsWithSpecialization(specialization,listofValidIndexes,RobotRepository);
}

int deleteTheRobotFromTheRepository(int serialNumberToDelete,DynamicVector * RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{
	return deleteRobot(serialNumberToDelete,RobotRepository,UndoRedoStackOfVectors);
}

void sortFilter(DynamicVector* RobotRepository, int* foundElements, int numberOfElements, relationFunctionState relationOfElements)
{
	int i = 0;
	int j = 0;
	int auxiliaryindex = 0;
	for (i = 0; i < numberOfElements - 1; ++i)
	{
		for (j = 0; j < numberOfElements - i - 1; ++j)
			if (relationOfElements(RobotRepository->elements[foundElements[j]], RobotRepository->elements[foundElements[j + 1]], getEnergyCapacity) < 0)
			{
				auxiliaryindex = foundElements[j];
				foundElements[j] = foundElements[j + 1];
				foundElements[j + 1] = auxiliaryindex;
			}
	}

}


int filterByMaxEnergyCapacity(int maxEnergyCapacity, int* listofValidIndexes, DynamicVector* RobotRepository, int relationType)
{
	relationFunctionState relation;
	if (relationType == 1)
		relation = compareEnergyCapacityBigger;
	else if (relationType == 2)
		relation = compareEnergyCapacitySmaller;
	else
		return 0;
	int numberOfElements = robotsByMaxEnergyCapacity(maxEnergyCapacity, listofValidIndexes, RobotRepository);
	sortFilter(RobotRepository, listofValidIndexes, numberOfElements, relation);
	return numberOfElements;
}

void UndoVectorChange(DynamicVector* RobotRepository, DynamicVector * UndoRedoStackOfVectors)
{
	DynamicVector* auxilliaryVector = copyDynamicVector(RobotRepository);
	destroyDynamicVectorElements(RobotRepository);

	DynamicVector* auxilliaryPointer = copyDynamicVector(UndoRedoStackOfVectors->elements[UndoRedoStackOfVectors->stackIndex-1]);
	*RobotRepository = *auxilliaryPointer;
	free(auxilliaryPointer);
	destroyDynamicVector(UndoRedoStackOfVectors->elements[UndoRedoStackOfVectors->stackIndex-1]);

	UndoRedoStackOfVectors->elements[UndoRedoStackOfVectors->stackIndex-1] = auxilliaryVector;

	UndoRedoStackOfVectors->stackIndex--;
	return;
}

void RedoVectorChange(DynamicVector* RobotRepository, DynamicVector * UndoRedoStackOfVectors)
{
	DynamicVector* auxilliaryVector = copyDynamicVector(RobotRepository);
	destroyDynamicVectorElements(RobotRepository);
	DynamicVector* auxilliaryPointer;
	auxilliaryPointer = copyDynamicVector(UndoRedoStackOfVectors->elements[UndoRedoStackOfVectors->stackIndex]);
	*RobotRepository = *auxilliaryPointer;
	free(auxilliaryPointer);

	destroyDynamicVector(UndoRedoStackOfVectors->elements[UndoRedoStackOfVectors->stackIndex]);

	UndoRedoStackOfVectors->elements[UndoRedoStackOfVectors->stackIndex] = auxilliaryVector;

	UndoRedoStackOfVectors->stackIndex++;
	return;
}

int UndoVectorChangeService(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfVectors)
{
	if (UndoRedoStackOfVectors->stackIndex == 0)
		return 0;//failed undo
	UndoVectorChange(RobotRepository,UndoRedoStackOfVectors);
	return 1;
}
int RedoVectorChangeService(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfVectors)
{
	if (UndoRedoStackOfVectors->size == UndoRedoStackOfVectors->stackIndex)
		return 0;//failed undo
	RedoVectorChange(RobotRepository,UndoRedoStackOfVectors);
	return 1;


}
