#pragma once
#include "Domain.h"

typedef void* TElem;
typedef void(*destroyFunction)(TElem);
typedef TElem(*copyFunction)(TElem);

typedef struct
{
	int capacity;
	int size;
	int stackIndex;
	TElem* elements;
	destroyFunction destroyElement;
	copyFunction copyElement;

}DynamicVector;

 DynamicVector* createVector(int initialCapacity,destroyFunction destroyElement,copyFunction copyElement);

 void destroyDynamicVector(DynamicVector* vectorToDestroy);

 void resizeDynamicVector(DynamicVector* vectorToResize);

 void addToVector(DynamicVector* vectorToAddTo, TElem elementToAdd);

 void removeFromVector(DynamicVector* vectorToRemoveFrom, int indexToRemove);

 void updateElementOfVector(DynamicVector* vectorToUpdate, TElem robotToUpdateWith,int indexToUpdate);

 DynamicVector* copyDynamicVector(DynamicVector* vectorToCopy);

 void overWriteDynamicVector(DynamicVector* vectorToOverWrtie, DynamicVector* copyVector);

 int getCapacity(DynamicVector* vector);

 void ClearRedoStack(DynamicVector* vectorToChange);

 void destroyDynamicVectorElements(DynamicVector* vectorToDestroy);
