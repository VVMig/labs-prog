#pragma once
#include "Array.h"
#include <string>

using namespace std;

class BitString:public Array
{
public:
	BitString() : Array(){
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
	BitString(const char* str):Array(str){
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

		for (int j = 0; j < 8; j++)
		{
			this->str[j] = (j >= strlen(str)) ? '0' : str[j] == '0' ? '0' : '1';
		}

		this->str[n] = '\0';

		for (int i = 0, j = n - 1; i < j; i++, j--)
		{
			swap(this->str[i], this->str[j]);
		}
	}
	void addElement(const char* a);
};

