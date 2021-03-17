#include "Repository.h"

int checkForExistingRobotBySerial(int serialOfRobot, Robot* RobotRepository, int* lengthOfRobotRepository)
{
	int i = 0;
	for(i = 0; i < *lengthOfRobotRepository; i++)
	{
		if(RobotRepository[i].serialNumber == serialOfRobot)
			return 1;
	}
	return 0;
}

int storeNewRobot(Robot newRobot, Robot * RobotRepository, int* lengthOfRobotRepository)
{
	if ((checkForExistingRobotBySerial(newRobot.serialNumber,RobotRepository,lengthOfRobotRepository) == 1))
		return 0;
	RobotRepository[*lengthOfRobotRepository].energyCapacity = newRobot.energyCapacity;
	RobotRepository[*lengthOfRobotRepository].serialNumber = newRobot.serialNumber;
	strcpy(RobotRepository[*lengthOfRobotRepository].specialization,newRobot.specialization);
	strcpy(RobotRepository[(*lengthOfRobotRepository)++].state,newRobot.state);//also increase the length of the repository by 1
	return 1;
}

int updateExistingRobot(int serialNumber, char * newState, char * newSpecialization, int newEnergyCapacity, Robot * RobotRepository, int * lengthOfRobotRepository)
{
	
	int i = 0;
	int foundRobot = 0;
	for(i = 0; i < *lengthOfRobotRepository && foundRobot == 0; i++)
	{
		if(RobotRepository[i].serialNumber == serialNumber)
			foundRobot = 1;
	}
	if(foundRobot == 1)
	{
		strcpy(RobotRepository[i-1].state,newState);
		strcpy(RobotRepository[i-1].specialization,newSpecialization);
		RobotRepository[i-1].energyCapacity = newEnergyCapacity;
		return 1;
	}
	return 0;
}

int robotWithState(char* stateTofind, int* listofValidIndexes, Robot* RobotRepository, int* lengthOfRobotRepository)
{
	int i = 0;
	int lengthOfListOfValidIndexes = 0;
	for(i = 0; i < *lengthOfRobotRepository;i++)
	{
		if(strcmp(stateTofind,RobotRepository[i].state)==0)
			listofValidIndexes[lengthOfListOfValidIndexes++] = i;
	}
	return lengthOfListOfValidIndexes;
}

int robotsWithSpecialization(char * specializationToFind, int * listofValidIndexes, Robot * RobotRepository, int * lengthOfRobotRepository)
{
	
	int i = 0;
	int lengthOfListOfValidIndexes = 0;
	for(i = 0; i < *lengthOfRobotRepository;i++)
	{
		if(strcmp(specializationToFind,RobotRepository[i].specialization)==0)
			listofValidIndexes[lengthOfListOfValidIndexes++] = i;
	}
	return lengthOfListOfValidIndexes;
}

int deleteRobot(int serialNumberToDelete, Robot * RobotRepository, int * lengthOfRobotRepository)
{

	int i = 0;
	int indexOfRobotInTheList = -1;
	int Found = 0;
	for(i = 0; i < *lengthOfRobotRepository && Found == 0; i++)
	{
		if(RobotRepository[i].serialNumber == serialNumberToDelete)
		{
			Found = 1;
			indexOfRobotInTheList = i;
		}
	}
	if(indexOfRobotInTheList != -1)
	{
		for(i = indexOfRobotInTheList; i < *lengthOfRobotRepository; i++)
		{
			RobotRepository[i].serialNumber = RobotRepository[i+1].serialNumber;
			strcpy(RobotRepository[i].specialization,RobotRepository[i+1].specialization);
			strcpy(RobotRepository[i].state,RobotRepository[i+1].state);
			RobotRepository[i].energyCapacity = RobotRepository[i+1].energyCapacity;

		}
		*lengthOfRobotRepository = *lengthOfRobotRepository -1;
		return 1;
	}
	return 0;

}
