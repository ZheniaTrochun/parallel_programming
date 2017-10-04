#include "stdafx.h"
#include "Func2.h"


void Func2()
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
		printf("\nFunc 2 ended\n ML = SORT(TRANS(MF)*MK) result:\n");
		data.printMatrix(mf);
	}
}
