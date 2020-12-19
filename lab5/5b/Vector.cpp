#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector(const Vector& oth)
{
	this->size = oth.size;
	this->vectors = new int[oth.size];

	for (int i = 0; i < size; i++)
	{
		this->vectors[i] = oth.vectors[i];
	}
}

Vector::Vector(int vectors[], int size)
{
	this->size = size;
	this->vectors = new int[size];

	for (int i = 0; i < size; i++)
	{
		this->vectors[i] = vectors[i];
	}
}

int Vector::getSize()
{
	return this->size;
}

int* Vector::getVectors()
{
	return this->vectors;
}

Vector::~Vector()
{
	delete[] vectors;
}
