/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: Queue class and function declarations
*/
#include "include.hpp"
#include "QueueNode.hpp"

class Queue
{
public: // Member functions
	// default constructor
	Queue();
	//default destructor
	~Queue();

	// creates a new customer and adds to the queue
	// adds service time to total each customer
	void enqueue(int customers, int service);
	// deletes node from queue
	void dequeue();
	// displays the current queue: customer number, service time, total time
	void displayQueue();
	// unused function
	void time();
	// once the time is over for the customer it will display "processed" to the screen
	// relies on dequeue()
	void process();

	// get head pointer
	QueueNode* getHead();
	// get tail pointer
	QueueNode* getTail();
	// set head pointer
	void setHead(QueueNode* newHead);
	// set tail pointer
	void setTail(QueueNode* newTail);

private:
	QueueNode* pHead,
		* pTail;
};