#pragma once
typedef void* TElem;
typedef void(*functionDo)(TElem*);
typedef void(*functionUndo)(TElem*);
typedef void(*destroyParameter)(TElem*);
typedef TElem*(*copyParameter)(TElem*);

typedef struct
{
	char* type;
	TElem* parameter;
	functionDo redo;
	functionUndo undo;
	destroyParameter freeParameter;
	copyParameter duplicateParameter;
	
}functionCall;

functionCall* createFunctionCall(char* type,TElem* parameter,functionDo redo,functionUndo undo,destroyParameter freeParameter,copyParameter duplicateParameter);

void destroyFunctionCall(functionCall* function);

functionCall* copyFunctionCall(functionCall* function); 