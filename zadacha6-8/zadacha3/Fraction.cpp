#include "Fraction.h"
#include <string>
#include <cmath>

using namespace std;

double toDouble(const char* a) {
	string cc = "", dd = "";
	double c = 0.0, d = 0.0;
	bool cel = true;

	for (int i = 0;a[i]; i++)
	{
		if (a[i] == '.') cel = false;
			if (a[i] >= '0' && a[i] <= '9') {
				if (cel)
					cc += a[i];
				else dd += a[i];
			}
	}

	c = atoi(cc.c_str());
	d = atoi(dd.c_str());

	d=  d/pow(10, dd.size());

	c += d;

	return c;
}

void Fraction::addElement(const char* a)
{
	double res = toDouble(a) + toDouble(this->c_str());
	string b = to_string(res);
	int i = b.size() - 1;
	
	for (i; b[i] == '0'; i--);

	b = b.substr(0, i + 1);

	str = new char[b.size() + 1];
	n = b.size();
	strcpy_s(str, n + 1, b.c_str());
}
