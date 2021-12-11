#include "Square.h"

Square::Square()
{
	Position::x = 0;
	Position::y = 0;
	this->length = 0;
}

Square::Square(double l)
{
	Position::x = 0;
	Position::y = 0;
	this->length = l;
}

Square::Square(int a, int b, double l)
{
	Position::x = a;
	Position::y = b;
	this->length = l;
}

double Square::perimetr()
{
	return 4 * this->length;
}

double Square::area()
{
	return this->length * this->length;
}

double Square::lan()
{
	return this->length;
}