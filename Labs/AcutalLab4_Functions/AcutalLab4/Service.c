#include "Service.h"
#include "Repository.h"
#include "Domain.h"
#include "FunctionCall.h"
#include <malloc.h>
#include <string.h>
#include "validator.h"

int addNewRobot(int serialNumber, char * state, char * specialization, int energyCapacity,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{
	Robot* newRobot = createRobot(serialNumber,state,specialization,energyCapacity);

	int result =  storeNewRobot(newRobot,RobotRepository,UndoRedoStackOfVectors);
	if(result == 0)
	{
		ClearRedoStack(UndoRedoStackOfVectors);
		int serialNumber = getSerialNumber(newRobot);
		functionCall* newFunctionCall = createFunctionCall("add",&serialNumber,newRobot,&deleteInteger,&destroyRobot,&duplicateInteger,&copyRobot);
		addUndoFunction(UndoRedoStackOfVectors,newFunctionCall);
		destroyFunctionCall(newFunctionCall);
	}
	destroyRobot(newRobot);
	return result;
}
 
int updateRobot(int serialNumber, char * newState, char * newSpecialization, int newEnergyCapacity, DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{	
	Robot* newRobot = createRobot(serialNumber,newState,newSpecialization,newEnergyCapacity);


	Robot* resultRobot =  updateExistingRobot(RobotRepository,newRobot,UndoRedoStackOfVectors);
	if (resultRobot != NULL)//sucessfull addition
	{
		ClearRedoStack(UndoRedoStackOfVectors);
		functionCall* newFunctionCall = createFunctionCall("update", resultRobot, newRobot, &destroyRobot, &destroyRobot, &copyRobot, &copyRobot);
		addUndoFunction(UndoRedoStackOfVectors, newFunctionCall);
		destroyFunctionCall(newFunctionCall);
		destroyRobot(resultRobot);
	}
	destroyRobot(newRobot);
	if (resultRobot == NULL)
		return 1;
	return 0;
	
}

int filterRobotsWithSpecialization(char* specialization,int* listofValidIndexes,DynamicVector* RobotRepository)
{
	return robotsWithSpecialization(specialization,listofValidIndexes,RobotRepository);
}

int deleteTheRobotFromTheRepository(int serialNumberToDelete,DynamicVector * RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{
	Robot* resultRobot = deleteRobot(serialNumberToDelete,RobotRepository,UndoRedoStackOfVectors);
	if(resultRobot != NULL)
	{
		ClearRedoStack(UndoRedoStackOfVectors);
		int serialNumber = getSerialNumber(resultRobot);
		functionCall* newFunctionCall = createFunctionCall("remove",resultRobot,&serialNumberToDelete,&destroyRobot,&deleteInteger,&copyRobot,&duplicateInteger);
		addUndoFunction(UndoRedoStackOfVectors,newFunctionCall);
		destroyFunctionCall(newFunctionCall);
		destroyRobot(resultRobot);
		return 0;
	}
	return 1;


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


int filterByMaxEnergyCapacity(int maxEnergyCapacity, int* listofValidIndexes, DynamicVector* RobotRepository, char choice)
{
	relationFunctionState relation;
	if (choice == '1')//ascending order
		relation = compareEnergyCapacityBigger;
	else if (choice == '2')//descending order
		relation = compareEnergyCapacitySmaller;

	int numberOfElements = robotsByMaxEnergyCapacity(maxEnergyCapacity,listofValidIndexes,RobotRepository);
	sortFilter(RobotRepository,listofValidIndexes,numberOfElements, relation);
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
		return 0;//failed redo
	RedoVectorChange(RobotRepository,UndoRedoStackOfVectors);
	return 1;


}
void UndoFunction(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfFunctionCalls)
{
	char* type = getType(UndoRedoStackOfFunctionCalls->elements[UndoRedoStackOfFunctionCalls->stackIndex-1]);
	if(strcmp(type,"add") == 0)
	{
		int serialToDelete = *getParameterUndo(UndoRedoStackOfFunctionCalls->elements[UndoRedoStackOfFunctionCalls->stackIndex-1]);
		Robot* ResultToDelete = deleteRobot(serialToDelete,RobotRepository,UndoRedoStackOfFunctionCalls);
		destroyRobot(ResultToDelete);
	}
	else if(strcmp(type,"update")==0)
	{
		Robot* robotToModifyWith = getParameterUndo(UndoRedoStackOfFunctionCalls->elements[UndoRedoStackOfFunctionCalls->stackIndex-1]);
		Robot* ResultToDelete = updateExistingRobot(RobotRepository,robotToModifyWith,UndoRedoStackOfFunctionCalls);
		destroyRobot(ResultToDelete);
	}
	else if(strcmp(type,"remove")==0)
	{
		Robot* robotToAdd = getParameterUndo(UndoRedoStackOfFunctionCalls->elements[UndoRedoStackOfFunctionCalls->stackIndex-1]);
		storeNewRobot(robotToAdd,RobotRepository,UndoRedoStackOfFunctionCalls);
	}
	UndoRedoStackOfFunctionCalls->stackIndex--;

}

void RedoFunction(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfFunctionCalls)
{
	char* type = getType(UndoRedoStackOfFunctionCalls->elements[UndoRedoStackOfFunctionCalls->stackIndex]);
	if(strcmp(type,"add") == 0)
	{
		Robot* robotToAdd = getParameterRedo(UndoRedoStackOfFunctionCalls->elements[UndoRedoStackOfFunctionCalls->stackIndex]);
		storeNewRobot(robotToAdd,RobotRepository,UndoRedoStackOfFunctionCalls);

	}
	else if(strcmp(type,"update")==0)
	{
		Robot* robotToModifyWith = getParameterRedo(UndoRedoStackOfFunctionCalls->elements[UndoRedoStackOfFunctionCalls->stackIndex]);
		Robot* resultToDelete = updateExistingRobot(RobotRepository,robotToModifyWith,UndoRedoStackOfFunctionCalls);
		destroyRobot(resultToDelete);

	}
	else if(strcmp(type,"remove")==0)
	{
		int serialToDelete = *getParameterRedo(UndoRedoStackOfFunctionCalls->elements[UndoRedoStackOfFunctionCalls->stackIndex]);
		Robot* resultToDelete = deleteRobot(serialToDelete,RobotRepository,UndoRedoStackOfFunctionCalls);
		destroyRobot(resultToDelete);
	}
	UndoRedoStackOfFunctionCalls->stackIndex++;

}

int UndoFunctionService(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfFunctionCalls)
{
	if(UndoRedoStackOfFunctionCalls->stackIndex == 0)
		return 0;
	UndoFunction(RobotRepository,UndoRedoStackOfFunctionCalls);
	return 1;
}

int RedoFunctionService(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfFunctionCalls)
{
	if(UndoRedoStackOfFunctionCalls->size == UndoRedoStackOfFunctionCalls->stackIndex)
		return 0;
	RedoFunction(RobotRepository,UndoRedoStackOfFunctionCalls);
	return 1;
}


