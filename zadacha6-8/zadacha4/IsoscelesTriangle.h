#pragma once
#include "Triangle.h"
#include <cmath>
#include <iostream>

using namespace std;

class IsoscelesTriangle:public Triangle
{
public:
	IsoscelesTriangle(double a, double b) :Triangle(a, b, b){}
    IsoscelesTriangle() :Triangle() {}

    double square() {
        double h = sqrt((b * b) - (a / 2.) * (a / 2.));
        return 0.5 * (a/2.) * h;
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

        c = b;
    }
};

