#pragma once
//Data structure representing a robot with
// an integer as a serial number
// a string of characters as the state and specialization
// the energy capacity as an integer
typedef struct
{
	int serialNumber;
	char* state;
	char* specialization;
	int energyCapacity;
}Robot;
typedef int(*valueGetter)(Robot*);
typedef int(*relationFunctionState)(void*, void*, valueGetter);

int compareEnergyCapacityBigger(void* elementOne, void* elementTwo, valueGetter getValue);

int compareEnergyCapacitySmaller(void* elementOne, void* elementTwo, valueGetter getValue);


int getSerialNumber(Robot* robot);

char* getState(Robot* robot);

char* getSpecialization(Robot* robot);

int getEnergyCapacity(Robot* robot);

Robot* createRobot(int serialNumber,char* state, char* specialization, int energyCapacity);

void destroyRobot(Robot* robotToDestroy);

Robot* copyRobot(Robot* robotToCopy);

void robotToString(Robot* robotToConvert,char* string);

