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
	//ofstream ofs("dataset_out.txt");

	double matrix[8][8];
	double qua_table[8][8];

	input_matrix(ifs, matrix);
	input_matrix(ifs_qua, qua_table);

	cout << "-------------- 原始矩阵 --------------" << endl;
	matrix_print(cout, matrix);
	cout << "------------- 经过DCT之后的矩阵 ------" << endl;
	DCT(matrix);
	matrix_print(cout, matrix);
	cout << "------------- 量化后的矩阵 ----------" << endl;
	quantize(matrix, qua_table);
	matrix_print(cout, matrix);
	cout << "------------- 逆量化后的矩阵 ----------" << endl;
	dequantize(matrix, qua_table);
	matrix_print(cout, matrix);
	cout << "------------- ICDT后的矩阵 ------------" << endl;
	IDCT(matrix);
	matrix_print(cout, matrix);

	//matrix_print(cout, matrix);
	//DCT(matrix);
	//matrix_print(cout, matrix);
	//IDCT(matrix);
	//matrix_print(cout, matrix);

	system("pause");
}