/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: Test class and function declarations
*/
#include "Data.hpp"
#include "Queue.hpp"
#include "QueueNode.hpp"

class Test
{
public:
	// enqueue test on empty node
	void enqueueEmpty();
	//enque test on one node
	void enqueueOne();
	//dequeue test for one node
	void dequeueOne();
	//dequeue test for two nodes
	void dequeueTwo();
	//run the app for 24 hours using runApp()
	void runTest();
	//main logic for running the app
	//randomizes the arrival of each queue and wont stop until all customers are processed
	//relies on process(), enqueue(), displayQueue(), and customers data member
	void runApp(int chosenTime);

private: 
	
};