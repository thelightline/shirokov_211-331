#include "Circle.h"

Circle::Circle()
{
	Position::x = 0;
	Position::y = 0;
	this->radius = 0;
}

Circle::Circle(double r)
{
	Position::x = 0;
	Position::y = 0;
	this->radius = r;
}

Circle::Circle(int a, int b, double r)
{
	Position::x = a;
	Position::y = b;
	this->radius = r;
}

double Circle::perimetr()
{
	return 2 * 3.14 * this->radius;
}

double Circle::area()
{
	return 3.14 * this->radius * this->radius;
}

double Circle::rad()
{
	return this->radius;
}