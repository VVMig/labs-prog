#include <iostream>
#include "Array.h"
#include "BitString.h"
#include "Fraction.h"

using namespace std;

int main() {
	string aTest, bTest;

	cout << "Array" << endl;
	cin >> aTest;
	cin >> bTest;

	Array a(aTest.c_str()), s(bTest.c_str());
	cout << a << endl;
	cout << s << endl;
	a.addElement(s.c_str());
	cout << a << endl;
	cout << "-------------" << endl;

	cout << "BitString" << endl;
	cin >> aTest;
	cin >> bTest;

	BitString c(aTest.c_str()), b(bTest.c_str());
	cout << c << endl;
	cout << b << endl;
	c.addElement(b.c_str());
	cout << c << endl;
	cout << "-------------" << endl;

	cout << "Fraction" << endl;
	cin >> aTest;
	cin >> bTest;

	Fraction f(aTest.c_str()), d(bTest.c_str());

	f.addElement(d.c_str());
	cout << f << endl;
	cout << "-------------" << endl;

	return 0;
}