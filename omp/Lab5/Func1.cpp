#include "stdafx.h"
#include "Func1.h"


//  d = ((A + B)* (C *(MA*ME)))
void Func1() {

	int d;
	int *a, *b, *c;
	int** ma, ** me;

	Data data;

	#pragma omp critical
	{
		printf("Func 1 started\n");
	}

	b = data.GetRandomVector();
	c = data.GetRandomVector();
	a = data.GetRandomVector();
	ma = data.GetRandomMatrix();
	me = data.GetRandomMatrix();


	a = data.sumOfVectors(a, b);
	ma = data.multMatrix(ma, me);
	c = data.matrixToVector(data.multMatrix(data.vectorToMatrix(c), ma));
	d = data.dotProduct(a, c);


	#pragma omp critical
	{
		printf("\nFunc 1 ended\nd = ((A + B)* (C *(MA*ME))) result:\n%d\n", d);
	}
}
