#include <iostream>
#include "BitString.h"
#include <string>

using namespace std;

int menu();

int main() {
	bool cont = true;
	int n = 0;
	string defVal;
	
	cout << "Enter def value: ";
	cin >> defVal;

	BitString a(defVal.c_str()), tmp; 

	while (cont) {
		switch (menu())
		{
		case 1:
			cout << "Enter string for operation: ";
			cin >> defVal;
			tmp = defVal.c_str();
			cout << tmp << endl << a << endl;
			tmp = tmp & a;
			cout << tmp << endl;
			break;
		case 2:
			cout << "Enter string for operation: ";
			cin >> defVal;
			tmp = defVal.c_str();
			cout << tmp << endl << a << endl;
			tmp = tmp | a;
			cout << tmp << endl;
			break;
		case 3:
			cout << "Enter string for operation: ";
			cin >> defVal;
			tmp = defVal.c_str();
			cout << tmp << endl << a << endl;
			tmp = tmp ^ a;
			cout << tmp << endl;
			break;
		case 4:
			cout << a << endl;
			tmp = !a;
			cout << tmp << endl;
			break;
		case 5:
			cout << "Enter n byte to move: ";
			cin >> n;
			while (cin.fail() || n < 0) {
				cout << "n must be greater then 0"<<endl;
				cout << "Enter n byte to move: ";
				cin >> n;
			}
			cout << a << endl;
			tmp = a << n;
			cout << tmp << endl;
			break;
		case 6:
			cout << "Enter n byte to move: ";
			cin >> n;
			while (cin.fail() || n < 0) {
				cout << "n must be greater then 0" << endl;
				cout << "Enter n byte to move: ";
				cin >> n;
			}
			cout << a << endl;
			tmp = a >> n;
			cout << tmp << endl;
			break;
		case 7:
			cout << a << endl;
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}

int menu() {
	cout << "1. And" << endl
		<< "2. Or" << endl
		<< "3.XOR" << endl
		<< "4.NOT" << endl
		<< "5. << n" << endl
		<< "6. >> n" << endl
		<< "7. show" << endl
		<< "0. end" << endl;

	int a;
	cout << "Select number: ";
	cin >> a;

	while (cin.fail() || a > 7 || a < 0) {
		cout << "Select number: ";
		cin >> a;
	}

	return a;
}