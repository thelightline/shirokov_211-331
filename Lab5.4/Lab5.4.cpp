#include <iostream>
#include "Position.h"
#include "Circle.h"
#include "Square.h"
#include "CIS.h"

int main()
{
	CIS CISA(2, 3, 4);
	std::cout << CISA.lan() << "\n";
	std::cout << CISA.rad() << "\n";
	Position PosA(5, 3);
	PosA.move(1, 1);
}