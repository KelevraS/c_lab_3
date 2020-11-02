#include <stdio.h>
#include <math.h>
#include <time.h>

int** createDynamicArr(int rank)
{
	int** a = malloc(rank * sizeof(int*));

	for (int i = 0; i < rank; i++)
	{
		a[i] = malloc(rank * sizeof(int));

		for (int j = 0; j < rank; j++)
		{
			a[i][j] = 0;
		}
	}

	return a;
}

int** createRandomDynamicArr(int rank, int value)
{
	srand(time(NULL));

	int** a = malloc(rank * sizeof(int*));

	for (int i = 0; i < rank; i++)
	{
		a[i] = malloc(rank * sizeof(int));

		for (int j = 0; j < rank; j++)
		{
			a[i][j] = rand() % value;
		}
	}

	return a;
}

int** createInputDynamicArr(int rank)
{
	int** a = createDynamicArr(rank);

	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			printf_s("Input element A[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}

	return a;
}

void printArray(int** a, int rank)
{
	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			printf_s("%d\t", a[i][j]);
		}
		printf_s("\n");
	}
}

const char* Delimiter = "|------------------------------------------------------|\n";

int* createMinor(int** a, int row, int col, int rank)
{
	int minorRank = rank - 1;
	int** minor = createDynamicArr(minorRank);

	int iMinor = 0;

	for (int i = 0; i < rank; i++)
	{
		int jMinor = 0;

		if (i == row)
			continue;
		
			for (int j = 0; j < rank; j++)
			{
				if (j == col)
					continue;
					minor[iMinor][jMinor] = a[i][j];
					jMinor++;
			}
			iMinor++;
	}

	printf_s("Minor for element A[%d][%d] in rank %d, where minor is:\n", row, col, rank);
	printArray(minor, minorRank);
	printf_s(Delimiter);

	return minor;
}

int calculateDeter(int** a, int rank)
{
	int sum = 0;

	if (rank == 1)
	{
		sum += **a;
		return sum;
	}

	int** minor;

	for (int col = 0; col < rank; col++)
	{
		int alternating = -1 * (col % 2 ? 1 : -1);
		printf_s("a[%d][%d] = %d\n", 0, col, a[0][col]);
		printf_s("(-1)^(%d + %d) = %d\n", 0 + 1, col + 1, alternating);
		minor = createMinor(a, 0, col, rank);
		sum += alternating * a[0][col] * calculateDeter(minor, rank - 1);
	}

	//free(minor);
	return sum;
}

int main(void)
{
	int rank = 0;

	printf_s("Input matrix rank: ");
	int rankInput = scanf_s("%d", &rank);

	if (rankInput < 1)
	{
		perror("Incorrect rank input!");
		return 1;
	}

	int** a = createInputDynamicArr(rank);

	printArray(a, rank);

	printf_s("Determinant: %d\n", calculateDeter(a, rank));

	free(a);
	return 0;

}