#pragma once
#include <iostream>
class BitString
{
	private:
		int n = 0;
		char* str;

	public:
		BitString();
		BitString(const char* a);
		BitString(const BitString& oth);
		char* c_str();
		BitString& operator =(const BitString&);
		BitString& operator =(const char*);
		BitString operator +(BitString&);
		BitString operator +(const char*);
		BitString operator &(BitString&);
		BitString operator |(BitString&);
		BitString operator ^(BitString&);
		BitString operator !();
		BitString operator << (int a);
		BitString operator >> (int a);
		char operator[](int i);
		friend std::ostream& operator<< (std::ostream& out, BitString& oth);
		friend std::istream& operator>> (std::istream& in, BitString& oth);
		~BitString();
};



