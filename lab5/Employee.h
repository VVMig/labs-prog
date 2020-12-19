#pragma once
#include <string>

using namespace std;

class Employee
{
protected:
	float salary;
	string name;
public:
	Employee() :salary(0), name(""){}
	Employee(float salary, string name) :salary(salary), name(name){}
	virtual void show() = 0;
	float getSalary() {
		return salary;
	}
	void setSalary(float salary) {
		if (salary >= 0) {
			this->salary = salary;
		}
	};
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};

