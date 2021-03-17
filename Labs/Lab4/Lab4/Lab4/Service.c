#include "Service.h"
#include "Repository.h"
#include "Domain.h"
#include <malloc.h>
#include <string.h>
#include "validator.h"
#define InvalidNumericalInput 2


int addNewRobot(char* serialNumber, char * state, char * specialization, char* energyCapacity,Robot* RobotRepository,int* lengthOfRobotRepository)
{
	Robot newRobot;
	if(checkIfInteger(serialNumber) == 0)
		return 2;
	newRobot.serialNumber = atoi(serialNumber);
	//newRobot->state = (char*)malloc((strlen(state)+1)*sizeof(char));
	strcpy(newRobot.state,state);
	//->specialization = (char*)malloc((strlen(specialization)+1)*sizeof(char));
	strcpy(newRobot.specialization,specialization);
	if(checkIfInteger(energyCapacity) == 0)
		return 2;

	newRobot.energyCapacity = atoi(energyCapacity);
	return storeNewRobot(newRobot,RobotRepository,lengthOfRobotRepository);
}
 
int updateRobot(char* serialNumber, char * newState, char * newSpecialization, char* newEnergyCapacity, Robot * RobotRepository, int * lengthOfRobotRepository)
{	
	if(checkIfInteger(serialNumber) == 0)
		return InvalidNumericalInput;///exit code of invalid numerical input

	int serialNumberInteger = atoi(serialNumber);

	if(checkIfInteger(newEnergyCapacity) == 0)
		return InvalidNumericalInput;

	int newEnergyCapacityInteger = atoi(newEnergyCapacity);

	return updateExistingRobot(serialNumberInteger,newState,newSpecialization,newEnergyCapacityInteger,RobotRepository,lengthOfRobotRepository);
}

int filterRobots(char choice,char* elementToFilterBy,int* listofValidIndexes,Robot * RobotRepository, int* lengthOfRobotRepository)
{
	fitlerTheList filterFunction;
	if (choice == '1')
		filterFunction = robotWithState;
	else if (choice == '2')
		filterFunction = robotsWithSpecialization;

	return filterFunction(elementToFilterBy,listofValidIndexes,RobotRepository,lengthOfRobotRepository);
}


int deleteTheRobotFromTheRepository(char* serialNumberToDelete, Robot * RobotRepository, int * lengthOfRobotRepository)
{
	if(checkIfInteger(serialNumberToDelete) == 0)
		return InvalidNumericalInput;
	int serialNumberToDeleteInteger = atoi(serialNumberToDelete);
	return deleteRobot(serialNumberToDeleteInteger,RobotRepository,lengthOfRobotRepository);
}
