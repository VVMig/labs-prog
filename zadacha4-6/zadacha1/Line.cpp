#include "Line.h"

Line::Line()
{
	x1 = x2 = y1 = y2 = 0;
}

Line::Line(double x1, double y1, double x2, double y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

double Line::getX1()
{
	return x1;
}

double Line::getY1()
{
	return y1;
}

double Line::getX2()
{
	return x2;
}

double Line::getY2()
{
	return y2;
}

void Line::setX1(double x)
{
	x1 = x;
}

void Line::setY1(double y)
{
	y1 = y;
}

void Line::setX2(double x)
{
	x2 = x;
}

void Line::setY2(double y)
{
	y2 = y;
}
