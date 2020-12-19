#pragma once
#include "Triangle.h"
#include <cmath>
#include <iostream>

using namespace std;

class RightTriangle:public Triangle
{
public:
	RightTriangle(double a, double b) :Triangle(a, b, sqrt(a* a + b * b)) {}
    RightTriangle() :Triangle(){}

    double square() {
        return 0.5*a*b;
    }
    double perimetr() {
        return a + b + c;
    }
    void input() {
        cout << "Enter first side: ";
        cin >> a;

        while (cin.fail() || a < 1) {
            cout << "Enter first side: ";
            cin >> a;
        }

        cout << "Enter second side: ";
        cin >> b;

        while (cin.fail() || b < 1) {
            cout << "Enter second side: ";
            cin >> b;
        }

        c = sqrt(b * b + a * a);
    }
    void show() {
        cout << "a: " << a << endl
            << "b: " << b << endl
            << "c: " << c << endl;
    }

};

