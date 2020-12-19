#include <iostream>
#include "RightTriangle.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "Triangle.h"

using namespace std;

void show(Triangle& a);

int main() {
	Triangle *a = new IsoscelesTriangle;

	cout << "Isosceles triangle" << endl;
	a->input();
	cout << "Show by method" << endl;
	a->show();
	cout << "Show by function" << endl;
	show(*a);
	cout << "Square: " << a->square() << endl;
	cout << "Perimetr: " << a->perimetr() << endl;

	cout << "------------------" << endl;

	cout << "Right triangle" << endl;
	a = new RightTriangle;
	a->input();
	cout << "Show by method" << endl;
	a->show();
	cout << "Show by function" << endl;
	show(*a);
	cout << "Square: " << a->square() << endl;
	cout << "Perimetr: " << a->perimetr() << endl;

	cout << "------------------" << endl;

	cout << "Equilateral triangle" << endl;
	a = new EquilateralTriangle;
	a->input();
	cout << "Show by method" << endl;
	a->show();
	cout << "Show by function" << endl;
	show(*a);
	cout << "Square: " << a->square() << endl;
	cout << "Perimetr: " << a->perimetr() << endl;
	
	return 0;
}

void show(Triangle& a)
{
	a.show();
}
