#pragma once
#include "Domain.h"
#include"Repository.h"

	/*
	Create a now robot then add it to the repository
	precondition: robot not in the list
	input: serialNumber - the number representing the robot
		   State - string representing the state for the robot
		   newSpecialization - string representing the new specialization
		   EnegyCapacity - number representing the energy capacity
		   RobotRepository - list of robots in the list of robots
		   lengthOfRobotRepository -integer
	output: 1 - if the robot is added sucessfully
			0 - if the addition is failed
	*/
int addNewRobot(char* serialNumber, char* state, char* specialization, char* energyCapacity,Robot* RobotRepository,int* lengthOfRobotRepository);

/*
	Updates an existing robot by it's serialNumber
	precondition: the robot must already exist
	input: serialNumber - the number representing the robot
		   newState - string representing the new state for the robot
		   newSpecialization - string representing the new specialization
		   newEnegyCapacity - number representing the new energy capacity
		   RobotRepository - list of robots in the list of robots
		   lengthOfRobotRepository -integer
	output: 0 - no successful update
			1 - the update is successful
	postcondition: X' U {X1,X2,..}
	*/
int updateRobot(char* serialNumber, char* newState, char* newSpecialization, char* newEnergyCapacity,Robot* RobotRepository,int* lengthOfRobotRepository);

/*
	Find the robots with the the specialization, and include their indeces into the listofValidIndexes
	input:specializaiton - string representing the specialization of the robot
		  listofValidIndexes - list of integers representing the valid indexes
		   RobotRepository - list of robots in the list of robots
		   lengthOfRobotRepository -integer
	ouput: the number of the found robots
		   the listofValidIndexes U {Xi}, Xi.specialization = specializationToFind
	*/
int filterRobots(char choice, char* elementToFilterBy, int* listofValidIndexes, Robot * RobotRepository, int* lengthOfRobotRepository);

	/*
	input: serialNumberToDelete - the serialnumber of the robot to be deleted
		   RobotRepository - list of robots in the list of robots
		   lengthOfRobotRepository -integer
	ouput: 1 - if the robot is deleted successfully
		   0 - if the robot is not deleted
	postcondition: {robotrepository}' = {robotrepository} \ {Xi}
	*/
int deleteTheRobotFromTheRepository(char* serialNumberToDelete,Robot * RobotRepository, int* lengthOfRobotRepository);
