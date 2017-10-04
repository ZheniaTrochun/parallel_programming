#include "stdafx.h"
#include "Func3.h"


// t = MAX((MO*MP)*R + MS*S)
void StartFunc3() {

	int t;
	int* s, *r;
	int** ms, **mo, **mp;
	Data data;

	#pragma omp critical
	{
		printf("Func 3 started\n");
	}

	s = data.GetRandomVector();
	r = data.GetRandomVector();

	mo = data.GetRandomMatrix();
	mp = data.GetRandomMatrix();
	ms = data.GetRandomMatrix();

	mo = data.multMatrix(mo, mp);
	mo = data.multMatrix(mo, data.vectorToMatrix(r));
	ms = data.multMatrix(ms, data.vectorToMatrix(s));
	mo = data.sumOfMatrix(ms, mo);
	t = data.maxOfMatrix(mo);

	#pragma omp critical
	{
		printf("Func 3 ended\nt = MAX((MO*MP)*R + MS*S) result:\n%d\n\n", t);
	}
}
