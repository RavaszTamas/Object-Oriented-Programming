#include "FunctionCall.h"
#include <stdio.h>
#include <string.h>

functionCall* createFunctionCall(char* type,TElem* parameterUndo,TElem* parameterRedo,destroyParameter freeParameterUndo,destroyParameter freeParameterRedo,copyParameter duplicateParameterUndo, copyParameter duplicateParameterRedo)
{
	functionCall* newFunction = (functionCall*)malloc(sizeof(functionCall));
	newFunction->duplicateParameterUndo = duplicateParameterUndo;
	newFunction->duplicateParameterRedo = duplicateParameterRedo;
	newFunction->parameterUndo = duplicateParameterUndo(parameterUndo);
	newFunction->parameterRedo = duplicateParameterRedo(parameterRedo);
	newFunction->freeParameterUndo = freeParameterUndo;
	newFunction->freeParameterRedo= freeParameterRedo;
	newFunction->type = (char*)malloc(sizeof(char)*(strlen(type)+1));
	strcpy(newFunction->type,type);

	return newFunction;
}

void destroyFunctionCall(functionCall* function)
{
	free(function->type);
	function->freeParameterUndo(function->parameterUndo);
	function->freeParameterRedo(function->parameterRedo);
	free(function);
	return;
}

functionCall* copyFunctionCall(functionCall* function)
{
	functionCall* newFunction = (functionCall*)malloc(sizeof(functionCall));
	newFunction->parameterUndo = function->duplicateParameterUndo(function->parameterUndo);
	newFunction->parameterRedo = function->duplicateParameterRedo(function->parameterRedo);
	newFunction->freeParameterUndo = function->freeParameterUndo;
	newFunction->freeParameterRedo = function->freeParameterRedo;
	newFunction->type = (char*)malloc(sizeof(char)*(strlen(function->type)+1));
	strcpy(newFunction->type,function->type);

	return newFunction;
}


char* getType(functionCall* function)
{
	return function->type;
}

TElem* getParameterUndo(functionCall * function)
{
	return function->parameterUndo;
}

TElem* getParameterRedo(functionCall * function)
{
	return function->parameterRedo;
}

int* duplicateInteger(int* elementToDuplicate)
{
	int* newInt = (int*)malloc(sizeof(int)*1);
	*newInt = *elementToDuplicate;
	return  newInt;
}

void deleteInteger(int* elementToDelete)
{
	free(elementToDelete);
	return;
}