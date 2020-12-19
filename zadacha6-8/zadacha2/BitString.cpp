#include "BitString.h"
#include <cstring>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

bool checkPrev(const char* a) {

	if (a[0] == '1') {
		for (int i = 1; a[i]; i++)
		{
			if (a[i] == '1') return false;
		}
		return true;
	}

	return false;
}

char* reverse(const char* a) {
	char* tmp;
	tmp = new char[strlen(a) + 1];

	for (int i = strlen(a) - 1,j = 0; a[i]; i--,j++)
	{
		tmp[j] = a[i];
	}

	tmp[strlen(a)] = '\0';

	return tmp;
}

BitString::BitString() {
	this->str = new char[9];
	this->n = 8;

	try
	{
		if (!str) throw exception("Error!No memory");
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}


	for (size_t i = 0; i < n; i++)
	{
		this->str[i] = '0';
	}

	this->str[n] = '\0';
}

char* BitString::c_str() {
	return this->str;
}

BitString::BitString(const BitString& oth) {
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

BitString::BitString(const char* a)
{
	this->str = new char[9];
	this->n = 8;

	try
	{
		if (!str) throw exception("Error!No memory");
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}

	for (int j = 0;j < 8; j++)
	{
		str[j] = (j >= strlen(a)) ? '0' : a[j] == '0' ? '0' : '1';
	}

	str[n] = '\0';

	for (int i = 0,j=n-1; i < j; i++,j--)
	{
		swap(str[i], str[j]);
	}
}

BitString& BitString::operator =(const BitString& oth) {
	this->n = oth.n;
	this->str = new char[oth.n + 1];

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

BitString& BitString:: operator =(const char*a) {
	BitString oth(a);

	this->n = oth.n;
	this->str = new char[oth.n + 1];

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


BitString BitString::operator+(BitString& oth) {
	BitString tmp;
	bool mem=false;

	for (int i = n - 1;i>=0; i--)
	{
		if (mem && (oth.str[i]=='0' && str[i]=='0')) {
			tmp.str[i] = '1';
			mem = false;
			continue;
		}
		else if (mem && (oth.str[i] == '1' && str[i] == '1')) {
			tmp.str[i] = '1';
			mem = true;
			continue;
		}
		else if(mem){
			tmp.str[i] = '0';
			mem = true;
			continue;
		}

		if (oth.str[i] == '1' && str[i] == '1') mem = true;
		tmp.str[i] = (oth.str[i] == '1' && str[i] == '1') || (oth.str[i] == '0' && str[i] == '0') ? '0' : '1';
	}

	return tmp;
}

BitString BitString::operator +(const char*a) {
	BitString tmp, oth(a);
	bool mem = false;

	for (int i = n - 1; i >= 0; i--)
	{
		if (mem && (oth.str[i] == '0' && str[i] == '0')) {
			tmp.str[i] = '1';
			mem = false;
			continue;
		}
		else if (mem && (oth.str[i] == '1' && str[i] == '1')) {
			tmp.str[i] = '1';
			mem = true;
			continue;
		}
		else if (mem) {
			tmp.str[i] = '0';
			mem = true;
			continue;
		}

		if (oth.str[i] == '1' && str[i] == '1') mem = true;
		tmp.str[i] = (oth.str[i] == '1' && str[i] == '1') || (oth.str[i] == '0' && str[i] == '0') ? '0' : '1';
	}

	return tmp;
}

BitString BitString::operator&(BitString&oth)
{
	BitString tmp;
	
	for (int i = n-1; i >= 0; i--)
	{
		tmp.str[i] = oth.str[i] == '1' && str[i] == '1' ? '1' : '0';
	}

	return tmp;
}

BitString BitString::operator|(BitString&oth)
{
	BitString tmp;

	for (int i = n - 1; i >= 0; i--)
	{
		tmp.str[i] = oth.str[i] == '1' || str[i] == '1' ? '1' : '0';
	}

	return tmp;
}

BitString BitString::operator^(BitString&oth)
{
	BitString tmp;

	for (int i = n - 1; i >= 0; i--)
	{
		tmp.str[i] = oth.str[i] == str[i] ? '0' : '1';
	}

	return tmp;
}

BitString BitString::operator!()
{
	BitString tmp(reverse(this->str));

	for (int i = 0; i < n; i++)
	{
		tmp.str[i] = tmp.str[i] == '1' ? '0' : '1';
	}

	return tmp;
}

BitString BitString::operator<<(int a)
{
	BitString tmp(reverse(this->c_str()));

	for (int j=0, i = n - 1; j<a;j++,i--)
	{
		if (checkPrev(tmp.c_str())) {
			tmp.str[i] = '0';
			tmp.str[n-1] = '1';
			i = n;
			continue;
		}
		
		for (int k = 0; k<n-1; k++)
		{
			tmp.str[k] = tmp.str[k + 1];
		}
		tmp.str[i] = '0';
	}

	return tmp;
}

BitString BitString::operator>>(int a)
{
	BitString tmp(reverse(this->c_str()));

	for (int j = 0, i = 0; j < a; j++, i++)
	{

		for (int k = n - 1; k > 0; k--)
		{
			tmp.str[k] = tmp.str[k - 1];
		}
		tmp.str[i] = '0';
	}

	return tmp;
}


char BitString::operator [](int i) {
	char result;

	try
	{
		result = this->str[i];
		if (i < 0 || i > this->n - 1) {
			throw exception::exception("ошибка в доступе к элементу");
		}
		return result;
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
		exit(-1);
	}
}

std::ostream& operator<< (std::ostream& out, BitString& oth) {

	for (int i = 0; oth.str[i]; i++)
	{
		out << oth.str[i];
	}
	return out;
}

std::istream& operator>> (std::istream& in, BitString& oth) {
	char a[1000];

	in >> a;


	oth.n = strlen(a);
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

BitString::~BitString() {
	delete[] this->str;
}
