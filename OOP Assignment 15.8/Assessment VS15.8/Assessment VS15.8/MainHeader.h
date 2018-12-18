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
		Sleep(10);
		std::cout << "\b\\" << std::flush;
		Sleep(10);
		std::cout << "\b|" << std::flush;
		Sleep(10);
		std::cout << "\b/" << std::flush;
		Sleep(10);
		std::cout << "\b-" << std::flush;
	}
}

//cpp functions
double* read_text(char *fileName, int sizeR, int sizeC);
void write_pgm(char *filename, double *data, int sizeR, int sizeC, int Q);

//classes
class NNS {
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
public:
	double * basereturndata;
	double * wallyreturndata;
};

class Overload {

	double a;
	double result;

	friend Overload operator!(Overload a) {

	}
};

Overload operator!(Overload a) {

	Overload a;
	a.result = a.a*a.a;
	return (a);

}
