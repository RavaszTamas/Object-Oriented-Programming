#include "DynamicArray.h"
#include <stdio.h>


DynamicVector* createVector(int initialCapacity,destroyFunction destroyElement,copyFunction copyElement)
{
	DynamicVector* newVector = (DynamicVector*)malloc(sizeof(DynamicVector));
	newVector->capacity = initialCapacity;
	newVector->size = 0;
	newVector->elements = (TElem*)malloc(initialCapacity*sizeof(TElem));
	newVector->destroyElement = destroyElement;
	newVector->copyElement = copyElement;
	return newVector;
}

void destroyDynamicVector(DynamicVector* vectorToDestroy)
{
	if(vectorToDestroy == NULL)
		return;
	int i = 0;
	for(i = 0; i < vectorToDestroy->size; i++)
		vectorToDestroy->destroyElement(vectorToDestroy->elements[i]);
	free(vectorToDestroy->elements);
	free(vectorToDestroy);
	return;
}

void destroyDynamicVectorElements(DynamicVector* vectorToDestroy)
{
	if(vectorToDestroy == NULL)
		return;
	int i = 0;
	for(i = 0; i < vectorToDestroy->size; i++)
		vectorToDestroy->destroyElement(vectorToDestroy->elements[i]);
	free(vectorToDestroy->elements);
}

void resizeDynamicVector(DynamicVector* vectorToResize)
{
	vectorToResize->capacity *= 2;
	TElem* newElements = (TElem*)malloc(vectorToResize->capacity*sizeof(TElem));
	int i = 0;
	for(i = 0; i < vectorToResize->size; i++)
	{
		newElements[i] = vectorToResize->elements[i];
	}
	free(vectorToResize->elements);
	vectorToResize->elements = newElements;
}

 void addToVector(DynamicVector* vectorToAddTo, TElem elementToAdd)
 {
	 if(vectorToAddTo->size == vectorToAddTo->capacity)
		 resizeDynamicVector(vectorToAddTo);

	 vectorToAddTo->elements[vectorToAddTo->size++] = vectorToAddTo->copyElement(elementToAdd);
 }

 TElem* removeFromVector(DynamicVector* vectorToRemoveFrom, int indexToRemove)
 {
	 if(indexToRemove >= vectorToRemoveFrom->size || indexToRemove < 0)
		 return 1;

	 int i = 0;
	 TElem* returnElement = vectorToRemoveFrom->copyElement(vectorToRemoveFrom->elements[indexToRemove]);

	 destroyRobot(vectorToRemoveFrom->elements[indexToRemove]);
	 for(i = indexToRemove; i < vectorToRemoveFrom->size-1; i++)
	 {
		 vectorToRemoveFrom->elements[i] = vectorToRemoveFrom->elements[i+1];
	 }
	 vectorToRemoveFrom->size--;
	 return returnElement; 
 }

 TElem* updateElementOfVector(DynamicVector* vectorToUpdate, TElem robotToUpdateWith,int indexToUpdate)
 {
	 int i =0;

	 TElem* returnElement = vectorToUpdate->copyElement(vectorToUpdate->elements[indexToUpdate]);



	 destroyRobot(vectorToUpdate->elements[indexToUpdate]);
	 vectorToUpdate->elements[indexToUpdate] = vectorToUpdate->copyElement(robotToUpdateWith);
	 return returnElement;
 }

 DynamicVector* copyDynamicVector(DynamicVector * vectorToCopy)
 {
	 DynamicVector* copyVector = (DynamicVector*)malloc(sizeof(DynamicVector));
	 if(vectorToCopy->capacity == 0)
	 {
		copyVector->elements = (TElem*)malloc(1*sizeof(TElem));
	 }
	 else
	 {
		copyVector->elements = (TElem*)malloc(vectorToCopy->capacity*sizeof(TElem));
	 }
	 copyVector->capacity = vectorToCopy->capacity;
	 copyVector->copyElement = vectorToCopy->copyElement;
	 copyVector->size = vectorToCopy->size;
	 copyVector->destroyElement = vectorToCopy->destroyElement;

	int i = 0;
	for(i = 0; i < vectorToCopy->size; i++)
		copyVector->elements[i] = vectorToCopy->copyElement(vectorToCopy->elements[i]);

	 return copyVector;
 }

  void overWriteDynamicVector(DynamicVector* vectorToOverWrtie, DynamicVector* copyVector)
  {
	TElem* newElements = (TElem*)malloc(copyVector->capacity*sizeof(TElem));
	int i = 0;
	for(i = 0; i < copyVector->size; i++)
	{
		newElements[i] = copyVector->elements[i];
	}
	free(vectorToOverWrtie->elements);
	vectorToOverWrtie->elements = newElements;
	vectorToOverWrtie->capacity = copyVector->capacity;
	vectorToOverWrtie->size = copyVector->size;
  }


  int getCapacity(DynamicVector* vector)
  {
	  return vector->capacity;
  }

  void ClearRedoStack(DynamicVector* vectorToChange)
  {
	  int i = 0;
	  for(i = vectorToChange->stackIndex; i < vectorToChange->size; i++)
		  vectorToChange->destroyElement(vectorToChange->elements[i]);
	  vectorToChange->size = vectorToChange->stackIndex;
  }