#pragma once
#include <iostream>

using namespace std;

class Array
{
protected:
	int n = 0;
	char* str;
public:
	Array();
	Array(const Array& oth);
	const char* c_str();
	Array(const char* str);
	const char& operator[](int a);
	virtual void addElement(const char* oth);
	friend ostream& operator<< (std::ostream& out, Array& oth);
	int getN() {
		return n;
	}

	~Array();
};

