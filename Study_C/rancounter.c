#include <stdio.h>
#include <stdlib.h>
#include "fileUtil.h"
#include "arrayUtil.h"

void swap(float** a, int row1, int row2, int col)
{
	for (int i = 0; i < col; i++)
	{
		int temp = a[row1][i];
		a[row1][i] = a[row2][i];
		a[row2][i] = temp;
	}
}

int rankOfMatrix(float **a, int row, int col)
{
	int R = row;
	int C = col;

	int rank = C;

	for (int row = 0; row < rank; row++)
	{
		if (a[row][row])
		{
			for (int col = 0; col < R; col++)
			{
				if (col != row)
				{
					float mult = (float)a[col][row] / a[row][row];

					for (int i = 0; i < rank; i++)
					{
						a[col][i] -= mult * a[row][i];
					}
				}
			}
		}
		else
		{
			char reduce = 1;

			for (int i = row + 1; i < R; i++)
			{
				if (a[i][row])
				{
					swap(a, row, i, rank);
					reduce = 0;
					break;
				}
			}

			if (reduce)
			{
				rank--;

				for (int i = 0; i < R; i++)
				{
					a[i][row] = a[i][rank];
				}
			}

			row--;
		}
	}

	return rank;
}

char pathA[256];

void rank()
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

	printf_s("Rank of matrix: %d", rankOfMatrix(a, rowCountA, colCountA));
}