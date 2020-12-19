#pragma once
#include "Array.h"
#include <iostream>

using namespace std;

class Decimal:public Array
{
public:
	Decimal(const char* a) :Array(a) {
		for (int i = 0; a[i]; i++)
		{
			try
			{
				if (a[i] < '0' || a[i] >'9')
					throw "It's must be a decimal unsigned integer";
			}
			catch (const char* str)
			{
				cout << str << endl;
				exit(-1);
			}
		}
	}
	Decimal(unsigned int a = 1):Array(a){}
	bool operator != (const Decimal& oth) {
		return atoi(str) != atoi(oth.str) ? true : false;
	}
	bool operator == (const Decimal& oth) {
		return atoi(str) == atoi(oth.str) ? true : false;
	}
	bool operator > (const Decimal& oth) {
		return atoi(str) > atoi(oth.str) ? true : false;
	}
	bool operator < (const Decimal& oth) {
		return atoi(str) < atoi(oth.str) ? true : false;
	}
	Decimal operator + (const Decimal& oth) {
		Decimal tmp(atoi(str) + atoi(oth.str));

		return tmp;
	}
	Decimal operator - (const Decimal& oth) {
		try
		{
			if (*this < oth) {
				throw "It is unsigned class!!!";
			}
		}
		catch (const char*err)
		{
			cout << err << endl;
			return *this;
		}

		Decimal tmp(atoi(str) - atoi(oth.str));

		return tmp;
	}
	Decimal operator * (const Decimal& oth) {
		Decimal tmp(atoi(str) * atoi(oth.str));

		return tmp;
	}
	Decimal operator / (const Decimal& oth) {
		Decimal tmp(atoi(str) / atoi(oth.str));

		return tmp;
	}
	Decimal& operator = (const Decimal& oth) {
		str = new char[strlen(oth.str) + 1];
		int i = 0;
		for (i; oth.str[i]; i++)
		{
			str[i] = oth.str[i];
		}
		str[i] = '\0';

		return *this;
	}
	char* show() {
		return str;
	}
};

