#include "matrix.h"
#include <iostream>

using namespace std;

matrix::matrix(){
	this->values = new double*[0];
	this->rows = 0;
	this->cols = 0;
}
matrix::matrix(int length, bool set_zeros):matrix(length, length, set_zeros) {
	
}
matrix::matrix(int rows, int cols, bool set_zeros){
	this->values = new double*[rows];
	this->rows = rows;
	this->cols = cols;

	for (int i = 0; i < rows; i++) {
		this->values[i] = new double[cols];

		if (set_zeros) {
			for (int j = 0; j < cols; j++) {
				this->values[i][j] = 0;
			}
		}
		else {
			for (int j = 0; j < cols; j++) {
				this->values[i][j] = rand() % 10 + 1;
				if (rand() % 2 == 1) {
					this->values[i][j] *= -1;
				}
			}
		}
	}
}
matrix::matrix(double** matrix, int rows, int cols){
	this->values = new double*[rows];
	this->rows = rows;
	this->cols = cols;

	for (int i = 0; i < rows; i++) {
		this->values[i] = new double[cols];
		for (int j = 0; j < cols; j++) {
			this->values[i][j] = matrix[i][j];
		}
	}
}

matrix* matrix::multiply(double number) {
	matrix* result = new matrix(values, rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result->values[i][j] *= number;
		}
	}
	return result;
}
vector* matrix::multiply(vector* vec){
	vector* result = new vector(vec->get_array_length());
	for (int i = 0; i < cols; i++) {
		for (int r = 0; r < rows; r++) {
			result->get_array()[i] += vec->get_array()[r] * values[r][i];
		}
	}
	return result;
}
matrix* matrix::multiply(matrix* mat){
	matrix* result = new matrix(rows, mat->cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < mat->cols; j++)
		{
			for (int r = 0; r < cols; r++)
			{
				result->values[i][j] += values[i][r] * mat->values[r][j];
			}
		}
	}

	return result;
}

matrix* matrix::add(matrix* mat){
	matrix* result = new matrix(mat->values, mat->rows, mat->cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result->values[i][j] += values[i][j];
		}
	}

	return result;
}
matrix* matrix::trans(){
	matrix* result = new matrix(cols, rows);
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			result->values[i][j] = values[j][i];
		}
	}
	return result;
}

double** matrix::get_values(){
	return values;
}
int matrix::get_rows(){
	return rows;
}
int matrix::get_cols(){
	return cols;
}

void matrix::print(){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << values[i][j] << " ";
		}
		cout << endl;
	}
}

matrix::~matrix(){
	if (values != NULL) {
		for (int i = 0; i < rows; i++) {
			delete[] values[i];
		}
		delete[] values;
	}

	rows = 0;
	cols = 0;
}

