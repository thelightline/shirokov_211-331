#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int choice = 0;
	Matrix matr1, matr2;
	while (true) {
		cout <<"1) Сложение\n" <<
			"2) Умножение\n" <<
			"3) След матрицы\n" <<
			"4) Определитель матрицы\n" <<
			"5) Умножение матрицы на число\n" <<
			"6) Ввод матрицы с клавиатуры\n" <<
			"7) Вывод матрицы в консоль\n" <<
			"8) Количество столбцов\n" << 
			"9) Количество строк\n" <<
			"10) Вернуть (i, j) элемент" << "\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			matr2.input();
			matr1.sum(&matr2);
			break;
		}
		case 2:
		{
			cout << "Переделать";
			break;
		}
		case 3:
		{
			matr1.trace();
			break;
		}
		case 4:
		{
			cout << matr1.det();
			break;
		}
		case 5:
		{
			double num;
			cout << "Введите член множества: ";
			cin >> num;
			matr1.mult_by_num(num);
			break;
		}
		case 6:
		{
			matr1.input();
			break;
		}
		case 7:
		{
			matr1.print();
			break;
		}
		case 8:
		{
			cout << matr1.get_columns();
			break;
		}
		case 9:
		{
			cout << matr1.get_rows();
			break;
		}
		case 10:
		{
			int i, j;
			cout << "Введите i и j: ";
			cin >> i;
			cin >> j;
			cout << matr1.get_elem(i, j);
			break;
		}
		default:
			return 0;
		}
	}
}