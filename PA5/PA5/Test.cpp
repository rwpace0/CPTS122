/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: Test function definitions
*/
#include "Test.hpp"

void Test::enqueueEmpty() {
	Queue test;
	test.enqueue(1, 10);
	test.displayQueue();
}

void Test::enqueueOne() {
	Queue test;
	test.enqueue(1, 10);
	test.enqueue(2, 20);
	test.displayQueue();
}

void Test::dequeueOne() {
	Queue test;
	test.enqueue(1, 10);
	test.dequeue();
	test.displayQueue();
}

void Test::dequeueTwo() {
	Queue test;
	test.enqueue(1, 10);
	test.enqueue(2, 20);
	test.dequeue();
	test.displayQueue();
}

void Test::runTest() {
	int chosenTime = (24 * 60); // 24 hrs
	runApp(chosenTime);
}

void Test::runApp(int chosenTime) {
	int totalTime = 0, expressTime = 0, normalTime = 0;
	Queue normal, express;

	srand(time(NULL));

	//arrival times
	expressTime = rand() % 5 + 1; 
	normalTime = rand() % 6 + 3;
	 int customers = 0;
	while (totalTime < chosenTime) {
		if (expressTime == 0) {
			int expressService = rand() % 5 + 1;
			customers++;
			express.enqueue(customers, expressService);
			cout << "Customer Entered Express Lane" << endl;
			express.displayQueue();
			expressTime = rand() % 5 + 1; // reset
		}
		if (normalTime == 0) {
			int normalService = rand() % 6 + 3;
			customers++;
			normal.enqueue(customers, normalService);
			cout << "Customer Entered Normal Lane" << endl;
			normal.displayQueue();
			normalTime = rand() % 6 + 3; // reset
		}
		
		normal.process();
		express.process();

		// display queues every 10 min
		if (totalTime!=0 && totalTime % 10 == 0) {
			cout << "Express:" << endl;
			express.displayQueue();
			cout << "Normal:" << endl;
			normal.displayQueue();
			
		}
		++totalTime;
		--expressTime;
		--normalTime;
		//normal.time();
		//express.time();
	}
	
}