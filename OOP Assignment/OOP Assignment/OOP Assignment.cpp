#include <iostream>
#include <string>
#include <vector>
#include "MainHeader.h"


using namespace std;

class Base_Image {

};

class NNS {
public:
	double CalcSSD(vector<double> matrix1, vector<double> matrix2, int wallycolums, int wallyrows) {
		double SumSquareDiff = 0;
		double difference = 0;
		for (int i = 0; i <= wallycolums - 1; i++) {
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
};

class Ref_Image : public Base_Image {
public:
	const int rows = 49;
	const int cols = 36;
};

class Large_Image : public Base_Image {

public:
	const int rows = 768;
	const int cols = 1024;
};
class Matrix {
private:
		int num1, num2;
	public:
		Matrix(int a, int b) { num1 = a; num2 = b; }

		int operator /() {
			return float(num1) + float(den2);
		}
};

int main(){

	Ref_Image wallyobj;
	Large_Image baseobj;

	int test = wallyobj.rows;

	char wallyfilename[15] = "Wally_grey.txt";
	char * wallyfilenamept = wallyfilename;

	char wallypgmfilename[15] = "Wally_grey.pgm";
	char * wallypgmfilenamept = wallypgmfilename;
	
	double * wallyreturndata = read_text(wallyfilenamept, wallyobj.rows, wallyobj.cols);

	write_pgm(wallypgmfilenamept, wallyreturndata, wallyobj.rows, wallyobj.cols, 255);

	char basefilename[20] = "Cluttered_scene.txt";
	char * basefilenamept = basefilename;

	char basepgmfilename[20] = "Cluttered_scene.pgm";
	char * basepgmfilenamept = basepgmfilename;

	double * basereturndata = read_text(basefilenamept, baseobj.rows, baseobj.cols);

	write_pgm(basepgmfilenamept, basereturndata, baseobj.rows, baseobj.cols, 255);

	//k = i x N + j

	//Where I = num1 & J = num2 & N = number of columns in A

	vector<double> baseimagear;
	vector<double> wallyar;

	for (int i = 0; i <= baseobj.rows - 1; i++) {
		for (int j = 0; j <= baseobj.cols - 1; j++) {
			int k = i * baseobj.cols + j;
			baseimagear.push_back(basereturndata[k]);
		}
	}

	for (int i = 0; i <= wallyobj.rows - 1; i++) {
		for (int j = 0; j <= wallyobj.cols - 1; j++) {
			int k = i * wallyobj.cols + j;
			wallyar.push_back(wallyreturndata[k]);
		}
	}

	double resultarry[5] = {};
	int comparisons = 0;
	NNS Searcherobj;

	for (int i = 0; i <= baseobj.rows - wallyobj.rows; i++) {
		for (int j = 0; j <= baseobj.cols - wallyobj.cols; j++) {

			vector <double> tempmatrix;

			for (int a = 0; a <= wallyobj.rows - 1; a++) {
				for (int b = 0; b <= wallyobj.cols - 1; b++) {

					tempmatrix.push_back(baseimagear[((i + a) * baseobj.cols + (j + b))]);
						
				}
			}
			double tempans = Searcherobj.CalcSSD(wallyar, tempmatrix, wallyobj.cols, wallyobj.rows);
			//comparisons++;
			//cout << tempans << "\t \t \t" << comparisons << " comparisons out of " << "710372" << "\n";
			if (tempans < resultarry[0] || i == 0 && j == 0 ) {
				resultarry[0] = tempans;
				resultarry[1] = i;
				resultarry[2] = j;
			}
			tempmatrix.clear();
		};
	};
	cout << resultarry[0] << resultarry[1] << resultarry[2] << "\n";

	//CODE BELOW WILL NOT COMPILE 
	//STACK OVERFLOW

	const int wallysum = wallyobj.rows * wallyobj.cols;
	const int basesum = baseobj.rows * baseobj.cols;


	double temp[wallysum];
	double highlightedscene[basesum];

	int q = resultarry[1]; //SHOULD BE 144
	int w = resultarry[2]; //SHOULD BE 162
	int c = 0;


	for (int e = 0; e <= baseobj.rows - 1; e++) {
		for (int f = 0; f <= baseobj.rows - 1; f++) {

			int k = e * baseobj.cols + f;
			highlightedscene[k] = baseimagear[k];

			if (e >= q && f >= w && e < q + wallyobj.rows && f < w + wallyobj.cols) {
				highlightedscene[k] = 0;
			}

		}
	}

	char name2[21] = "highlightedscene.pgm";
	char * namept2 = name2;
	double * data2 = highlightedscene;

	write_pgm(namept2, data2, baseobj.rows, baseobj.cols, 255);



}