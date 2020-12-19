#pragma once
#include <cmath>
#include <iostream>

class Triangle
{
protected:
    double a;
    double b;
    double c;
public:
    Triangle():a(0),b(0),c(0){}
    Triangle(double a, double b, double c) :a(a), b(b), c(c){
        try
        {
            if ((a + b <= c || a + c <= b || c + b <= a)) 
                throw "Triangle doesn't exist";
        }
        catch (const char* a)
        {
            std::cout << a << std::endl;
            exit(-1);
        }
    }
    virtual double square() = 0;
    virtual double perimetr() = 0;
    virtual void input() = 0;
    virtual void show() = 0;
};

