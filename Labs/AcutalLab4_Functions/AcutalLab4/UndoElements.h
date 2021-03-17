#pragma once
typedef void* TElem;
typedef void(*addToVector)(TElem);

typedef struct
{
	int argumentCount;
	char** argumentToExecute;

}FunctionCall;