#include "Employee.h"
#include <string>
#pragma once
class Administrator: public Employee
{

public:
	Administrator(float salary = 0, string name = "unknown") :Employee(salary, name) {}

	void show();
};

