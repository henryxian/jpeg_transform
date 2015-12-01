#ifndef MATRIXIO_H
#define MATRIXIO_H

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

typedef double matrix[8][8];

void input_matrix(std::ifstream &, matrix);

void output_matrix(std::ofstream &, matrix);

int hexstr_to_int(const string &);

void matrix_print(ostream &, matrix);

void print_result(ostream &, matrix, matrix);

#endif