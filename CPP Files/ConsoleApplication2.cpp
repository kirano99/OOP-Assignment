// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Equations:

//k = i x N + j

//k = (N x I) + J

//I = (k - j) / N

//J = (N x I) + k

#include <iostream>
using namespace std;

class Matrix {

public:
	double get(double B[], int i, int j) {

		double N = 2;

		int result = i * N + j;

		return B[result];
	}
};

int main()
{
	Matrix MatrixObj;

	double B[] = { 11, 12, 13, 14, 15, 16 };

	int i = 2;
	int j = 1;

	double result = MatrixObj.get(B, i, j);

	cout << result;
}
