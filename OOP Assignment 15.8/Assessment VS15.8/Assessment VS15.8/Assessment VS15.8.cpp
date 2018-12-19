#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "MainHeader.h"
using namespace std;

int main() {

	Ref_Image wallyobj;
	Large_Image baseobj;
	Matrix* matrixobj = new Matrix;		//initialize objects

	const int wallyrows = wallyobj.getrows();
	const int wallycols = wallyobj.getcols();
	const int baserows = baseobj.getrows();
	const int basecols = baseobj.getcols();		//get values

	matrixobj->wallyreturndata = read_text(matrixobj->wallyfilenamept, wallyrows, wallycols);	//read text file for wally

	write_pgm(matrixobj->wallypgmfilenamept, matrixobj->wallyreturndata, wallyrows, wallycols, 255);	//write pgm for wally

	matrixobj->basereturndata = read_text(matrixobj->basefilenamept, baserows, basecols);		//read text file for base

	write_pgm(matrixobj->basepgmfilenamept, matrixobj->basereturndata, baserows, basecols, 255);	//write pgm for base

	//k = i x N + j

	//Where I = num1 & J = num2 & N = number of columns in A		

	vector<unsigned char> baseimagear;
	vector<unsigned char> wallyar;					//Initilaize Vectors

	for (int i = 0; i <= baserows - 1; i++) {
		for (int j = 0; j <= basecols - 1; j++) {
			int k = i * basecols + j;
			baseimagear.push_back(matrixobj->basereturndata[k]);		//push data to vector for base
		}
	}

	for (int i = 0; i <= wallyrows - 1; i++) {
		for (int j = 0; j <= wallycols - 1; j++) {
			int k = i * wallycols + j;
			wallyar.push_back(matrixobj->wallyreturndata[k]);			//push data to vector for wally
		}
	}

	delete matrixobj;	//delete obj to free memory

	cout << "RUNNING: Execution usually takes 45 seconds - 1 minute. Please wait..." << endl;

	thread load(loading);												//calls loading animation as a new thread

	double resultarry[5] = {};	//initialize an array to store result of NNS
	int comparisons = 0;		
	NNS* Searcherobj = new NNS; //create new instance of NNS class

	for (int i = 0; i <= baserows - wallyrows; i++) {
		for (int j = 0; j <= basecols - wallycols; j++) {

			for (int a = 0; a <= wallyrows - 1; a++) {
				for (int b = 0; b <= wallycols - 1; b++) {		//moving window search area

					Searcherobj->tempmatrix.push_back(baseimagear[((i + a) * basecols + (j + b))]); //generate a temporary image with the same size as wally for comparison

				}
			}
			double tempans = Searcherobj->CalcSSD(wallyar, Searcherobj->tempmatrix, wallycols, wallyrows);		//perform SSD by comparing the extracted matrix to wally's matrix
			//comparisons++;
			//cout << tempans << "\t \t \t" << comparisons << "\n";
			if (tempans < resultarry[0] || i == 0 && j == 0) {			//identify the nearest result and output result and location to an array
				resultarry[0] = tempans;
				resultarry[1] = i;
				resultarry[2] = j;		//store in array
			}
			Searcherobj->tempmatrix.clear();		//clear array ready for next iteration
		};
	};
	cout << resultarry[0] << resultarry[1] << resultarry[2] << "\n";		//print result to console

	delete Searcherobj;		//delete obj to free memory

	load.detach();		//stops loading animation

	unsigned char temp[1764];		//the size is the sum of the columns and rows
	Base_Image* baseimgobj = new Base_Image;		//create new instance of base image class

	int q = resultarry[1]; //SHOULD BE 144 for wally
	int w = resultarry[2]; //SHOULD BE 162 for wally
	int c = 0;

	for (int e = 0; e <= baserows - 1; e++) {
		for (int f = 0; f <= basecols - 1; f++) {	//iterate one last time to produce an image with wally highlighted

			int k = e * basecols + f;
			baseimgobj->highlightedscene[k] = baseimagear[k];

			if (e >= q && f >= w && e < q + wallyrows && f < w + wallycols && (f % 2 == 0 || e % 2 == 0)) { //highlights the region where wally is located
				baseimgobj->highlightedscene[k] = 0;
			}

		}
	}
	char name2[21] = "highlightedscene.pgm";
	char * namept2 = name2;
	double * data2 = baseimgobj->highlightedscene;

	write_pgm(namept2, data2, baserows, basecols, 255);		//outputs the highlighted file

	delete baseimgobj;	//deletes obj to free up memory

	cout << "\n\n" << endl;
	cout << "Execution complete, Wally Found Successful \n" << endl;	
	cout << "Wally can be seen in the file highlightedscene.pgm \n" << endl;
	cout << "The file is located with the source files. \n\n" << endl;	//complete
}