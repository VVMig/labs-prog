#include "TernaryVector.h"
#include <iostream>

using namespace std;

TernaryVector::TernaryVector(const TernaryVector& oth)
{
	this->size = oth.size;
	this->vectors = new int[oth.size];

	for (int i = 0; i < this->size; i++)
	{
		this->vectors[i] = oth.vectors[i];
	}
}

TernaryVector& TernaryVector::operator=(TernaryVector oth)
{
	this->vectors = new int[oth.size];
	this->size = oth.size;

	for (int i = 0; i < size; i++)
	{
		this->vectors[i] = oth.vectors[i];
	}

	return *this;
}

TernaryVector TernaryVector::operator&(TernaryVector& oth)
{
	TernaryVector tmp;

	if (this->ort(oth)) {
		return tmp;
	}

	if (size > oth.size) {
		tmp = *this;

		for (int i = 0; i < oth.size; i++)
		{
			if (vectors[i] == oth.vectors[i]) tmp.vectors[i] = vectors[i];
			else if (vectors[i] * oth.vectors[i] == 0) tmp.vectors[i] = 0;
			else if (vectors[i] * oth.vectors[i] == 2) tmp.vectors[i] = 1;
		}
	}
	else {
		tmp = *this;

		for (int i = 0; i < size; i++)
		{
			if (vectors[i] == oth.vectors[i]) tmp.vectors[i] = vectors[i];
			else if (vectors[i] * oth.vectors[i] == 0) tmp.vectors[i] = 0;
			else if (vectors[i] * oth.vectors[i] == 2) tmp.vectors[i] = 1;
		}
	}

	return tmp;
}

int TernaryVector::operator[](int a)
{
	return a >= 0 && a < size ? vectors[a] : -1;
}

bool TernaryVector::ort( const TernaryVector& b)
{
	bool one = false, zero = false;

	for (int i = 0; i < size; i++)
	{
		one = vectors[i] == 1 ? true : zero;
		zero = vectors[i] == 0 ? true : zero;
	}

	for (int i = 0; i < b.size; i++)
	{
		if (b.vectors[i] == 1 && zero) return true;
		if (b.vectors[i] == 0 && one) return true;
	}

	return false;
}

void TernaryVector::show()
{
	cout << "[ ";
	for (int i = 0; i < this->size; i++)
	{
		cout << this->vectors[i];

		if (i != size - 1) 
			cout << ", ";
	}
	cout << " ]" << endl;
}

int TernaryVector::undefinedComponents()
{
	int res = 0;

	for (int i = 0; i < size; i++)
	{
		res += vectors[i] == 2 ? 1 : 0;
	}

	return res;
}

void TernaryVector::setVectors(int vectors[], int size)
{
	this->vectors = new int[size];
	this->size = size;

	for (int i = 0; i < size; i++)
	{
		this->vectors[i] = vectors[i] % 3;
	}
}


