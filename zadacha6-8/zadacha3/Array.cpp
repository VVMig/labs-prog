#include "Array.h"
#include <iostream>

using namespace std;

Array::Array() {
	str = new char;
	n = 1;
}
Array::Array(const Array& oth) {
	this->n = oth.n;
	this->str = new char[this->n + 1];

	try
	{
		if (!str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	for (int i = 0; oth.str[i]; i++)
	{
		this->str[i] = oth.str[i];
	}

	this->str[this->n] = '\0';
}

const char* Array::c_str() {
	return str;
}

Array::Array(const char* str) {
	this->n = strlen(str);
	this->str = new char[n + 1];

	try
	{
		if (!str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	strcpy_s(this->str, n + 1, str);
}
const char& Array::operator[](int a) {
	try
	{
		if (a < 0 || a >= n)
			throw exception("Index does not exist");
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
		return '\0';
	}

	return str[a];
}
void Array::addElement(const char* oth) {
	int j = 0;

	int newN = this->n + strlen(oth);
	char* newStr = new char[newN + 1];

	try
	{
		if (!newStr) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	for (int i = 0; i < this->n; i++, j++)
	{
		newStr[j] = this->str[i];
	}

	for (int i = 0; oth[i]; i++, j++)
	{
		newStr[j] = oth[i];
	}

	newStr[newN] = '\0';

	str = new char[newN + 1];
	n = newN;
	strcpy_s(str, n + 1, newStr);
}
ostream& operator<< (std::ostream& out, Array& oth) {

	for (int i = 0; oth.str[i]; i++)
	{
		out << oth.str[i];
	}
	return out;
}

Array::~Array() {
	delete[] str;
}