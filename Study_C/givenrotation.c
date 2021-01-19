#include <stdio.h>
#include <stdlib.h>
#include "fileUtil.h"
#include "arrayutil.h"

void Givens(int n, float** A, float** V, int Nrun, double tol)
{
	int i, j, k, p, q, r;
	float c, s, t, tau, tmax, alpha, xp, xq, eps = 1.0E-22;
	float sum;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == j) V[i][j] = 1.0;  else V[i][j] = 0.0;

	for (k = 0; k < Nrun; k++) {
		tmax = -1;
		sum = 0.0;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++) {
				t = fabs(A[i][j]);
				sum += (t * t);
				if (t > tmax) { tmax = t; p = i; q = j; }
			}
		sum = sqrt(2.0 * sum);
		if (sum < tol)  return;
		alpha = (A[q][q] - A[p][p]) / 2.0 / A[p][q];
		t = ((alpha > eps) ? 1.0 / (alpha + sqrt(1.0 + alpha * alpha)) :
			(alpha < eps) ? 1.0 / (alpha - sqrt(1.0 + alpha * alpha)) : 1.0);

		c = 1.0 / sqrt(1.0 + t * t);
		s = c * t;
		tau = s / (1.0 + c);

		/*--------------------------------------------------------------------------*/
		/*  A^(k+1)  \leftarrow J_k^t A^k J_k                                       */
		/*--------------------------------------------------------------------------*/
		for (r = 0; r < p; r++)     A[p][r] = c * A[r][p] - s * A[r][q];
		for (r = p + 1; r < n; r++)   if (r != q) A[r][p] = c * A[p][r] - s * A[q][r];

		for (r = 0; r < p; r++)     A[q][r] = s * A[r][p] + c * A[r][q];
		for (r = p + 1; r < q; r++)   A[q][r] = s * A[p][r] + c * A[r][q];
		for (r = q + 1; r < n; r++)   A[r][q] = s * A[p][r] + c * A[q][r];

		A[p][p] = A[p][p] - t * A[p][q];
		A[q][q] = A[q][q] + t * A[p][q];
		A[q][p] = 0.0;

		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				A[i][j] = A[j][i];
		/*--------------------------------------------------------------------------*/
		/* Eigenvectors are stored in the columns of V                              */
		/*--------------------------------------------------------------------------*/
		for (i = 0; i < n; i++) {
			xp = V[i][p];
			xq = V[i][q];
			V[i][p] = c * xp - s * xq;
			V[i][q] = s * xp + c * xq;
		}
	}
}

char pathA[256];

void eigenGivens()
{
	int Nrun = 31;
	double tol = 1.0E-22;

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

	float **v = create2DynamicArr(rowCountA, colCountA);

	Givens(rowCountA, a, v, Nrun, tol);

	printf_s("Eigenvalues: \n");
	for (int i = 0; i < rowCountA; i++)
	{
		printf_s("%f", a[i][i]);
	}
	printf_s("\n");
	printf_s("\n");
	printf_s("Eigenvectors (in columns):\n");
	for (int i = 0; i < rowCountA; i++) 
	{
		for (int j = 0; j < rowCountA; j++)
		{
			printf_s("%f", v[i][j]);
		}
		printf_s("\n");
	}
}