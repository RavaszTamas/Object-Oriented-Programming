#pragma once
//Data structure representing a robot with
// an integer as a serial number
// a string of characters as the state and specialization
// the energy capacity as an integer
typedef struct
{
	int serialNumber;
	char state[50];
	char specialization[50];
	int energyCapacity;
}Robot;

char* getState(Robot* robot);

char* getSpecialization(Robot* robot);

int compareState(Robot* robotOne, Robot* robotTwo);

int compareSpecialization(Robot* robotOne, Robot* robotTwo);