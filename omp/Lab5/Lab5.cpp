
#include "stdafx.h"
#include <omp.h>
#include <iostream>
#include <ctime>

#include "Func1.h"
#include "Func2.h"
#include "Func3.h"


int main()
{

	#pragma omp parallel sections num_threads(4)
    {

		#pragma omp section

			Func1();


		#pragma omp section

			Func2();


		#pragma omp section

			Func3();

	}

	return 0;
}
