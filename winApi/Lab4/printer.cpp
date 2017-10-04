#include "printer.h"
#include <iostream>

using namespace std;

void printer::show(vector* v) {
	for (int i = 0; i < v->get_array_length(); i++) {
		cout << v->get_array()[i] << "\t";
	}
	cout << endl;
}

void printer::show(matrix* m) {
	for (int i = 0; i < m->get_rows(); i++) {
		for (int j = 0; j < m->get_cols(); j++) {
			cout << m->get_values()[i][j] << "\t";
		}
		cout << endl;
	}
}