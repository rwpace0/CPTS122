/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: main file for program execution
*/
#include "Test.hpp"

int main() {

	Test test;
	//cout << "Text Functions:\n" << endl;
	//test.enqueueEmpty();
	//test.enqueueOne();
	//test.dequeueOne();
	//test.dequeueTwo();
	//test.runTest();

	int chosenTime = 0;
	cout << "Enter the number of minutes the simulation will run for: " << endl;
	cin >> chosenTime;

	test.runApp(chosenTime);

	return 0;
}