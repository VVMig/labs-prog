#include <iostream>
#include "Decimal.h"

using namespace std;

int main() {
	Decimal a(13), b(26), tmp;
	
	for (int i = 0; a[i]; i++)
	{
		cout <<i + 1<<": "<< a[i] << endl;
	}
	
	cout << a << ' ' << b << endl;
	cout << "------------------" << endl;
	cout << "a < b" << endl;
	if (a < b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << a << ' ' << b << endl;
	cout << "------------------" << endl;
	cout << "a > b" << endl;
	if (a > b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << a << ' ' << b << endl;
	cout << "------------------" << endl;
	cout << "a == b" << endl;
	if (a == b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << a << ' ' << b << endl;
	cout << "------------------" << endl;
	cout << "a != b" << endl;
	if (a != b) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	cout << "------------------" << endl;
	cout << "a * b" << endl;
	tmp = a * b;
	cout << a << " * " << b << " = " << tmp << endl;

	cout << "------------------" << endl;
	cout << "a + b" << endl;
	tmp = a + b;
	cout << a << " + " << b << " = " << tmp << endl;

	cout << "------------------" << endl;
	cout << "a - b" << endl;
	tmp = a - b;
	cout << a << " - " << b << " = " << tmp << endl;

	cout << "------------------" << endl;
	cout << "a / b" << endl;
	tmp = a / b;
	cout << a << " / " << b << " = " << tmp << endl;

	return 0;
}