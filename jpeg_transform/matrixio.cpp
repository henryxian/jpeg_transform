#include "matrixio.h"
#include "maths.h"

using namespace std;

void input_matrix(ifstream &ifs, matrix mat) {
	int i = 0, j = 0;
	int n = 0;
	string s;
	string temp;
	while (getline(ifs, s)){
		istringstream is(s);
		//cout << s << endl;
		while (is >> temp){
			mat[i][j++] = hexstr_to_int(temp);
			//mat[i][j++] = atoi(temp.c_str());
		}
		j = 0;
		i++;
	}
}

void output_matrix(ofstream &ofs, matrix mat) {
	for (size_t idx = 0; idx < 8; idx++) {
		for (size_t idy = 0; idy < 8; idy++)
		{
			ofs << mat[idx][idy] << " ";
		}
		ofs << "\n";
	}
}

//void main(int argc, char **argv) {
//	string test1("11");
//	string test2("FF");
//	cout << hexstr_to_int(test1) <<endl;
//	cout << hexstr_to_int(test2) << endl;
//	system("pause");
//}

//void main(int argc, char ** argv) {
//	string temp;
//	ifstream ifs("dataset1.txt");
//	int matrix[8][8];
//	input_matrix(ifs, matrix);
//	//cout << int(matrix[0][0]) << endl;
//	matrix_print(cout, matrix);
//	ofstream ofs("output.txt");
//	output_matrix(ofs, matrix);
//	system("pause");
//}

// change the hex string into integer
int hexstr_to_int(const string &s){
	unsigned int offset = 16;
	int result = 0;
	for (const auto i : s){
		result *= offset;
		if (isdigit(i)){
			result += (i - '0');
		}
		if (isalpha(i)){
			result += (i - 55);
		}
	}
	return result;
}

// print matrix
void matrix_print(ostream &os, matrix mat) {
	for (size_t idx = 0; idx < 8; idx++) {
		for (size_t idy = 0; idy < 8; idy++)
		{
			os << mat[idx][idy] << " ";
		}
		os << "\n";
	}
}

void print_result(ostream& os, matrix mat, matrix qua_table) {
	os << "-------------- 原始矩阵 --------------" << "\n";
	matrix_print(os, mat);
	os << "------------- 经过DCT之后的矩阵 ------" << "\n";
	DCT(mat);
	matrix_print(os, mat);
	os << "------------- 量化后的矩阵 ----------" << "\n";
	quantize(mat, qua_table);
	matrix_print(os, mat);
	os << "------------- 逆量化后的矩阵 ----------" << "\n";
	dequantize(mat, qua_table);
	matrix_print(os, mat);
	os << "------------- ICDT后的矩阵 ------------" << "\n";
	IDCT(mat);
	matrix_print(os, mat);
}
