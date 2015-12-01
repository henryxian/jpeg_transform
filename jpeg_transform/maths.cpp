#include "maths.h"
#include "matrixio.h"

void matrix_transpose(double t1[8][8], double t2[8][8]) {
	for (size_t idx = 0; idx < 8; idx++)
	{
		for (size_t idy = 0; idy < 8; idy++)
		{
			t2[idx][idy] = t1[idy][idx];
		}
	}
}

void coefficient(double mat[8][8]) {
	double square = 1 / sqrt(8.0);
	for (size_t i = 0; i < 8; i++)
	{
		mat[0][i] = square;
	}

	for (size_t i = 1; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			mat[i][j] = sqrt(2.0 / 8) * cos(i * PI * (j + 0.5) / 8.0);
		}
	}
}

void matrix_multiply(double t1[8][8], double t2[8][8], double t[8][8]) {
	double temp = 0;
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			temp = 0;
			for (size_t k = 0; k < 8; k++)
			{
				temp += t1[i][k] * t2[k][j];
			}
			t[i][j] = temp;
		}
	}
}

void DCT(double mat[8][8]) {
	double quotient[8][8];
	double quotientT[8][8];
	double temp[8][8];

	coefficient(quotient);
	matrix_transpose(quotient, quotientT);

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			mat[i][j] -= 128;
		}
	}

	matrix_multiply(quotient, mat, temp);
	matrix_multiply(temp, quotientT, mat);

	//for (size_t i = 0; i < 8; i++)
	//{
	//	for (size_t j = 0; j < 8; j++)
	//	{
	//		mat[i][j] = (int)mat[i][j];
	//	}
	//}
}

void quantize(matrix data_mat, matrix qua_table) {
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			data_mat[i][j] /= qua_table[i][j];
			data_mat[i][j] = (int)data_mat[i][j];
		}
	}
}
