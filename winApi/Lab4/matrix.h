#pragma once

#include "vector.h"

class matrix {
private:
	double** values;
	int rows;
	int cols;
public:
	matrix();
	matrix(int length, bool set_zeros = true);
	matrix(int rows, int cols, bool set_zeros = true);
	matrix(double** matrix, int rows, int cols);

	matrix* multiply(double number);
	vector* multiply(vector* vec);
	matrix* multiply(matrix* matrix);

	matrix* add(matrix* mat);
	matrix* trans();

	double** get_values();
	int get_rows();
	int get_cols();

	void print();

	~matrix();
};