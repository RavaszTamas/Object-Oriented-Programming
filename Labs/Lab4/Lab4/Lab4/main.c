#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "UI.h"
//#include "Test.h"

int main()
{
	//testAll();
	UI();
    _CrtDumpMemoryLeaks();
	return 0;
}