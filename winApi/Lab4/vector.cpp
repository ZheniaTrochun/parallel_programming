#include "vector.h"
#include <iostream>

using namespace std;

vector::vector() {
	this->arr = new double[0];
	this->length = 0;
}
vector::vector(int length, bool set_zeros) {
	this->length = length;
	this->arr = new double[length];

	if (set_zeros) {
		for (int i = 0; i < length; i++) {
			arr[i] = 0;
		}
	}
	else {
		for (int i = 0; i < length; i++) {
			arr[i] = rand() % 10 + 1;
			if (rand() % 2 == 1) {
				arr[i] *= -1;
			}
		}
	}
}
vector::vector(double* arr, int length) {
	this->length = length;
	this->arr = new double[length];

	for (int i = 0; i < length; i++) {
		this->arr[i] = arr[i];
	}
}

vector* vector::sort() {
	vector* res = new vector(arr, length);
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			if (res->arr[i] < res->arr[j]) {
				double temp = res->arr[i];
				res->arr[i] = res->arr[j];
				res->arr[j] = temp;
			}
		}
	}
	return res;
}
double vector::min_val() {
	double min = arr[0];

	for (int i = 1; i < length; i++) {
		if (arr[i] < min)
			min = arr[i];
	}

	return min;
}

void vector::print() {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

double* vector::get_array() {
	return arr;
}
int vector::get_array_length() {
	return length;
}

vector::~vector() {
	if (arr != NULL) {
		delete[] arr;
	}
	length = 0;
}