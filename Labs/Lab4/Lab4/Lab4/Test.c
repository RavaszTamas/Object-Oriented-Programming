#include "Test.h"
#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include <assert.h>
#include "validator.h"
void testAll()
{
	Robot RobotRepository[100];
	int lengthOfRobotRepository = 0;
	addNewRobot("1","a","b","1",RobotRepository,&lengthOfRobotRepository);
	assert(lengthOfRobotRepository == 1);
	addNewRobot("1","ca","cb","12",RobotRepository,&lengthOfRobotRepository);
	assert(lengthOfRobotRepository == 1);
	deleteTheRobotFromTheRepository("1",RobotRepository,&lengthOfRobotRepository);
	assert(lengthOfRobotRepository == 0);
	addNewRobot("1","2","3","4",RobotRepository,&lengthOfRobotRepository);
	assert(RobotRepository[0].serialNumber == 1);
	assert(strcmp(RobotRepository[0].state,"2") == 0);
	assert(strcmp(RobotRepository[0].specialization,"3") == 0);
	assert(RobotRepository[0].energyCapacity == 4);
	updateRobot("1","22","33","44",RobotRepository,&lengthOfRobotRepository);
	assert(RobotRepository[0].serialNumber == 1);
	assert(strcmp(RobotRepository[0].state,"22") == 0);
	assert(strcmp(RobotRepository[0].specialization,"33") == 0);
	assert(RobotRepository[0].energyCapacity == 44);
	assert(checkForExistingRobotBySerial(1,RobotRepository,&lengthOfRobotRepository) == 1);
	assert(checkForExistingRobotBySerial(2,RobotRepository,&lengthOfRobotRepository) == 0);
	
	addNewRobot("2","2","a","4",RobotRepository,&lengthOfRobotRepository);
	addNewRobot("3","2","a","4",RobotRepository,&lengthOfRobotRepository);
	addNewRobot("4","2","b","4",RobotRepository,&lengthOfRobotRepository);
	int listOfIndexes[100];
	assert(robotsWithSpecialization("a",listOfIndexes,RobotRepository,&lengthOfRobotRepository) == 2);
	assert(checkIfInteger("123") == 1);
	assert(checkIfInteger("-123") == 1);
	assert(checkIfInteger("-123a") == 0);

}
