#include "Administrator.h"
#include <iostream>
#include <string>

using namespace std;


void Administrator::show()
{
	cout << "---------------------------------------" << endl;
	cout << "Name: " << this->getName() << endl
		<< "Salary: " << this->getSalary() << "$" << endl
		<< "Job: Administrator" << endl;
	cout << "---------------------------------------" << endl;

}
