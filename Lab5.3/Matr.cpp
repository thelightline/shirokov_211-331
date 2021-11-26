#include "Matr.h"
#include <iostream>

using namespace std;

Matr::Matr() {
	size = 0;
	elem = nullptr;
}

Matr::Matr(const Matr& old) {
	this->size = old.size;
	//	if (this->elem != nullptr)
	//		delete[]this->elem;
	this->elem = new double[this->size * 3];
	for (int i = 0; i < 3 * this->size; i++) {
		this->elem[i] = old.elem[i];
	}
}

Matr::Matr(int size) {
	this->size = size;
	if (elem != nullptr)
		delete[]elem;
	this->elem = new double[this->size * 3];
}

Matr::~Matr() {
	if (this->elem != nullptr)
		delete[] this->elem;
}

void Matr::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++) {
			cout << this->get_elem(i, j) << " ";
		}
		cout << "\n";
	}
}

double Matr::get_elem(int i, int j) const
{
	if (i == j) return this->elem[this->size + i];
	else if (i == j - 1) return this->elem[i];
	else if (i == j + 1) return this->elem[2 * this->size + i];
	else return 0.0;
}

void Matr::input(int size)
{
	this->size = size;
	if (this->elem != nullptr)
		delete[]this->elem;
	this->elem = new double[this->size * 3];
	cout << "Введите " << 3 * this->size << " элементов:" << "\n";
	for (int i = 0; i < 3 * this->size; i++) {
		cin >> this->elem[i];
	}

	// size+1 и (size*2)+1 не входят на матрицу
	return;
}

double Matr::tr() const
{
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + this->get_elem(i, i);
	}
	return sum;
}

double Matr::det() const {
	if (this->size == 2) {
		double s = get_elem(1, 1) * get_elem(2, 2) - get_elem(1, 2) * get_elem(2, 1);
		return s;
	}
	if (this->size == 3) {
		double s = get_elem(1, 1) * get_elem(2, 2) * get_elem(3, 3) + get_elem(1, 2) * get_elem(2, 3) * get_elem(3, 1) + get_elem(1, 3) * get_elem(2, 1) * get_elem(3, 2) -
			get_elem(1, 3) * get_elem(2, 2) * get_elem(3, 1) - get_elem(1, 2) * get_elem(2, 1) * get_elem(3, 3) - get_elem(1, 1) * get_elem(2, 3) * get_elem(3, 2);
		return s;
	}

	cout << "Матрица должна быть 2x2 или 3x3" << "\n";
	return 0;
}

int Matr::columns() const {
	return this->size;
}

void Matr::operator+= (const Matr& temp)
{
	if (this->size == temp.size) {
		for (int i = 0; i < 3 * this->size; i++) {
			this->elem[i] += temp.elem[i];
		}
	}
}

void Matr::operator-=(const Matr& temp)
{
	if (this->size == temp.size) {
		for (int i = 0; i < 3 * this->size; i++) {
			this->elem[i] -= temp.elem[i];
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Matr& temp)
{
	for (int i = 0; i < temp.size; i++) {
		for (int j = 0; j < temp.size; j++) {
			out << temp.get_elem(i, j) << "  ";
		}
		out << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Matr& temp)
{
	in >> temp.size;
	if (temp.elem != nullptr)
		delete[] temp.elem;
	temp.elem = new double[3 * temp.size];
	for (int i = 0; i < 3 * temp.size; i++)
		in >> temp.elem[i];
	return in;
}

Matr operator-(const Matr& m)
{
	Matr res(m);
	for (int i = 0; i < 3 * m.size; i++) {
		res.elem[i] = -m.elem[i];
	}
	return res;
}

Matr operator-(const Matr& m, const Matr& n)
{
	Matr res(m);
	if (m.size != n.size) {
		return res;
	}
	else {
		res -= n;
		return res;
	}
}

Matr operator+(const Matr& m, double a)
{
	Matr res(m);
	for (int i = 0; i < m.size; i++) {
		res.elem[i] = m.elem[i] + a;
	}
	return res;
}

Matr operator+(const Matr& m, const Matr& n)
{
	Matr res(m);
	if (m.size != n.size) {
		return res;
	}
	else {
		res += n;
		return res;
	}
}

Matr operator*(const Matr& m, double a)
{
	Matr res(m);
	for (int i = 0; i < m.size; i++) {
		res.elem[i] = m.elem[i] * a;
	}
	return res;
}

Matr operator*(const Matr& m, const Matr& n) {
	double* Matrix;
	Matrix = new double[m.size * m.size];
	if (m.size != n.size) std::cout << "\n"<< "Ошибка. Матрицы не равны." << "\n";
	else {
		for (int i = 0; i < m.size; i++)
		{
			for (int j = 0; j < n.size; j++)
			{
				Matrix[i * n.size + j] = 0;
				for (int k = 0; k < m.size; k++) {
					Matrix[i * n.size + j] += m.get_elem(i, k) * n.get_elem(k, j);
				}
			}
		}
	}
	for (int i = 0; i < m.size; i++)
	{
		for (int j = 0; j < m.size; j++)
		{
			cout << Matrix[i * n.size + j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return m;
}