#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileUtil.h"
#include "arrayUtil.h"
#include "determinant.h"

char pathA[256], pathB[256], pathC[256];
char path[256];

void addition()
{
	int rowCountA, colCountA;
	int rowCountB, colCountB;
	int rowCountC, colCountC;
	float** a = NULL;
	float** b = NULL;
	float** c = NULL;

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

	getPath(pathB, (unsigned)_countof(pathB));

	if (fopen_s(&fp, pathB, "r") != 0)
	{
		perror("File error occured in reading! ", pathB);
		return 1;
	}

	getArrayDimension(fp, &rowCountB, &colCountB);
	b = create2DynamicArr(rowCountB, colCountB);
	load2DArrayFromFile(b, &rowCountB, &colCountB, fp);
	print2DArray(b, rowCountB, colCountB);
	fclose(fp);

	c = create2DynamicArr(rowCountA, colCountA);

	for (int i = 0; i < rowCountA; i++)
	{
		for (int j = 0; j < colCountA; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	getPath(pathC, (unsigned)_countof(pathC));

	if (fopen_s(&fp, pathC, "w") != 0)
	{
		perror("File error occured in writing ");
		return 1;
	}
	save2DArrayToFile(c, rowCountA, colCountA, fp);
	print2DArray(c, rowCountA, colCountA);
	fclose(fp);
}

void multiplication()
{
	int rowCountA, colCountA;
	int rowCountB, colCountB;
	int rowCountC, colCountC;
	float** a = NULL;
	float** b = NULL;
	float** c = NULL;

	FILE* fp;
	getPath(pathA, (unsigned)_countof(pathA));
	fopen_s(&fp, pathA, "r");
	getArrayDimension(fp, &rowCountA, &colCountA);
	a = create2DynamicArr(rowCountA, colCountA);
	load2DArrayFromFile(a, &rowCountA, &colCountA, fp);
	print2DArray(a, rowCountA, colCountA);
	fclose(fp);

	getPath(pathB, (unsigned)_countof(pathB));
	fopen_s(&fp, pathB, "r");
	getArrayDimension(fp, &rowCountB, &colCountB);
	b = create2DynamicArr(rowCountB, colCountB);
	load2DArrayFromFile(b, &rowCountB, &colCountB, fp);
	print2DArray(b, rowCountB, colCountB);
	fclose(fp);

	if (colCountA != rowCountB)
	{
		perror("Matricies are incompatible! ");
		return 2;
	}

	c = create2DynamicArr(rowCountA, colCountB);

	/*for (int i = 0; i < rowCountA; i++)
	{
		for (int j = 0; j < colCountB; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < colCountA; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}*/

	multiplicateArray(a, b, c, rowCountA, colCountA, rowCountB, colCountB);

	getPath(pathC, (unsigned)_countof(pathC));
	fopen_s(&fp, pathC, "w");
	save2DArrayToFile(c, rowCountA, colCountA, fp);
	print2DArray(c, rowCountA, colCountA);
	fclose(fp);
}

void multiplicateArray(float** a, float** b, float** c, int rowCountA, int colCountA, int rowCountB, int colCountB)
{
	for (int i = 0; i < rowCountA; i++)
	{
		for (int j = 0; j < colCountB; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < colCountA; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void determinant()
{
	int rowCountA, colCountA;
	float result;

	float** a = NULL;

	FILE* fp;
	getPath(pathA, (unsigned)_countof(pathA));
	fopen_s(&fp, pathA, "r");
	getArrayDimension(fp, &rowCountA, &colCountA);
	a = create2DynamicArr(rowCountA, colCountA);
	load2DArrayFromFile(a, &rowCountA, &colCountA, fp);
	print2DArray(a, rowCountA, colCountA);
	fclose(fp);

	result = calculateDeterF(a, rowCountA);
	printf_s("Determinant = %f", result);
}