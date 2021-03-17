#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "UI.h"
#include "DynamicArray.h"
#include "Test.h"

int main()
{
	//testAll();
	//testUndoRedoFunctionCalls();
	UI();
    _CrtDumpMemoryLeaks();
	return 0;
}