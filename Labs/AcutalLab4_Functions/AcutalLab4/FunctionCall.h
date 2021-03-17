#pragma once
typedef void* TElem;
typedef void(*destroyParameter)(TElem*);
typedef TElem*(*copyParameter)(TElem*);

typedef struct
{
	char* type;
	TElem* parameterUndo;
	TElem* parameterRedo;
	destroyParameter freeParameterUndo;
	destroyParameter freeParameterRedo;
	copyParameter duplicateParameterUndo;
	copyParameter duplicateParameterRedo;
	
}functionCall;

char* getType(functionCall* function);

TElem* getParameterUndo(functionCall* function);

TElem* getParameterRedo(functionCall* function);


functionCall* createFunctionCall(char* type,TElem* parameterUndo,TElem* parameterRedo,destroyParameter freeParameterUndo,destroyParameter freeParameterRedo,copyParameter duplicateParameterUndo, copyParameter duplicateParameterRedo);

void destroyFunctionCall(functionCall* function);

functionCall* copyFunctionCall(functionCall* function); 


int* duplicateInteger(int* elementToDuplicate);

void deleteInteger(int* elementToDelete);
