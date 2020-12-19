#include "String.h"
#include <cstring>
#include <Windows.h>
#include <iostream>
#include <fstream>

using namespace std;

char* toString(char* str, int num) {
	char symb = 'a';
	int length = 0;
	bool minus = num > 0 ? false : true;

	for (int i = num; i != 0; i /= 10)
	{
		length++;
	}

	if (minus) {
		length++;
		num *= -1;
	}

	str = new char[length + 1];

	for (int i = num, j = minus ? 1 : 0; i != 0; i /= 10, j++)
	{
		switch (i % 10) {
		case 0:
			symb = '0';
			break;
		case 1:
			symb = '1';
			break;
		case 2:
			symb = '2';
			break;
		case 3:
			symb = '3';
			break;
		case 4:
			symb = '4';
			break;
		case 5:
			symb = '5';
			break;
		case 6:
			symb = '6';
			break;
		case 7:
			symb = '7';
			break;
		case 8:
			symb = '8';
			break;
		case 9:
			symb = '9';
			break;
		default:
			break;
		}
		str[j] = symb;
	}

	str[length] = '\0';

	for (int i = minus ? 1 : 0, j = length - 1; i < j; i++, j--)
	{
		symb = str[i];
		str[i] = str[j];
		str[j] = symb;
	}

	if (minus) str[0] = '-';

	return str;
}

char* toString(char* str, double num) {
	double tmpNum = 0;
	int point = 0;

	for (int i = (int)ceil(num); i != 0; i /= 10, point++)
	{
	}

	for (tmpNum = num; tmpNum != (int)tmpNum; tmpNum *= 10)
	{
	}
	

	str = toString(str, (int)tmpNum);
	int length = strlen(str) + 2;
	char* tmp = new char[length];

	for (int i = 0, j=0; str[i]; i++, j++)
	{
		if (i == point) {
			tmp[j] = '.';
			j++;
		}
		tmp[j] = str[i];
	}

	tmp[length-1] = '\0';

	return tmp;
}

String::String() {
	this->str = new char;
	this->n = 0;
	this->Length = n;

	try
	{
		if (!str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
}

int String::getLength() {
	return this->n;
}

char* String::c_str() {
	return this->str;
}

String::String(const String& oth) {
	this->n = oth.n;
	this->str = new char[this->n + 1];
	this->Length = oth.Length;

	try
	{
		if (!str) throw "Error!No memory";
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
	}

	for (int i = 0; oth.str[i]; i++)
	{
		this->str[i] = oth.str[i];
	}

	this->str[this->Length] = '\0';

}

String::String(const char* str) {
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
	this->Length = n;
}

String::String(int num) {
	str = toString(str, num);
	this->n = strlen(this->str);
	this->Length = n;

	try
	{
		if (!str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
}

String::String(double num) {
	this->str = toString(this->str, num);
	this->n = strlen(this->str);
	this->Length = n;

	try
	{
		if (!str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
}

String::String(const bool str) {
	if (str) {
		n = 4;

		this->str = new char[n + 1];
		strcpy_s(this->str, n + 1, "true");
	}
	else {
		n = 5;

		this->str = new char[n + 1];
		strcpy_s(this->str, n + 1, "false");
	}
	this->Length = n;

	try
	{
		if (!str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
}

String& String::operator =(const char* oth) {
	this->str = new char[strlen(oth) + 1];
	this->n = strlen(oth);
	this->Length = n;

	try
	{
		if (!str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	strcpy_s(str, n + 1, oth);
	
	return *this;
}

String& String::operator =(const String& oth) {
	this->n = oth.n;
	this->str = new char[oth.n + 1];
	this->Length = oth.Length;

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

	return *this;
}

String String::operator +(String& oth) {
	String tmp;
	int j = 0;

	tmp.n = this->n + oth.n;
	tmp.Length = tmp.n;
	tmp.str = new char[tmp.n + 1];

	try
	{
		if (!tmp.str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	for (int i = 0; i < this->n; i++, j++)
	{
		tmp.str[j] = this->str[i];
	}

	for (int i = 0; oth.str[i]; i++, j++)
	{
		tmp.str[j] = oth.str[i];
	}

	tmp.str[tmp.n] = '\0';

	return tmp;
}

String& String::operator +=(String& oth) {
	String tmp;
	int j = 0;

	tmp.n = this->n + oth.n;
	tmp.Length = tmp.n;
	tmp.str = new char[tmp.n + 1];

	try
	{
		if (!tmp.str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	for (int i = 0; i < this->n; i++, j++)
	{
		tmp.str[j] = this->str[i];
	}

	for (int i = 0; oth.str[i]; i++, j++)
	{
		tmp.str[j] = oth.str[i];
	}

	tmp.str[tmp.n] = '\0';
	*this = tmp;

	return *this;
}

bool String::operator==(String& oth) {
	return !strcmp(this->str, oth.str);
}

bool String::operator!=(String& oth) {
	return strcmp(this->str, oth.str);
}

String String::operator +(const char* oth) {
	String tmp;
	int j = 0;

	tmp.n = this->n + strlen(oth);
	tmp.Length = tmp.n;
	tmp.str = new char[tmp.n + 1];

	try
	{
		if (!tmp.str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	for (int i = 0; i < this->n; i++, j++)
	{
		tmp.str[j] = this->str[i];
	}

	for (int i = 0; oth[i]; i++, j++)
	{
		tmp.str[j] = oth[i];
	}

	tmp.str[tmp.n] = '\0';

	return tmp;
}

String& String::operator +=(const char* oth) {
	String tmp;
	int j = 0;

	tmp.n = this->n + strlen(oth);
	tmp.Length = tmp.n;
	tmp.str = new char[tmp.n + 1];

	try
	{
		if (!tmp.str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	for (int i = 0; i < this->n; i++, j++)
	{
		tmp.str[j] = this->str[i];
	}

	for (int i = 0; oth[i]; i++, j++)
	{
		tmp.str[j] = oth[i];
	}

	tmp.str[tmp.n] = '\0';
	*this = tmp;

	return *this;
}

bool String::operator==(const char* oth) {
	return !strcmp(this->str, oth);
}

bool String::operator!=(const char* oth) {
	return strcmp(this->str, oth);
}

char String::operator [](int i) {
	char result;

	try
	{
		result = this->str[i];
		if (i < 0 || i > this->n - 1) {
			throw exception::exception("ошибка в доступе к элементу");
		}
		return result;
	}
	catch (const std::exception&err)
	{
		cout << err.what() << endl;
		exit(-1);
	} 
}

std::ostream& operator<< (std::ostream& out, String& oth) {

	for (int i = 0; oth.str[i]; i++)
	{
		out << oth.str[i];
	}
	return out;
}

std::istream& operator>> (std::istream& in, String& oth) {
	char a[1000];

	in>>a;
	

	oth.n = oth.Length = strlen(a);
	oth.str = new char[oth.n + 1];

	try
	{
		if (!oth.str) throw "Error!No memory";
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	strcpy_s(oth.str, oth.n + 1, a);
	
	return in;
}

std::ifstream& operator>> (std::ifstream& in, String& oth){
	char a[1000];
	
	in >> a;

	oth += a;

	return in;
}

std::ofstream& operator<< (std::ofstream& out, String& oth) {
	out << oth.c_str();

	return out;
}


String::~String() {
	delete[] this->str;
}