
#include "stdafx.h"
#include "mpi.h"
#include <iostream>
#include <ctime>

#include "Func1.h"
#include "Func2.h"
#include "Func3.h"


int main(int argc, char* argv[])
{
	int rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		StartFunc1();
	}

	else if (rank == 1) {
		StartFunc2();
	}

	else if (rank == 2) {
		StartFunc3();
	}

	MPI_Finalize();

	return 0;
}
