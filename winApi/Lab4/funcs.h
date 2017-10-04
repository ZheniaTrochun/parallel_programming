#pragma once
#include "matrix.h"

//MC = MIN(A) *(MA*MD)
matrix* func1(vector* a, matrix* ma, matrix* md);
//MK = TRANS(MA)*TRANS(MB*MM) + MÕ
matrix* func2(matrix* ma, matrix* mb, matrix* mm, matrix* mx);
//O = SORT(P)*(MR * MS)
vector* func3(vector* p, matrix* mr, matrix* ms);