#include <iostream>
#include <string>
#include <vector>
#include "MainHeader.h"


using namespace std;


double CalcSSD(vector<double> matrix1, vector<double> matrix2, int wallycolums) {
	double SumSquareDiff = 0;
	double difference = 0;
	for (int i = 0; i <= wallycolums - 1; i++) {
		for (int j = 0; j <= wallycolums - 1; j++) {
			int k = i * wallycolums + j;
			difference = matrix1[k] - matrix2[k];
			SumSquareDiff += difference * difference;
		}
	}
	return SumSquareDiff;
}

int main(){


	const int baserows = 12288;
	const int basecols = 1024;
	const int wallyrows = 49;
	const int wallycols = 36;

	char wallyfilename[15] = "Wally_grey.txt";
	char * wallyfilenamept = wallyfilename;

	char wallypgmfilename[15] = "Wally_grey.pgm";
	char * wallypgmfilenamept = wallypgmfilename;
	
	double * wallyreturndata = read_text(wallyfilenamept,49,36);

	write_pgm(wallypgmfilenamept, wallyreturndata, 49, 36, 255);

	char basefilename[20] = "Cluttered_scene.txt";
	char * basefilenamept = basefilename;

	char basepgmfilename[20] = "Cluttered_scene.pgm";
	char * basepgmfilenamept = basepgmfilename;

	double * basereturndata = read_text(basefilenamept, 12288, 1024);

	write_pgm(basepgmfilenamept, basereturndata, 12288, 1024, 255);

	//k = i x N + j

	//Where I = num1 & J = num2 & N = number of columns in A

	vector<double> baseimagear;
	vector<double> wallyar;

	for (int i = 0; i <= baserows - 1; i++) {
		for (int j = 0; j <= basecols - 1; j++) {
			int k = i * basecols + j;
			baseimagear.push_back(basereturndata[k]);
		}
	}

	for (int i = 0; i <= wallyrows - 1; i++) {
		for (int j = 0; j <= wallycols - 1; j++) {
			int k = i * wallycols + j;
			wallyar.push_back(wallyreturndata[k]);
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