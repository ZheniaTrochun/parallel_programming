#pragma once
#include "stdafx.h"
#include "mpi.h"
#include <iostream>
#include <stdlib.h>

class Data
{
public:
	Data();

	~Data();

	int* GetRandomVector();
	int** GetRandomMatrix();
	void printMatrix(int** matrix);
	int* sumOfVectors(int* vector1, int* vector2);
	int** sumOfMatrix(int** matrix1, int** matrix2);
	int** vectorToMatrix(int* vector);
	int* matrixToVector(int** matrix);
	int** multMatrix(int** matrix1, int** matrix2);
	int** transMatrix(int** matrix);
	int dotProduct(int* vector1, int* vector2);
	int** sortMatrix(int** matrix);
	int maxOfMatrix(int** matrix);

private:
	int sizeOfArrays;
};
