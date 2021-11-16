#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
	size_col = size_row = 0;
	elem = nullptr;
}

Matrix::Matrix(int col, int row){
	size_col = col;
	size_row = row;
	elem = new double[col * row];
	for (int i = 0; i < col * row; i++)
		elem[i] = 0;
}

Matrix::Matrix(const Matrix& temp){
	size_col = temp.size_col;
	size_row = temp.size_row;
	elem = new double[(temp.size_col) * (temp.size_row)];
	for (int i = 0; i < temp.size_col * temp.size_row; i++)
		elem[i] = temp.elem[i];
}

Matrix::~Matrix(){
	if (elem != nullptr) delete[]elem;
}

void Matrix::sum(Matrix* matr2) {// сложение матриц
	if (size_col == matr2->size_col && size_row == matr2->size_row) {
		for (int i = 0; i < size_col * size_row; i++)
			this->elem[i] += matr2->elem[i];
	}
}

void Matrix::trace() // сумма чисел матрицы по диагонаи
{
	double s = 0.0;
	if (size_col == size_row)
	{
		for (int i = 0; i < size_row; i++)
		{
			s += this->elem[i * size_row + 1];
		}
		cout << "След матрицы равен: " << s;
	}
	else
	{
		cout << "Матрица не является квадратной\n";
	}
	cout << "\n";
}

double Matrix::det() // определитель 
{
	double s = 0.0;
	if (size_col == size_row && size_col == 2){
		s = elem[0] * elem[3] - elem[2] * elem[1];
	}
	else if (size_col == size_row && size_col == 3){
		s = (elem[0] * elem[4] * elem[8] + elem[1] * elem[5] * elem[6] + elem[2] * elem[3] * elem[7]) -
			(elem[2] * elem[4] * elem[6] + elem[1] * elem[3] * elem[8] + elem[0] * elem[5] * elem[7]);
	}
	else
		cout << "Матрица не равна квадрату из 3ёх или 2ух элементов"<<"\n";
	return s;
}

void Matrix::mult_by_num(double num){ // умножение матрицы на число
	for (int i = 0; i < size_col * size_row; i++)
		elem[i] *= num;
}

void Matrix::input(){ // ввод матрицы
	cout << "Введите количество столбцов матрицы: " << "\n";
	cin >> size_col;
	cout << "Введите количество строк матрицы: ";
	cin >> size_row;
	if (elem != nullptr) delete[] elem;
	elem = new double[size_col * size_row];
	for (int i = 0; i < size_col * size_row; i++)
		cin >> elem[i];
}

void Matrix::print(){ // вывод матрицы
	for (int i = 0; i < size_row; i++){
		for (int j = 0; j < size_col; j++)
			cout << elem[i * size_col + j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int Matrix::get_columns(){ // количество столбцов
	return size_col;
}

int Matrix::get_rows(){ // количество строк
	return size_row;
}

double Matrix::get_elem(int i, int j){ // вывод (i, j) элемента
	return elem[i, j];
}

