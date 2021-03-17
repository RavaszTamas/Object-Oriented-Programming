#include <iostream>
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"
#include "Repository.h"
#include "Service.h"
#include "UI.h"
#define _CRTDBG_MAP_ALLOC

void run()
{
	DynamicVector<Plant> malac{1};
	PlantRepository repository;
	Validator validator;
	AppController controller{ repository, validator };
	Console console{controller};
	console.run();
}

int main()
{	


	//console.run();

	run();
	_CrtDumpMemoryLeaks();



	return 0;
}