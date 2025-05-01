/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: QueueNode class and function declarations
*/
//guard
#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

#include "include.hpp"
#include "Data.hpp"

class QueueNode
{
public: // Member functions
	// destructor
	~QueueNode();
	//constructor
	QueueNode();
	//constructor for Data member
	QueueNode(Data* newData);
	// constructor for Data member and next member
	QueueNode(Data* newData, QueueNode* newNext);
	// getter for pData
	Data* getData();
	// getter for pNext
	QueueNode* getNext();
	// setter for pData
	void setData(Data* newData);
	// setter for pNext
	void setNext(QueueNode* pNext);

private:
	Data* pData; // The memory for Data will need to be allocated on the heap as well!
	QueueNode* pNext;
};
#endif