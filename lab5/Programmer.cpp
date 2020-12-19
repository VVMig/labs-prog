#include "Programmer.h"
#include <iostream>
#include <string>

using namespace std;


void Programmer::show()
{
	cout << "---------------------------------------" << endl;
	cout << "Name: " << this->getName() << endl
		<< "Salary: " << this->getSalary() << "$" << endl
		<< "Job: Programmer" << endl;
	cout << "---------------------------------------" << endl;
}
