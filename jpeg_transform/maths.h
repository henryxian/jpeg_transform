#ifndef MATHS_H
#define MATHS_H

#include <math.h>
#include "matrixio.h"
//#define _USE_MATH_DEFINES
const double PI = 3.14159265358979323846;

void matrix_transpose(double t1[8][8], double t2[8][8]);

void coefficient(double mat[8][8]);

void matrix_multiply(double t1[8][8], double t2[8][8], double t[8][8]);

void DCT(double mat[8][8]);

void IDCT(double mat[8][8]);

void quantize(matrix, matrix);

void dequantize(matrix, matrix);

#endif