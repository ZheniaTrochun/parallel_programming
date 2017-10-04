#include "stdafx.h"
#include "Data.h"


Data::Data()
{
	this->sizeOfArrays = 10;
}


Data::~Data()
{
}

int* Data::GetRandomVector()
{
	int* vector = new int[sizeOfArrays];

	for (int i = 0; i < sizeOfArrays; i++)
	{
		vector[i] = rand() % 20 - 20;
	}

	return vector;
}

int** Data::GetRandomMatrix()
{
	int** matrix = new int*[sizeOfArrays];

	for (int i = 0; i < sizeOfArrays; i++)
	{
		matrix[i] = new int[sizeOfArrays];
	}

	for (int i = 0; i < sizeOfArrays; i++)
	{
		for (int j = 0; j < sizeOfArrays; j++)
		{
			matrix[i][j] = rand() % 100 - 100;
		}
	}

	return matrix;
}

void Data::printMatrix(int** matrix)
{
	for (int i = 0; i < sizeOfArrays; i++)
	{
		for (int j = 0; j < sizeOfArrays; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}
}

int* Data::sumOfVectors(int* vector1, int* vector2)
{
	int* resVector = new int[sizeOfArrays];

	for (int i = 0; i < sizeOfArrays; i++)
	{
		resVector[i] = vector1[i] + vector2[i];
	}

	return resVector;
}

int** Data::sumOfMatrix(int** matrix1, int** matrix2)
{
	int** resMatrix = new int*[sizeOfArrays];

	for (int i = 0; i < sizeOfArrays; i++)
	{
		resMatrix[i] = new int[sizeOfArrays];
	}

	for (int i = 0; i < sizeOfArrays; i++)
	{
		for (int j = 0; j < sizeOfArrays; j++)
		{
			resMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	return resMatrix;
}

int** Data::vectorToMatrix(int* vector)
{
	int** matrix = new int*[sizeOfArrays];

	for (int i = 0; i < sizeOfArrays; i++)
	{
		matrix[i] = new int[sizeOfArrays];
	}

	for (int i = 0; i < sizeOfArrays; i++)
	{
		for (int j = 0; j < sizeOfArrays; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < sizeOfArrays; i++) {
		matrix[0][i] = vector[i];
	}

	return matrix;
}


int* Data::matrixToVector(int** matrix)
{
	int* vector = new int[sizeOfArrays];
	int indexOfVector = 0;

	for (int i = 0; i < sizeOfArrays; i++) {
		for (int j = 0; j < sizeOfArrays; j++) {
			if (matrix[i][j] != 0) vector[indexOfVector++] = matrix[i][j];
		}
	}

	return vector;
}

int** Data::multMatrix(int** matrix1, int** matrix2)
{
	int** resultMatrix = new int*[sizeOfArrays];

	for (int i = 0; i < sizeOfArrays; i++)
	{
		resultMatrix[i] = new int[sizeOfArrays];
	}

	for (int i = 0; i < sizeOfArrays; i++)
	{
		for (int j = 0; j < sizeOfArrays; j++)
		{
			resultMatrix[i][j] = 0;
		}

	}

	for (int i = 0; i < sizeOfArrays; i++) {
		for (int j = 0; j < sizeOfArrays; j++) {
			for (int k = 0; k < sizeOfArrays; k++) {
				resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return resultMatrix;
}

int** Data::transMatrix(int** matrix)
{
	int** transMatr = new int*[sizeOfArrays];

	for (int i = 0; i < sizeOfArrays; i++)
	{
		transMatr[i] = new int[sizeOfArrays];
	}

	for (int i = 0; i < sizeOfArrays; i++)
	{
		for (int j = 0; j < sizeOfArrays; j++)
		{
			transMatr[i][j] = 0;
		}
	}

	for (int i = 0; i < sizeOfArrays; i++) {
		for (int j = 0; j < sizeOfArrays; j++) {
			transMatr[i][j] = matrix[j][i];
		}
	}
	return transMatr;
}

int Data::maxOfMatrix(int ** matrix)
{
	int max = matrix[0][0];

	for (int i(0); i < this->sizeOfArrays; i++)
		for (int j(0); j < this->sizeOfArrays; j++)
			if (matrix[i][j] > max)
				max = matrix[i][j];

	return max;
}

int Data::dotProduct(int * vector1, int * vector2)
{
	int result = 0;

	for (int i = 0; i < sizeOfArrays; i++)
		result += vector1[i] * vector2[i];

	return result;
}

int** Data::sortMatrix(int ** matrix)
{
	int temp;

	for (int k = 0; k < sizeOfArrays; k++)
	{
		for (int i = 0; i < sizeOfArrays - 1; i++)
		{
			for (int j = i + 1; j < sizeOfArrays; j++)
			{
				if (matrix[k][i] > matrix[k][j])
				{
					temp = matrix[k][i];
					matrix[k][i] = matrix[k][j];
					matrix[k][j] = temp;
				}
			}
		}
	}

	return matrix;
}
