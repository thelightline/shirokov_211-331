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
		cout << "\n";
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
			matr2.input();
			matr1.mult(&matr2);
			break;
		}
		case 3:
		{
			cout << "След матрицы: " << matr1.trace() << "\n";
			break;
		}
		case 4:
		{
			cout <<"Определитель раверн: "<< matr1.det() << "\n";
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
			cout <<"Столбцов в матрице: "<< matr1.get_columns() << "\n";
			break;
		}
		case 9:
		{
			cout <<"Строк в матриец: "<< matr1.get_rows() << "\n";
			break;
		}
		case 10:
		{
			int i, j, a;
			cout << "Введите i: ";
			cin >> i;
			cout << "Введите j: ";
			cin >> j;
			double* arr = new double[i * j];;
			cout << "Введите массив: ";
			for (int k = 0; k < i * j; k++) {
				cin >> a;
				arr[k] = a;
			}
			matr1.mult(arr);
			
			break;
		}
		default:
			return 0;
		}
	}
}