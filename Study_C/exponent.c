#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "fileUtil.h"
#include "arrayUtil.h"
#include "customop.h"

#define ITERATIONS 10

void calculate_exponent(float **source, float **res, int rowCount, int colCount)
{
	for (int i = 0; i < ITERATIONS; i++)
	{
		
	}
}

int getFactorial(int n)
{
	int res = 1;

	for (int i = 0; i < n; i++)
		res *= i + 1;

	return res;
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
}