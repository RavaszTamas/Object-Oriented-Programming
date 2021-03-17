#pragma once
#include "Domain.h"
#include "DynamicArray.h"

	/*
	Searches through the RobotReopsitory and checks whether a robot exists with a given serialnumber
	precondition: none
	input: serialOfRobot-integer serial number to be found in the list
		   RobotRepository - the list of robots
		   lengthOfRobotRepository - length of the list of robots
	output: 1 if the robot is found i.e.- there are two equal serial number
	postcondition: none
	*/
int checkForExistingRobotBySerial(int serialOfRobot,DynamicVector* RobotRepository);

	/*
	Store the new robot into the Repository of Robots
	If the robot with the same serial exists the new robot is not included in the list
	input: newRobot-the new robot to be added to the list
		   RobotRepository - the list of robots
		   lengthOfRobotRepository - length of the list of robots
	output: 0 if the robot already exists
			1 if the addition is successful
	postcondition: the newRobot is included in the RobotRepository
	*/
int storeNewRobot(Robot* newRobot,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors);

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
int updateExistingRobot(DynamicVector* RobotRepository,Robot* newRobot,DynamicVector* UndoRedoStackOfVectors);

/*
	Find the robots with the the specialization, and include their indeces into the listofValidIndexes
	input:specializaiton - string representing the specialization of the robot
		  listofValidIndexes - list of integers representing the valid indexes
		   RobotRepository - list of robots in the list of robots
		   lengthOfRobotRepository -integer
	ouput: the number of the found robots
		   the listofValidIndexes U {Xi}, Xi.specialization = specializationToFind
	*/
int robotsWithSpecialization(char* specializationToFind,int* listofValidIndexes,DynamicVector* RobotRepository);
	/*
	input: serialNumberToDelete - the serialnumber of the robot to be deleted
		   RobotRepository - list of robots in the list of robots
		   lengthOfRobotRepository -integer
	ouput: 1 - if the robot is deleted successfully
		   0 - if the robot is not deleted
	postcondition: {robotrepository}' = {robotrepository} \ {Xi}
	*/
int deleteRobot(int serialNumberToDelete,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors);


int robotsByMaxEnergyCapacity(int maxEnergyCapacity,int* listofValidIndexes,DynamicVector* RobotRepository);

void addUndoAction(DynamicVector* UndoRedoStackOfVectors,DynamicVector* RobotRepository);
