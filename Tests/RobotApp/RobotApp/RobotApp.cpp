// RobotApp.cpp : Defines the entry point for the console application.

#include "stdafx.h"
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
