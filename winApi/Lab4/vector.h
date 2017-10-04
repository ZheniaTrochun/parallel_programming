#pragma once

class vector {
private:
	double* arr;
	int length;
public:
	vector();
	vector(int length, bool set_zeros = true);
	vector(double* arr, int length);
	double min_val();
	vector* sort();
	void print();
	double* get_array();
	int get_array_length();
	~vector();
};