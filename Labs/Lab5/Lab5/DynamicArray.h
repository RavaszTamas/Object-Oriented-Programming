#pragma once
#include "Domain.h"
/*
Template for a dynamic array, a vector like structure
*/
template <typename TYPE>
class DynamicVector
{
private:
	TYPE* elements;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector();

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& vector);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& vector);

	/*
	Overloading the subscript operator
	Input: position - a valid position within the dynamic array.
	Output: a reference to the element on the given position.
	*/
	TYPE& operator[](int position);

	// Adds an element to the current dynamic vector.
	void add(TYPE newElement);

	// Removes an element from the dynamic vector from the position indexToRemove
	// the position must be valid otherwise an exception is thrown
	void remove(int indexToRemove);

	// Updates an element from the dynamic vector from the position indexToRemove
	// the position must be valid otherwise an exception is thrown
	void update(int indexToUpdate, TYPE&);

	//Returns the value of the size of the vector
	int getSize() const;

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};

template <typename TYPE>
DynamicVector<TYPE>::DynamicVector()
{
	this->size = 0;
	int capacity = 10;
	if (capacity <= 0)
		capacity = 10;
	this->capacity = capacity;
	this->elements = new TYPE[capacity];
}

template<typename TYPE>
DynamicVector<TYPE>::DynamicVector(const DynamicVector & vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elements = new TYPE[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = vector.elements[i];
}

template<typename TYPE>
DynamicVector<TYPE>::~DynamicVector()
{
	delete[] this->elements;

}

template<typename TYPE>
DynamicVector<TYPE> & DynamicVector<TYPE>::operator=(const DynamicVector & vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;

	TYPE* auxilliaryArray = new TYPE[this->capacity];

	delete[] this->elements;


	this->elements = auxilliaryArray;

	for (int i = 0; i < this->size; ++i)
	{
		this->elements[i] = vector.elements[i];
	}

	return *this;
}


template<typename TYPE>
TYPE & DynamicVector<TYPE>::operator[](int position)
{
	return this->elements[position];
}

template<typename TYPE>
void DynamicVector<TYPE>::add(TYPE newElement)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size++] = newElement;

}

template<typename TYPE>
void DynamicVector<TYPE>::remove(int indexToRemove)
{
	if (indexToRemove < 0)
		throw "Invalid index!";

	for (int i = indexToRemove; i < this->size; ++i)
		this->elements[i] = this->elements[i + 1];
	this->size--;
}

template<typename TYPE>
inline void DynamicVector<TYPE>::update(int indexToUpdate, TYPE & elementToUpdateWith)
{
	if (indexToUpdate < 0)
		throw "Invalid index";
	this->elements[indexToUpdate] = elementToUpdateWith;
}

template<typename TYPE>
int DynamicVector<TYPE>::getSize() const
{
	return this ->size;
}

template<typename TYPE>
void DynamicVector<TYPE>::resize(double factor)
{
	this->capacity *= factor;

	TYPE* newElements = new TYPE[this->capacity];
	for (int i = 0; i < this->size; i++)
		newElements[i] = this->elements[i];

	delete[] this->elements;
	this->elements = newElements;

}

