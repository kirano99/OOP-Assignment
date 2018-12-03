// RobotClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Robots.h"

using namespace std;


int main(int argc, char* argv[])
{
	Robot *r = new Robot();
	SocialRobot *sR = new SocialRobot("Sam");
	IndustrialRobot *iR = new IndustrialRobot("Isacc");

	cout << sR->getName;
	cout << iR->getName;

	delete r, sR, iR;

	cout << endl;
	system("pause");

	return 0;
}
