#include "Employee.h"
#include <string>
#pragma once
class Programmer : public Employee
{

public:
	Programmer(float salary = 0, string name = "unknown") :Employee(salary, name) {}

	void show();
};

