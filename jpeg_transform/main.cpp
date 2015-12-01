#include "maths.h"
#include "matrixio.h"


void main(int argc, char **argv) {
	//string temp;
	//ifstream ifs("dataset1.txt");
	const string data_in1 = "dataset1.txt";
	const string data_in2 = "dataset2.txt";
	const string data_in3 = "dataset3.txt";
	const string data_in4 = "dataset4.txt";

	ifstream ifs("dataset.txt");
	ifstream ifs_qua("matrice_in\\qua_table1.txt");
	double matrix[8][8];
	double qua_table[8][8];

	input_matrix(ifs, matrix);
	input_matrix(ifs_qua, qua_table);

	DCT(matrix);
	ofstream ofs("output.txt");
	//output_matrix(ofs, matrix);
	matrix_print(cout, matrix);
	quantize(matrix, qua_table);
	matrix_print(cout, matrix);
	
	system("pause");
}