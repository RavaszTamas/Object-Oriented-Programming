#include "FunctionCall.h"
#include <stdio.h>
#include <string.h>

functionCall* createFunctionCall(char* type,TElem* parameter,functionDo redo,functionUndo undo,destroyParameter freeParameter,copyParameter duplicateParameter)
{
	functionCall* newFunction = (functionCall*)malloc(sizeof(functionCall));
	newFunction->parameter = parameter;
	newFunction->redo = redo;
	newFunction->undo = undo;
	newFunction->freeParameter = freeParameter;
	newFunction->duplicateParameter = duplicateParameter;
	newFunction->type = (char*)malloc(sizeof(char)*(strlen(type)+1));
	strcpy(newFunction->type,type);

	return newFunction;
}

void destroyFunctionCall(functionCall* function)
{
	free(function->type);
	if(function->freeParameter == NULL)//if the parameter has no need for a special destroy function e.g it is an int or char or a struct with no allocated memory
		free(function->parameter);
	else
		function->freeParameter(function->parameter);
	free(function);
	return;
}

functionCall* copyFunctionCall(functionCall* function)
{
	functionCall* newFunction = (functionCall*)malloc(sizeof(functionCall));
	newFunction->parameter = function->duplicateParameter(function->parameter);
	newFunction->redo = function->redo;
	newFunction->undo = function->undo;
	newFunction->freeParameter = function->freeParameter;
	newFunction->type = (char*)malloc(sizeof(char)*(strlen(function->type)+1));
	strcpy(newFunction->type,function->type);

	return newFunction;
}

