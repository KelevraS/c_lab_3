#include <stdio.h>
#include <stdlib.h>

#include "arrayUtil.h"
#include "fileUtil.h"

char pathToFile[256];
int elementCount;
float* arr = NULL;
float** arr2d = NULL;

int rowCount, colCount;

int main_input(void)
{
	//pathToFile = getPath();
	getPath(pathToFile, (unsigned)_countof(pathToFile));
	/*
	printf_s("Input row and col count:\n");
	scanf_s("%d %d", &rowCount, &colCount);

	arr2d = create2DynamicArr(rowCount, colCount);

	input2DArray(arr2d, rowCount, colCount);

	print2DArray(arr2d, rowCount, colCount);

	FILE* fp;
	fopen_s(&fp, pathToFile, "w");
	save2DArrayToFile(arr2d, rowCount, colCount, fp);
	fclose(fp);

	free(arr);
	*/

	FILE* fp;
	fopen_s(&fp, pathToFile, "r");
	getArrayDimension(fp, &rowCount, &colCount);
	arr2d = create2DynamicArr(rowCount, colCount);
	load2DArrayFromFile(arr2d, &rowCount, &colCount, fp);

	printf_s("Loaded array:\n");

	print2DArray(arr2d, rowCount, colCount);

	free(arr2d);

	printf_s("%d %d", rowCount, colCount);

	return 0;
}