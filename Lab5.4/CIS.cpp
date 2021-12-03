#include "CIS.h"

CIS::CIS()
{
	Position::x = 0;
	Position::y = 0;
	Square::length = 0;
	Circle::radius = 0;
}

CIS::CIS(double size)
{
	Position::x = 0;
	Position::y = 0;
	Square::length = size;
	Circle::radius = size / 2;
}

CIS::CIS(int a, int b, double size)
{
	Position::x = a;
	Position::y = b;
	Square::length = size;
	Circle::radius = size / 2;
}

void CIS::set_size(double size)
{
	Square::length = size;
	Circle::radius = size / 2;
}