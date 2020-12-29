#include <math.h>
//#include "arrayUtil.h"

int rowCount, colCount;

void matrix_m_vector(float** m, float* v, float* res)
{
	for (int i = 0; i < rowCount; i++)
	{
		res[i] = 0;

		for (int j = 0; j < colCount; j++)
		{
			res[i] += m[i][j] * v[j];
		}
	}
}

void vector_m_vector(float* v1, float* v2, float* res)
{
	for (int i = 0; i < colCount; i++)
	{
		*res += v1[i] + v2[i];
	}
}

void calculate_eigen(float** A, int rowCount, int colCount)
{
	float *Xn, *Xn1;
	float L = 10;

	//Xn = createDynamicArr(colCount);
	//Xn1 = createDynamicArr(colCount);
	Xn = NULL;
	Xn1 = NULL;

	while (1)
	{
		matrix_m_vector(A, Xn, Xn1);
		float num = 0, den = 0;
		vector_m_vector(Xn1, Xn, &num);
		vector_m_vector(Xn, Xn, &den);
		float Lprev = L;
		L = num / den;
		if ((fabs(L - Lprev) < 0.000001)) break;
		for (int i = 0; i < colCount; i++)
		{
			Xn[i] = Xn1[i];
		}
	}
}

