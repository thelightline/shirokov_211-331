#include "Position.h"
#include <iostream>

Position::Position()
{
	this->x = 0;
	this->y = 0;
}

Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}

Position::~Position()
{
}

void Position::set_position(int a, int b)
{
	this->x = a;
	this->y = b;

	std::cout << this->x << " " << this->y << "\n";
}

void Position::move(int a, int b)
{
	this->x += a;
	this->y += b;

	std::cout << this->x << " " << this->y << "\n";
}