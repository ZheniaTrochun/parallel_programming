#include "funcs.h"

matrix* func1(vector* a, matrix* ma, matrix* md) {
	return ma->multiply(md)->multiply(a->min_val());
}
matrix* func2(matrix* ma, matrix* mb, matrix* mm, matrix* mx) {
	return (ma->trans()->multiply(mb->multiply(mm)->trans()))->add(mx);
}
vector* func3(vector* p, matrix* mr, matrix* ms) {
	return mr->multiply(ms)->multiply(p->sort());
}