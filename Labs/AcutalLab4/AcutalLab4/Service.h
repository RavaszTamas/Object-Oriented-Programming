#pragma once
#include "Domain.h"
#include "DynamicArray.h"

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
int addNewRobot(int serialNumber, char* state, char* specialization, int energyCapacity,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors);

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
int updateRobot(int serialNumber, char* newState, char* newSpecialization, int newEnergyCapacity,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors);

/*
	Find the robots with the the specialization, and include their indeces into the listofValidIndexes
	input:specializaiton - string representing the specialization of the robot
		  listofValidIndexes - list of integers representing the valid indexes
		   RobotRepository - list of robots in the list of robots
		   lengthOfRobotRepository -integer
	ouput: the number of the found robots
		   the listofValidIndexes U {Xi}, Xi.specialization = specializationToFind
	*/
int filterRobotsWithSpecialization(char* specialization,int* listofValidIndexes,DynamicVector* RobotRepository);

	/*
	input: serialNumberToDelete - the serialnumber of the robot to be deleted
		   RobotRepository - list of robots in the list of robots
		   lengthOfRobotRepository -integer
	ouput: 1 - if the robot is deleted successfully
		   0 - if the robot is not deleted
	postcondition: {robotrepository}' = {robotrepository} \ {Xi}
	*/
int deleteTheRobotFromTheRepository(int serialNumberToDelete,DynamicVector * RobotRepository,DynamicVector* UndoRedoStackOfVectors);
/*
input: maxEnergyCapacity - integer
	   listofValidIndexes - integer array
	   RobotRepository - list of robots in the list of robots
	   relationType - the specified relation for the the filter, in this case the 1 is the ascending order, 2 is the descending order
*/
int filterByMaxEnergyCapacity(int maxEnergyCapacity, int* listofValidIndexes, DynamicVector* RobotRepository, int relationType);
/*
This is the function which perfroms the undo action, the penultimate of the stack is copied as the repository
and the current repository is put on the top of the stack
input: - RobotRepository - the repository of ropobts
		 UndoStackOfVectors - all the previous valid iterations of the repository
output: none
*/
void UndoVectorChange(DynamicVector * RobotRepository,DynamicVector* UndoRedoStackOfVectors);
/*
This is the function which perfroms the redo action
	input: - RobotRepository - the repository of ropobts
	UndoStackOfVectors - all the previous valid iterations of the repository
	output: none

*/
void RedoVectorChange(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfVectors);
/*
This is the function checks wether an undo action can be performed, the top  element of the stack is copied as the repository
and the current repository is put on the top of the stack
input: - RobotRepository - the repository of ropobts
UndoStackOfVectors - all the previous valid iterations of the repository
output: 0 if successful
		1 if failed

*/
int UndoVectorChangeService(DynamicVector * RobotRepository,DynamicVector* UndoRedoStackOfVectors);
/*
This is the function checks wether an redo action can be performed
input: - RobotRepository - the repository of ropobts
UndoStackOfVectors - all the previous valid iterations of the repository
output: 0 if successful
	1 if failed

*/
int RedoVectorChangeService(DynamicVector * RobotRepository, DynamicVector * UndoRedoStackOfVectors);
/*
input: RobotRepository - list of robots in the list of robots
	   foundElements - an array of elements found
	   numberOfElements - numberOfFoundElements the number of elements found
	   relationFunctionState relationOfElements - a function pointer representing the relation - it returns >0 if the order is correct
												 0 if the elemenets are the same <0 for an incorrect order
output: the found elements array arraneged in the desired order
*/
void sortFilter(DynamicVector* RobotRepository, int* foundElements, int numberOfElements, relationFunctionState relationOfElements);
