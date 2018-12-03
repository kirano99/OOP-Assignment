#pragma once
#include <iostream>
#include <string>
using namespace std;

class Robot
{
public:
	string robotName;
private:
	
};

class SocialRobot : public Robot
{
public:
	SocialRobot(string name);

	string getName() {
		return robotName;
	}
	void setName(string input) {
		robotName = input;
	}

private:

};

class IndustrialRobot : public Robot
{
public:
	string getName() {
		return robotName;
	}

	void setName(string input) {
		robotName = input;
	}
private:

};