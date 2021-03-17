#include "Test.h"
#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include <assert.h>
#include "validator.h"
#include "FunctionCall.h"
#include "DynamicArray.h"
/*
void testAll()
{
	DynamicVector* RobotRepository = createVector(1,&destroyRobot,&copyRobot);
	DynamicVector* UndoRedoStackOfVectors = createVector(1,&destroyDynamicVector,&copyDynamicVector);
	UndoRedoStackOfVectors->stackIndex = 0;
	addNewRobot(1,"a","b",1,RobotRepository,UndoRedoStackOfVectors);
	assert(RobotRepository->size == 1);





	assert(getSerialNumber(RobotRepository->elements[0]) == 1);
	assert(strcmp(getState(RobotRepository->elements[0]),"a") == 0);
	assert(strcmp(getSpecialization(RobotRepository->elements[0]),"b") == 0);
	assert(getEnergyCapacity(RobotRepository->elements[0]) == 1);



	addNewRobot(1,"ca","cb",12,RobotRepository,UndoRedoStackOfVectors);
	assert(RobotRepository->size == 1);

	deleteTheRobotFromTheRepository(1,RobotRepository,UndoRedoStackOfVectors);
	assert(RobotRepository->size == 0);

	addNewRobot(1,"2","3",4,RobotRepository,UndoRedoStackOfVectors);
	assert(getSerialNumber(RobotRepository->elements[0]) == 1);
	assert(strcmp(getState(RobotRepository->elements[0]),"2") == 0);
	assert(strcmp(getSpecialization(RobotRepository->elements[0]),"3") == 0);
	assert(getEnergyCapacity(RobotRepository->elements[0]) == 4);
	updateRobot(1,"22","33",44,RobotRepository,UndoRedoStackOfVectors);
	assert(getSerialNumber(RobotRepository->elements[0]) == 1);
	assert(strcmp(getState(RobotRepository->elements[0]),"22") == 0);
	assert(strcmp(getSpecialization(RobotRepository->elements[0]),"33") == 0);
	assert(getEnergyCapacity(RobotRepository->elements[0]) == 44);
	assert(checkForExistingRobotBySerial(1,RobotRepository) == 0);
	assert(checkForExistingRobotBySerial(2,RobotRepository) == -1);

	addNewRobot(2,"2","a",4,RobotRepository,UndoRedoStackOfVectors);
	addNewRobot(3,"2","a",4,RobotRepository,UndoRedoStackOfVectors);
	addNewRobot(4,"2","b",4,RobotRepository,UndoRedoStackOfVectors);

	int listOfIndexes[100];
	assert(robotsWithSpecialization("a",listOfIndexes,RobotRepository) == 2);
	assert(checkIfInteger("123") == 1);
	assert(checkIfInteger("-123") == 1);
	assert(checkIfInteger("-123a") == 0);

	assert(RobotRepository->size==4);
	assert(UndoRedoStackOfVectors->size == 7);

	
	UndoVectorChangeService(RobotRepository,UndoRedoStackOfVectors);

	assert(RobotRepository->size==3);
	assert(UndoRedoStackOfVectors->stackIndex == 6);


	addNewRobot(5,"2","a",4,RobotRepository,UndoRedoStackOfVectors);


	RedoVectorChangeService(RobotRepository,UndoRedoStackOfVectors);


	UndoVectorChangeService(RobotRepository,UndoRedoStackOfVectors);

	assert(RobotRepository->size==3);
	assert(UndoRedoStackOfVectors->stackIndex == 6);


	destroyDynamicVector(RobotRepository);
	destroyDynamicVector(UndoRedoStackOfVectors);

	return;

}
*/
void testUndoRedoFunctionCalls()
{
	
	DynamicVector* RobotRepository = createVector(1,&destroyRobot,&copyRobot);
	DynamicVector* UndoRedoStackOfFunctionCalls = createVector(1,&destroyFunctionCall,&copyFunctionCall);
	UndoRedoStackOfFunctionCalls->stackIndex = 0;
	/*
	addNewRobot(1,"a","b",1,RobotRepository,UndoRedoStackOfFunctionCalls);

	UndoFunctionService(RobotRepository,UndoRedoStackOfFunctionCalls);
	RedoFunctionService(RobotRepository,UndoRedoStackOfFunctionCalls);
	UndoFunctionService(RobotRepository, UndoRedoStackOfFunctionCalls);
	RedoFunctionService(RobotRepository, UndoRedoStackOfFunctionCalls);

	updateRobot(1, "c", "d", 2, RobotRepository, UndoRedoStackOfFunctionCalls);
	assert(getSerialNumber(RobotRepository->elements[0]) == 1);
	assert(strcmp(getState(RobotRepository->elements[0]),"c") == 0);
	assert(strcmp(getSpecialization(RobotRepository->elements[0]), "d") == 0);
	assert(getEnergyCapacity(RobotRepository->elements[0]) == 2);
	*/
	addNewRobot(1, "a", "b", 1, RobotRepository, UndoRedoStackOfFunctionCalls);
	assert(RobotRepository->size == 1);





	assert(getSerialNumber(RobotRepository->elements[0]) == 1);
	assert(strcmp(getState(RobotRepository->elements[0]), "a") == 0);
	assert(strcmp(getSpecialization(RobotRepository->elements[0]), "b") == 0);
	assert(getEnergyCapacity(RobotRepository->elements[0]) == 1);



	addNewRobot(1, "ca", "cb", 12, RobotRepository, UndoRedoStackOfFunctionCalls);//readding the element with the same serialNumber
	assert(RobotRepository->size == 1);

	deleteTheRobotFromTheRepository(1, RobotRepository, UndoRedoStackOfFunctionCalls);
	assert(RobotRepository->size == 0);

	addNewRobot(1, "2", "3", 4, RobotRepository, UndoRedoStackOfFunctionCalls);
	assert(getSerialNumber(RobotRepository->elements[0]) == 1);
	assert(strcmp(getState(RobotRepository->elements[0]), "2") == 0);
	assert(strcmp(getSpecialization(RobotRepository->elements[0]), "3") == 0);
	assert(getEnergyCapacity(RobotRepository->elements[0]) == 4);
	updateRobot(1, "22", "33", 44, RobotRepository, UndoRedoStackOfFunctionCalls);
	assert(getSerialNumber(RobotRepository->elements[0]) == 1);
	assert(strcmp(getState(RobotRepository->elements[0]), "22") == 0);
	assert(strcmp(getSpecialization(RobotRepository->elements[0]), "33") == 0);
	assert(getEnergyCapacity(RobotRepository->elements[0]) == 44);
	assert(checkForExistingRobotBySerial(1, RobotRepository) == 0);
	assert(checkForExistingRobotBySerial(2, RobotRepository) == -1);

	addNewRobot(2, "2", "a", 4, RobotRepository, UndoRedoStackOfFunctionCalls);
	addNewRobot(3, "2", "a", 4, RobotRepository, UndoRedoStackOfFunctionCalls);
	addNewRobot(4, "2", "b", 4, RobotRepository, UndoRedoStackOfFunctionCalls);

	int listOfIndexes[100];
	assert(robotsWithSpecialization("a", listOfIndexes, RobotRepository) == 2);
	assert(checkIfInteger("123") == 1);
	assert(checkIfInteger("-123") == 1);
	assert(checkIfInteger("-123a") == 0);

	assert(RobotRepository->size == 4);
	assert(UndoRedoStackOfFunctionCalls->size == 7);

	UndoFunctionService(RobotRepository, UndoRedoStackOfFunctionCalls);

	assert(RobotRepository->size == 3);
	assert(UndoRedoStackOfFunctionCalls->stackIndex == 6);


	addNewRobot(5, "2", "a", 4, RobotRepository, UndoRedoStackOfFunctionCalls);


	RedoVectorChangeService(RobotRepository, UndoRedoStackOfFunctionCalls);


	UndoFunctionService(RobotRepository, UndoRedoStackOfFunctionCalls);

	assert(RobotRepository->size == 3);
	assert(UndoRedoStackOfFunctionCalls->stackIndex == 6);


	destroyDynamicVector(RobotRepository);
	destroyDynamicVector(UndoRedoStackOfFunctionCalls);
	return;

}