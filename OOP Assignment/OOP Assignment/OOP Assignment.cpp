#include <iostream>
#include <string>
#include <vector>

using namespace std;


double CalcSSD(double matrix1[4][11], double matrix2[3][3], int size) {
	double SumSquareDiff = 0;
	double difference = 0;
	for (int i = 0; i <= 3 - 1; i++) {
		for (int j = 0; j <= 3 - 1; j++) {
			difference = matrix1[i][j] - matrix2[i][j];
			SumSquareDiff += difference * difference;
		}
	}
	return SumSquareDiff;
}

int main(){

	double baseimagear[4][11] = {

		{1,6,4,7,2,6,3,8,1,3,5},
		{5,8,2,4,8,7,2,9,1,3,6},
		{1,5,8,3,8,2,4,6,7,9,8},
		{6,1,8,3,8,2,6,4,8,9,9}

	};

	double wallyar[3][3] = {

		{7,2,9},
		{2,4,6},
		{2,6,4}

	};

	int baserows = sizeof baseimagear / sizeof baseimagear[0]; // Get Number of Rows
	int basecols = sizeof baseimagear[0] / sizeof(int); // Get Number of Columns

	int wallyrows = sizeof wallyar / sizeof wallyar[0]; // Get Number of Rows
	int wallycols = sizeof wallyar[0] / sizeof(int); // Get Number of Columns
	
	for (int i = 0; i <= baserows - wallyrows; i++) {
		for (int j = 0; j <= basecols - wallycols; j++) {

			double tempmatrix[3][3] = {
				{baseimagear[i][j], baseimagear[i][j + 1], baseimagear[i][j + 2]},
				{baseimagear[i + 1][j], baseimagear[i][j + 1], baseimagear[i][j + 2]},
				{baseimagear[i + 2][j], baseimagear[i][j + 1], baseimagear[i][j + 2]}
			};

			double tempans = CalcSSD(baseimagear, tempmatrix, 3);
				cout << tempans << endl;

		};
	};


}