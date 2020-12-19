#include <iostream>
#include "Employee.h"
#include <string>
#include "Administrator.h"
#include "Manager.h"
#include "Programmer.h"

using namespace std;

int selectClass();
void showClassMenu();
void showActions();
int selectAction();
int selectNum(int length);

int main() {
	int length;
	bool end = true;

	cout << "Enter length: ";
	cin >> length;

	while (cin.fail() || length < 1) {
		cout << "Enter length: ";
		cin >> length;
	}

	Employee **b = new Employee *[3];

	b[0] = new Administrator[length];
	b[1] = new Programmer[length];
	b[2] = new Manager[length];
	
	while (end) {
		switch (selectClass())
		{
		case 1:
			switch (selectAction())
			{
			case 1:
					float salary;

					cout << "Salary: ";
					cin >> salary;

					while (cin.fail() || salary < 0) {
						cout << "Enter correct data" << endl;
						cout << "Salary: ";
						cin >> salary;
					}

					b[0][selectNum(length)].setSalary(salary);
				break;
			case 2:
				if (true) {
					string name;

					cout << "Name: ";
					cin >> name;

					while (cin.fail() || name == "") {
						cout << "Enter correct data" << endl;
						cout << "Salary: ";
						cin >> name;
					}

					b[0][selectNum(length)].setName(name);
				}
				break;
			case 3:
					cout <<  b[0][selectNum(length)].getSalary() << "$" << endl;
				break;
			case 4:
	
					cout << b[0][selectNum(length)].getName() << endl;
				break;
			case 5:
				b[0][selectNum(length)].show();
				break;
			default:
				break;
			}
			break;
		case 2:
				switch (selectAction())
				{
				case 1:
					float salary;

					cout << "Salary: ";
					cin >> salary;

					while (cin.fail() || salary < 0) {
						cout << "Enter correct data" << endl;
						cout << "Salary: ";
						cin >> salary;
					}

					b[0][selectNum(length)].setSalary(salary);
					break;
				case 2:
					if (true) {
						string name;

						cout << "Name: ";
						cin >> name;

						while (cin.fail() || name == "") {
							cout << "Enter correct data" << endl;
							cout << "Salary: ";
							cin >> name;
						}

						b[0][selectNum(length)].setName(name);
					}
					break;
				case 3:
					cout << b[0][selectNum(length)].getSalary() << "$" << endl;
					break;
				case 4:

					cout << b[0][selectNum(length)].getName() << endl;
					break;
				case 5:
	
						b[0][selectNum(length)].show();
					break;
				default:
					break;
				}
			break;
		case 3:
				switch (selectAction())
				{
				case 1:
					if (true) {
						float salary;

						cout << "Salary: ";
						cin >> salary;

						while (cin.fail() || salary < 0) {
							cout << "Enter correct data" << endl;
							cout << "Salary: ";
							cin >> salary;
						}

						b[0][selectNum(length)].setSalary(salary);
					}
					break;
				case 2:
					if (true) {
						string name;

						cout << "Name: ";
						cin >> name;

						while (cin.fail() || name == "") {
							cout << "Enter correct data" << endl;
							cout << "Salary: ";
							cin >> name;
						}

						b[0][selectNum(length)].setName(name);
					}
					break;
				case 3:
					cout << b[0][selectNum(length)].getSalary() << "$" << endl;
					break;
				case 4:

					cout << b[0][selectNum(length)].getName() << endl;
					break;
				case 5:
					b[0][selectNum(length)].show();
					break;
				default:
					break;
				}
			break;
		case 4:
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < length; j++) {
					b[i][j].show();
				}
			}
			break;
		default:
			end = false;
			break;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		delete[] b[i];
	}

	delete[] b;

	return 0;
}

int selectNum(int length) {
	if (length == 1) {
		return 1;
	}

	int num;

	cout << "Enter number of Employee to change: ";
	cin >> num;

	while (cin.fail() || num < 1 || num > length) {
		cout << "Enter number of Employee to change: ";
		cin >> num;
	}

	return num - 1;
}

int selectAction() {
	cout << "---------------------------------------" << endl;

	int n;

	showActions();

	cout << "Select action: ";
	cin >> n;

	while (cin.fail() || n > 5 || n < 0) {
		cout << "Enter correct number" << endl;

		showActions();

		cout << "Select action: ";
		cin >> n;
	}

	return n;
}

void showActions() {
	cout << "1. Set salary" << endl
		<< "2. Set name" << endl
		<< "3.Get salary" << endl
		<< "4. Get name" << endl
		<< "5. Get fullInfo" << endl
		<< "0. End" << endl;
}

int selectClass() {
	cout << "---------------------------------------" << endl;
	int n;

	showClassMenu();

	cout << "Select class: ";
	cin >> n;

	while (cin.fail() || n > 4 || n < 0) {
		cout << "Enter correct number" << endl;

		showClassMenu();

		cout << "Select class: ";
		cin >> n;
	}

	return n;
}

void showClassMenu() {
	cout << "1. Administrator" << endl
		<< "2. Programmer" << endl
		<< "3. Manager" << endl
		<< "4. Get all info" << endl
		<< "0. End" << endl;
}
