#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	int n = 0;
	char* str;

public:
	int Length = 0;
	String();
	String(const char*);
	String(int);
	String(double);
	String(const bool);
	String(const String& oth);
	int getLength();
	char* c_str();
	String& operator =(const char*);
	String& operator =(const String&);
	String operator +(String&);
	String& operator +=(String&);
	bool operator ==(String&);
	bool operator !=(String&);
	String operator +(const char*);
	String& operator +=(const char*);
	bool operator ==(const char*);
	bool operator !=(const char*);
	char operator [](int i);
	friend std::ostream& operator<< (std::ostream& out, String& oth);
	friend std::istream& operator>> (std::istream& in, String& oth);
	friend std::ofstream& operator<< (std::ofstream& out, String& oth);
	friend std::ifstream& operator>> (std::ifstream& in, String& oth);

	~String();
};

