#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "fileUtil.h"
#include "arrayUtil.h"
#include "customop.h"

#define ITERATIONS 10

int getFactorial(int n)
{
	int res = 1;

	for (int i = 0; i < n; i++)
		res *= i + 1;

	return res;
}

void calculate_exponent(float **source, float **res, int rowCount, int colCount)
{
	float** temp = create2DynamicArr(rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < rowCount; j++)
		{
			res[i][j] = source[i][j];
		}
	}

	for (int i = 1; i < ITERATIONS; i++)
	{
		for (int j = 1; j < i; j++)
		{
			multiplicateArray(source, source, temp, rowCount, colCount, rowCount, colCount);
		}

		for (int j = 0; j < rowCount; j++)
		{
			for (int k = 0; k < rowCount; k++)
				temp[j][k] /= getFactorial(i);
		}

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < rowCount; j++)
			{
				res[i][j] = temp[i][j];
			}
		}

		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < rowCount; j++)
			{
				temp[i][j] = 0;
			}
		}
	}
}


char pathA[256];

void exponent()
{
	int rowCountA, colCountA;
	float** a = NULL;

	FILE* fp;
	getPath(pathA, (unsigned)_countof(pathA));

	if (fopen_s(&fp, pathA, "r") != 0)
	{
		perror("File error occured in reading! ", pathA);
		return 1;
	}

	getArrayDimension(fp, &rowCountA, &colCountA);
	a = create2DynamicArr(rowCountA, colCountA);
	load2DArrayFromFile(a, &rowCountA, &colCountA, fp);
	print2DArray(a, rowCountA, colCountA);
	fclose(fp);

	float** b = create2DynamicArr(rowCountA, colCountA);

	calculate_exponent(a, b, colCountA, rowCountA);

	print2DArray(b, colCountA, rowCountA);
}