#include <iostream>
#include <string>
#include <vector>
using namespace std;


double CalcSSD(vector<double> matrix1, vector<double> matrix2, int wallycolums) {
	double SumSquareDiff = 0;
	double difference = 0;
	for (int i = 0; i <= 3 - 1; i++) {
		for (int j = 0; j <= 3 - 1; j++) {
			int k = i * wallycolums + j;
			difference = matrix1[k] - matrix2[k];
			SumSquareDiff += difference * difference;
		}
	}
	return SumSquareDiff;
}

int main(){

	//k = i x N + j

	//Where I = num1 & J = num2 & N = number of columns in A

	const int baserows = 4;
	const int basecols = 11;
	const int wallyrows = 3;
	const int wallycols = 3;

	double baseimagearray[baserows][basecols] = {
		{ 1,6,4,7,2,6,3,8,1,3,5 },
		{ 5,8,2,4,8,7,2,9,1,3,6 },
		{ 1,5,8,3,8,2,4,6,7,9,8 },
		{ 6,1,8,3,8,2,6,4,8,9,9 }
	};

	double wallyarray[wallyrows][wallycols] = {

		{7,2,9},
		{2,4,6},
		{2,6,4}

	};

	vector<double> baseimagear;
	vector<double> wallyar;

	for (int i = 0; i <= baserows - 1; i++) {
		for (int j = 0; j <= basecols - 1; j++) {
			int k = i * basecols + j;
			baseimagear.push_back(baseimagearray[i][j]);
		}
	}

	for (int i = 0; i <= wallyrows - 1; i++) {
		for (int j = 0; j <= wallycols - 1; j++) {
			int k = i * wallycols + j;
			wallyar.push_back(wallyarray[i][j]);
		}
	}


	for (int i = 0; i <= baserows - wallyrows; i++) {
		for (int j = 0; j <= basecols - wallycols; j++) {

			vector <double> tempmatrix;

			for (int a = 0; a <= wallyrows - 1; a++) {
				for (int b = 0; b <= wallycols - 1; b++) {

					tempmatrix.push_back(baseimagear[((i + a) * basecols + (j + b))]);
						
				}
			}
			double tempans = CalcSSD(wallyar, tempmatrix, wallycols);
			cout << tempans << endl;
			tempmatrix.clear();
		};
	};
}