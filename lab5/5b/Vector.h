#pragma once
class Vector
{
protected:
	int size;
	int* vectors = nullptr;
public:
	Vector() : size(0) {}
	Vector(const Vector& oth);
	Vector(int vectors[], int size);
	int getSize();
	int* getVectors();
	virtual void setVectors(int vectors[], int size) = 0;
	virtual void show() = 0;
	~Vector();
};

