#pragma once
class Line
{
	double x1;
	double y1;
	double x2;
	double y2;
public:
	Line();
	Line(double x1, double y1, double x2, double y2);
	double getX1();
	double getY1();
	double getX2();
	double getY2();
	void setX1(double x);
	void setY1(double y);
	void setX2(double x);
	void setY2(double y);
};

