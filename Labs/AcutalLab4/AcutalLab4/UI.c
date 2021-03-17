#include "UI.h"
#include "Service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"
#include "DynamicArray.h"
#include "FunctionCall.h"

void UIFilterSpecialization(char* specialization,DynamicVector* RobotRepository)
{
	int* listofValidIndexes =(int*)malloc(sizeof(int)*RobotRepository->size);
	int numberOfFound = filterRobotsWithSpecialization(specialization,listofValidIndexes,RobotRepository);
	int i = 0;
	char* outPutString = (char*)malloc(sizeof(char)*1000);
	for(i = 0; i < numberOfFound; i++)
	{
	
		robotToString(RobotRepository->elements[listofValidIndexes[i]],outPutString);
		printf("%s\n",outPutString);
	}
	free(listofValidIndexes);
	free(outPutString);
}

void UIFilterByMaxEnergyCapacity(int maxEnegryCapacity,DynamicVector* RobotRepository)
{
	int* listofValidIndexes =(int*)malloc(sizeof(int)*RobotRepository->size);
	int good = 1;
	int relationType;
	while (good)
	{
		printf("Enter 1 for ascending sort, 2 for descending sort!\n");
		char choice;
		scanf(" %c", &choice);
		if (choice == '1')
		{
			relationType = compareEnergyCapacityBigger;
			good = 0;
		}
		else if (choice == '2')
		{
			relationType = compareEnergyCapacitySmaller;
			good = 0;
		}
	}
	int numberOfFound = filterByMaxEnergyCapacity(maxEnegryCapacity,listofValidIndexes,RobotRepository, relationType);
	int i = 0;
	char* outPutString = (char*)malloc(sizeof(char)*1000);
	for(i = 0; i < numberOfFound; i++)
	{
		robotToString(RobotRepository->elements[listofValidIndexes[i]],outPutString);
		printf("%s\n",outPutString);
	}
	free(listofValidIndexes);
	free(outPutString);
}
void UIListRobots(char* inputParameters,DynamicVector* RobotRepository)
{
	if(isdigit(inputParameters[0]) || (inputParameters[0] == '-' && isdigit(inputParameters)))
	{
		UIFilterByMaxEnergyCapacity(atoi(inputParameters),RobotRepository);

	}
	else if(isalpha(inputParameters[0]))
	{
		UIFilterSpecialization(inputParameters,RobotRepository);
	}
	else
	{
		int i = 0;
		char* outPutString = (char*)malloc(sizeof(char)*1000);
		for(i = 0; i < RobotRepository->size; i++)
		{
			robotToString(RobotRepository->elements[i],outPutString);
			printf("%s\n",outPutString);
		}
		free(outPutString);
	}
}
void UIDeleteRobot(char* inputParameters,DynamicVector* RobotRepository, DynamicVector* UndoRedoStackOfVectors)
{
	int serialNumberOfRobot = atoi(strtok(inputParameters,", \n"));

	if(deleteTheRobotFromTheRepository(serialNumberOfRobot,RobotRepository,UndoRedoStackOfVectors) == 1)
		printf("No robot with that serial number!\n");

	//printf("%s",serialNumberOfRobot);
}
void UIUpdateExistingRobot(char* inputParameters,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{
	char* serialNumberString = strtok(inputParameters,", \n");

	if (serialNumberString == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}
	int SerialNumber = atoi(serialNumberString);

	char* newState = strtok(NULL,", \n");

	if (newState == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}

	char* newSpecialization = strtok(NULL, ", \n");

	if (newSpecialization == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}
	char* newEnergyCapacityString = strtok(NULL,", \n");
	if(newEnergyCapacityString == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}

	int newEnergyCapacity = atoi(newEnergyCapacityString);

	if(updateRobot(SerialNumber,newState,newSpecialization,newEnergyCapacity,RobotRepository,UndoRedoStackOfVectors)==1)
		printf("%s","No robot with that serial number!\n");
	//printf("%d %s %s %d\n",SerialNumber,newState,newSpecialization,newEnergyCapacity);
}
void UIAddNewRobot(char* inputParameters,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors)
{
	char* serialNumberString = strtok(inputParameters,", \n");
	if (serialNumberString == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}

	int serialNumber = atoi(serialNumberString);

	char* state = strtok(NULL,", \n");

	if (state == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}

	char* specialization = strtok(NULL, ", \n");

	if (specialization == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}
	char* energyCapacityString = strtok(NULL,", \n");
	if(energyCapacityString == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}
	int energyCapacity = atoi(energyCapacityString);
	//printf("%s %s %s %s\n",serialNumber,state,specialization,energyCapacity);
	int exitCode = addNewRobot(serialNumber,state,specialization,energyCapacity,RobotRepository,UndoRedoStackOfVectors);
	if (exitCode == 1)
		printf("Robot already exists!\n");

		//printf("%s %s %s %s\n",serialNumber,state,specialization,energyCapacity);
}


void UIUndo(DynamicVector* RobotRepository, DynamicVector* UndoRedoStack)
{
	
	return;
}

void UIRedo()
{
	return;
}

void UIUndoListofLists(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfVectors)
{
	int result = UndoVectorChangeService(RobotRepository,UndoRedoStackOfVectors);//failed undo
	if(result == 0)
	{
		printf("%s","No more undo possibility!\n");
		return;
	}
	return;
}

void UIRedoListofLists(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfVectors)
{
	int result =  RedoVectorChangeService(RobotRepository,UndoRedoStackOfVectors);//failed undo
	if(result == 0)//Failed undo
	{
		printf("%s","No more redo possibility!\n");
		return;
	}
	return;
}

void UIUndoFunctionCalls(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfFunctionCalls)
{

}

void UIRedoFunctionCalls(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfFunctionCalls)
{
}


void UI()
{
	DynamicVector* RobotRepository = createVector(10,destroyRobot,copyRobot);
	DynamicVector* UndoRedoStackOfVectors = createVector(1,destroyDynamicVector,copyDynamicVector);
	//DynamicVector* UndoRedoStackOfFunctionCalls = createVector(1,destroyFunctionCall,copyFunctionCall);
	UndoRedoStackOfVectors->stackIndex = 0;

	char* InputCommand=(char*)malloc(sizeof(char)*1001);
	int i = 0;
	for(i = 0 ; i < 1001; i++)
		InputCommand[i] = 0;

	char* command;
	while(1)
	{
		scanf(" %[^'\n']s",InputCommand);
		command = strtok(InputCommand,", \n");
		if(strcmp(command,"add") == 0)
		{
			UIAddNewRobot(InputCommand+4,RobotRepository,UndoRedoStackOfVectors);
		}
		else if(strcmp(command,"update") == 0)
		{
			UIUpdateExistingRobot(InputCommand+7,RobotRepository,UndoRedoStackOfVectors);

		}
		else if(strcmp(command,"delete") == 0)
		{
			UIDeleteRobot(InputCommand+7,RobotRepository,UndoRedoStackOfVectors);

		}
		else if(strcmp(command,"list") == 0)
		{
			UIListRobots(InputCommand+5,RobotRepository);

		}
		else if(strcmp(command,"undo") == 0)
		{
			UIUndoListofLists(RobotRepository,UndoRedoStackOfVectors);
			//UIUndoFunctionCalls(RobotRepository,UndoRedoStackOfFunctionCalls);
		}
		else if(strcmp(command,"redo") == 0)
		{
			UIRedoListofLists(RobotRepository,UndoRedoStackOfVectors);
			//UIRedoFunctionCalls(RobotRepository,UndoRedoStackOfFunctionCalls);
		}
		else if(strcmp(command,"exit")==0)
		{
			destroyDynamicVector(RobotRepository);
			destroyDynamicVector(UndoRedoStackOfVectors);
			free(InputCommand);
			return;
		}
		else
			printf("Invalid command!\n");

		for(i = 0 ; i < 1001; i++)
			InputCommand[i] = 0;
			
	}
	destroyDynamicVector(RobotRepository);
	free(InputCommand);
}
