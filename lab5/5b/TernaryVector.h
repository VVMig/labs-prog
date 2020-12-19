#pragma once
#include "Vector.h"

class TernaryVector:public Vector
{

public:
	TernaryVector() :Vector() {}
	TernaryVector(int vectors[], int size) :Vector(vectors, size) {
		for (int i = 0; i < size; i++)
		{
			this->vectors[i] %= 3;
		}
	}
	TernaryVector(const TernaryVector& oth);
	TernaryVector& operator=(TernaryVector oth);
	TernaryVector operator&(TernaryVector& oth);
	int operator[](int a);
	bool ort(const TernaryVector& b);
	void show();
	int undefinedComponents();
	void setVectors(int vectors[], int size);
};

