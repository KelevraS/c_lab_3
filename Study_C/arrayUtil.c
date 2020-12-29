#include <stdio.h>
#include <stdlib.h>

void printArray(const float* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf_s("%f\t", arr[i]);
	}
}

void inputArray(float* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf_s("Input %d element:\n", i);
		scanf_s("%f", &arr[i]);
	}
}

void saveArrayToFile(const float* a, int length, FILE* fp)
{
	fwrite(&length, sizeof(length), 1, fp);

	for (int i = 0; i < length; i++)
	{
		fwrite(&a[i], sizeof(a[i]), 1, fp);
	}
}

void loadArrayFromFile(float* a, int* colCount, FILE* fp)
{
	fread(colCount, sizeof(*colCount), 1, fp);

	for (int i = 0; i < *colCount; i++)
	{
		fread(&a[i], sizeof(a[i]), 1, fp);
	}
}

void print2DArray(const float** arr, int rowCount, int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		printArray(arr[i], colCount);
		printf_s("\n");
	}
}

void input2DArray(float** arr, int rowCount, int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		inputArray(arr[i], colCount);
	}
}

float* createDynamicArr(int size)
{
	return malloc(size * sizeof(float));
}

float** create2DynamicArr(int rowCount, int colCount)
{
	float** arr2d = malloc(rowCount * sizeof(float*));

	for (int i = 0; i < rowCount; i++)
	{
		arr2d[i] = malloc(colCount * sizeof(float));
	}

	return arr2d;
}

void save2DArrayToFile(const float** a, int rowCount, int colCount, FILE* fp)
{
	fwrite(&rowCount, sizeof(rowCount), 1, fp);

	for (int i = 0; i < rowCount; i++)
	{
		saveArrayToFile(a[i], colCount, fp);
	}
}

void load2DArrayFromFile(float** a, int* rowCount, int* colCount, FILE* fp)
{
	fread(rowCount, sizeof(*rowCount), 1, fp);

	for (int i = 0; i < *rowCount; i++)
	{
		loadArrayFromFile(a[i], colCount, fp);
	}
}

void getArrayDimension(FILE* fp, int* rowCount, int* colCount)
{
	fread(rowCount, sizeof(*rowCount), 1, fp);
	fread(colCount, sizeof(*colCount), 1, fp);
	rewind(fp);
}