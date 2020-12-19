#pragma once
#include "Array.h"
class Fraction:public Array
{
public:
	Fraction():Array(){}
	Fraction(const char* a) :Array(a){}
	void addElement(const char* a);
};

