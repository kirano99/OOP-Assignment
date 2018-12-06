#include <iostream>
#include <string>
#include <vector>

using namespace std;


double CalcSSD(vector<vector<double>*> matrix1[3][3], vector<vector<double>*> matrix2[3][3]) {
	double SumSquareDiff = 0;
	double difference = 0;
	for (int i = 0; i <= 3 - 1; i++) {
		for (int j = 0; j <= 3 - 1; j++) {
			difference = (*matrix1[i])[j] - (*matrix2[i])[j];
			SumSquareDiff += difference * difference;
		}
	}
	return SumSquareDiff;
}

int main(){

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

	double wallyar[wallyrows][wallycols] = {

		{7,2,9},
		{2,4,6},
		{2,6,4}

	};

	vector<vector<double>> baseimagear[baserows][basecols];







	for (int i = 0; i <= baserows - wallyrows; i++) {
		for (int j = 0; j <= basecols - wallycols; j++) {

			vector<vector<double>> tempmatrix[wallyrows][wallycols];

			for (int a = 0; a <= wallyrows - 1; a++) {
				for (int b = 0; b <= wallycols - 1; b++) {

					tempmatrix[a][b] = baseimagear[i + a][j + b];

				}
			}
			double tempans = CalcSSD(wallyar, tempmatrix);
			cout << tempans << endl;
			memset(tempmatrix, 0, sizeof(tempmatrix[0][0]) * wallyrows * wallycols);
		};
	};
}