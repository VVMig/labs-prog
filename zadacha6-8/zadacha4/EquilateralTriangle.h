#pragma once
#include "Triangle.h"
#include <cmath>
#include <iostream>

using namespace std;

class EquilateralTriangle:public Triangle
{
public:
	EquilateralTriangle(double a) :Triangle(a, a, a){}
    EquilateralTriangle() :Triangle() {}

    double square() {
        return (a*a*sqrt(3))/4.;
    }
    double perimetr() {
        return a + b + c;
    }
    void show() {
        cout << "a: " << a << endl
            << "b: " << b << endl
            << "c: " << c << endl;
    }
    void input() {
        cout << "Enter side: ";
        cin >> a;

        while (cin.fail() || a < 1) {
            cout << "Enter side: ";
            cin >> a;
        }

        b = c = a;
    }
};

