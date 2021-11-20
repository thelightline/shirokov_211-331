#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
	size_col = size_row = 0;
	elem = nullptr;
}

Matrix::Matrix(int col, int row) {
	size_col = col;
	size_row = row;
	elem = new double[col * row];
	for (int i = 0; i < col * row; i++)
		elem[i] = 0;
}

Matrix::Matrix(int col, int row, double* arr){
	size_col = col;
	size_row = row;
	elem = new double[col * row];
	for (int i = 0; i < col * row; i++)
		elem[i] = arr[i];
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

void Matrix::sum(Matrix* matr2) { 
	if (size_col == matr2->size_col && size_row == matr2->size_row) {
		for (int i = 0; i < size_col * size_row; i++)
			this->elem[i] += matr2->elem[i];
	}
}

double Matrix::trace() // сумма чисел матрицы по диагонаи
{
	double s = 0.0;
	if (size_col == size_row)
	{
		for (int i = 0; i < size_row; i++)
		{
			s += this->elem[i * size_row + 1];
		}
		return s;
	}
	else
	{
		cout << "Матрица не является квадратной\n";
	}
	cout << "\n";
}

Matrix Matrix::mult(Matrix* matr2) { // умножение матриц
	if (this->size_col != matr2->size_row) cout << "Ложная записьx";
	else {
		int res_col = matr2->size_col;
		int k = 0;
		int res_row = size_row;
		double* res = new double[res_row * res_col];
		for (int i = 0; i < res_row; i++)
			for (int j = 0; j < res_col; j++)
			{
				res[i * res_col + j] = 0;
				for (int k = 0; k < this->size_col; k++)
					res[i * res_col + j] += this->get_elem(i, k) * matr2->get_elem(k, j);
			}
		for (int i = 0; i < res_row; i++) {
			for (int j = 0; j < res_col; j++)
				cout << res[i * res_col + j] << " ";
			cout << "\n";
		}
		cout << "\n";
		return Matrix(res_col, res_row, res);
	}
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
	cout << "Введите количество столбцов матрицы: ";
	cin >> size_col;
	cout << "Введите количество строк матрицы: ";
	cin >> size_row;
	if (elem != nullptr) delete[] elem;
	elem = new double[size_col * size_row];
	for (int i = 0; i < size_col * size_row; i++)
		cin >> elem[i];
	cout << "\n";
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
	return this->elem[i * size_col + j];
}

void Matrix::input(int col, int row)
{
	int a;
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) {
			cin >> a;
			elem[i * col + j] = a;
		}
}

void Matrix::input(int col, int row, double* arr) {
	int k = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			elem[i * col + j] = arr[k];
			k++;
		}
}

Matrix Matrix::mult(const double* arr)
{
	int arr_size = sizeof(arr);
	int res_col = arr_size/this->size_col;
	int res_row = this->size_row;
	if (!(arr_size % this->size_col)) return *this;
	double* res = new double[res_row * res_col];
		for (int i = 0; i < res_row; i++)
			for (int j = 0; j < res_col; j++)
			{
				res[i * res_col + j] = 0;
				for (int k = 0; k < this->size_col; k++)
					res[i * res_col + j] += this->get_elem(i, k) * arr[k * res_col + j];
			}
		return Matrix(res_col, res_row, res);;
}

Matrix Matrix::sum(const double* arr) {
	if (size_col * size_row == sizeof(arr)){
		for (int i = 0; i < size_col * size_row; i++)
			this->elem[i] += arr[i];
		return *this;
	}
	else
		return *this;
}
