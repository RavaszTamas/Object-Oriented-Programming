#include <iostream>
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include "Repository.h"
#include "TextFileRepo.h"
#include "Service.h"
#include "UI.h"
#include <fstream>
#include "test.h"
#define _CRTDBG_MAP_ALLOC

void run()
{
	PlantFileRepository repository;
	Validator validator;
	AppController controller{ repository, validator };
	Console console{controller};
	console.run();
}

int main()
{	


	testAll();

	run();
	_CrtDumpMemoryLeaks();


	return 0;
}