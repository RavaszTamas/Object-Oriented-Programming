#include "UI.h"
#include "Service.h"
#include "Repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Domain.h"

void UIFilter(char* filterElement,Robot* RobotRepository,int* lengthOfRobotRepository)
{
	int listofValidIndexes[1000];
	fitlerTheList filterFunction;
	
		int good = 1;
		char choice = 0;
		while (good)
		{
			printf("Enter 1 to filter state by , or 2 by specializaton\n");
			scanf(" %c", &choice);
			if (choice == '1')
			{
				good = 0;
			}
			else if (choice == '2')
			{
				good = 0;
			}
		}
	
	int numberOfFound = filterRobots(choice, filterElement,listofValidIndexes,RobotRepository,lengthOfRobotRepository);
	int i = 0;
	for(i = 0; i < numberOfFound; i++)
	{
			printf("%d %s %s %d\n",RobotRepository[listofValidIndexes[i]].serialNumber,RobotRepository[listofValidIndexes[i]].state,RobotRepository[listofValidIndexes[i]].specialization,RobotRepository[listofValidIndexes[i]].energyCapacity);
	}
}
void UIListRobots(char* inputParameters,Robot* RobotRepository,int* lengthOfRobotRepository)
{
	if(inputParameters[0] != 0)
	{
		UIFilter(inputParameters,RobotRepository,lengthOfRobotRepository);
	}
	else
	{
		int i = 0;
		for(i = 0; i < *lengthOfRobotRepository; i++)
			printf("%d %s %s %d\n",RobotRepository[i].serialNumber,RobotRepository[i].state,RobotRepository[i].specialization,RobotRepository[i].energyCapacity);
	}
}
void UIDeleteRobot(char* inputParameters,Robot* RobotRepository,int* lengthOfRobotRepository)
{
	int serialNumberOfRobot = strtok(inputParameters,", \n");

	if(deleteTheRobotFromTheRepository(serialNumberOfRobot,RobotRepository,lengthOfRobotRepository) == 0)
		printf("No robot with that serial number!\n");

	//printf("%s",serialNumberOfRobot);
}
void UIUpdateExistingRobot(char* inputParameters,Robot* RobotRepository,int* lengthOfRobotRepository)
{
	int SerialNumber = strtok(inputParameters,", \n");
	char* newState = strtok(NULL,", \n");
	char* newSpecialization = strtok(NULL,", \n");
	int newEnergyCapacity = strtok(NULL,", \n");
	updateRobot(SerialNumber,newState,newSpecialization,newEnergyCapacity,RobotRepository,lengthOfRobotRepository);
	//printf("%d %s %s %d\n",SerialNumber,newState,newSpecialization,newEnergyCapacity);
}
void UIAddNewRobot(char* inputParameters,Robot* RobotRepository,int* lengthOfRobotRepository)
{
	char* serialNumber = strtok(inputParameters,", \n");
	if (serialNumber == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}

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
	char* energyCapacity = strtok(NULL,", \n");
	if(energyCapacity == NULL)
	{
		printf("Invalid parameters!\n");
		return;
	}

	//printf("%s %s %s %s\n",serialNumber,state,specialization,energyCapacity);
	int exitCode = addNewRobot(serialNumber,state,specialization,energyCapacity,RobotRepository,lengthOfRobotRepository);
	if (exitCode == 0)
		printf("Robot already exists!\n");
	else if(exitCode == 0)
		printf("Invalid input!\n");

		//printf("%s %s %s %s\n",serialNumber,state,specialization,energyCapacity);
}


void UI()
{
	Robot RobotRepository[1000];
	int lengthOfRobotRepository = 0;
	char InputCommand[1001];
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
			//printf("%s\n",InputCommand+4);
			UIAddNewRobot(InputCommand+4,RobotRepository,&lengthOfRobotRepository);
		}
		else if(strcmp(command,"update") == 0)
		{
			UIUpdateExistingRobot(InputCommand+7,RobotRepository,&lengthOfRobotRepository);
			//printf("%s\n",InputCommand+7);

		}
		else if(strcmp(command,"delete") == 0)
		{
			UIDeleteRobot(InputCommand+7,RobotRepository,&lengthOfRobotRepository);
			//printf("%s\n",InputCommand+7);

		}
		else if(strcmp(command,"list") == 0)
		{
			UIListRobots(InputCommand+5,RobotRepository,&lengthOfRobotRepository);
			//printf("%s\n",InputCommand+5);

		}
		else if(strcmp(command,"exit")==0)
			return;
		else
			printf("Invalid command!\n");

		for(i = 0 ; i < 1001; i++)
			InputCommand[i] = 0;
		//printf(" \n");
		//scanf("%c",&extraendline);
			
	}
}
