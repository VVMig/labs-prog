#include "Employee.h"
#include <string>
#pragma once
class Manager : public Employee
{

public:
	Manager(float salary = 0, string name = "unknown"):Employee(salary, name){}

	void show();
};

