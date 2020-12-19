#pragma once
#include <iostream>
#include <string>

using namespace std;

class Array
{
protected:
	char* str;
public:
	Array() {
		str = new char;
	}
	Array(const char*a) {
		str = new char[strlen(a) + 1];
		strcpy_s(str, strlen(a) + 1, a);
	}
	Array(unsigned int a) {
		str = new char[strlen(to_string(a).c_str()) + 1];
		strcpy_s(str, strlen(to_string(a).c_str()) + 1, to_string(a).c_str());
	}
	Array(const Array& oth) {
		str = new char[strlen(oth.str) + 1];

		for (int i = 0; oth.str[i]; i++)
		{
			str[i] = oth.str[i];
		}

		str[strlen(oth.str)] = '\0';
	}
	char operator[](int i) {
		return str[i];
	}
	friend ostream& operator << (ostream& out,const Array& oth) {
		out << oth.str;

		return out;
	}
	~Array() {
		delete[] str;
	}
};

