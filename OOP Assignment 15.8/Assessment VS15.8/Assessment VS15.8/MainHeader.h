#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

//loading animation function
void loading()
{
	std::cout << '-' << std::flush;
	for (;;) {
		Sleep(100);
		std::cout << "\b\\" << std::flush;
		Sleep(100);
		std::cout << "\b|" << std::flush;
		Sleep(100);
		std::cout << "\b/" << std::flush;
		Sleep(100);
		std::cout << "\b-" << std::flush;
	}
}

//cpp functions
double* read_text(char *fileName, int sizeR, int sizeC);
void write_pgm(char *filename, double *data, int sizeR, int sizeC, int Q);

//classes
class NNS{
public:
	double CalcSSD(vector<unsigned char> matrix1, vector<unsigned char> matrix2, int wallycolums, int wallyrows) {
		double SumSquareDiff = 0;
		double difference = 0;
		for (int i = 0; i <= wallyrows - 1; i++) {
			for (int j = 0; j <= wallycolums - 1; j++) {
				int k = i * wallycolums + j;
				if (matrix1[k] == 255) {
					matrix1[k] = matrix2[k];
				}

				difference = matrix1[k] - matrix2[k];

				SumSquareDiff += difference * difference;
			}
		}
		return SumSquareDiff;
	}
	vector <unsigned char> tempmatrix;

};

class Base_Image {
public:
	double highlightedscene[786432];
};

class Ref_Image : public Base_Image {
private:
	int rows;
	int cols;

public:

	Ref_Image() {
		rows = 49;
		cols = 36;
		cout << "Ref_Image obj created" << endl;
	}
	virtual ~Ref_Image() {
		cout << "Ref_Image obj deleted" << endl;
	}
	const int getrows() {
		return rows;
	}
	const int getcols() {
		return cols;
	}
};

class Large_Image : public Base_Image {

public:
	int rows;
	int cols; 

	Large_Image() {
		rows = 768;
		cols = 1024;
		cout << "Large_Image obj created" << endl;
	}
	virtual ~Large_Image() {
		cout << "Large_Image obj deleted" << endl;
	}
	const int getrows() {
		return rows;
	}
	const int getcols() {
		return cols;
	}
};

class Matrix {
private:
	int i = 0;
	int r = 0;

public:
	double * basereturndata;
	double * wallyreturndata;

	char wallyfilename[15] = "Wally_grey.txt";
	char * wallyfilenamept;

	char wallypgmfilename[15] = "Wally_grey.pgm";
	char * wallypgmfilenamept;

	char basefilename[20] = "Cluttered_scene.txt";
	char * basefilenamept;

	char basepgmfilename[20] = "Cluttered_scene.pgm";
	char * basepgmfilenamept;;

	Matrix() {

		wallyfilenamept = wallyfilename;
		wallypgmfilenamept = wallypgmfilename;
		basefilenamept = basefilename;
		basepgmfilenamept = basepgmfilename;

		cout << "Matrix obj created" << endl;
	}
	virtual ~Matrix() {
		cout << "Matrix obj deleted" << endl;
	}

	friend Matrix operator--(const Matrix& i);
};

Matrix operator--(const Matrix& i) {
	Matrix result;

	result.r = i.i * i.i;

	return result;

}
