#include "stdafx.h"
#include "Func2.h"

// ML = SORT(TRANS(MF)*MK)
void StartFunc2()
{
	Data data;
	int** mf, **mk;

	#pragma omp critical
	{
		printf("Func 2 started\n");
	}

	mf = data.GetRandomMatrix();
	mk = data.GetRandomMatrix();

	mf = data.transMatrix(mf);
	mf = data.multMatrix(mf, mk);
	mf = data.sortMatrix(mf);

	#pragma omp critical
	{
		printf("Func 2 ended\nML = SORT(TRANS(MF)*MK) result:\n");
		data.printMatrix(mf);
		printf("\n");
	}
}
