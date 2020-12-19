#include "Manager.h"
#include <iostream>
#include <string>

using namespace std;

void Manager::show()
{
	cout << "---------------------------------------" << endl;
	cout << "Name: " << this->getName() << endl
		<< "Salary: " << this->getSalary() << "$" << endl
		<< "Job: Manager" << endl;
	cout << "---------------------------------------" << endl;
}
