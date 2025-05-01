/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: QueueNode function definitions
*/
#include "QueueNode.hpp"

QueueNode::~QueueNode() {
	delete pData;
}

QueueNode::QueueNode() : pData(nullptr), pNext(nullptr) {}

QueueNode::QueueNode(Data* newData) : pData(newData), pNext(nullptr) {}

QueueNode::QueueNode(Data* newData, QueueNode* newNext) : pData(newData), pNext(newNext){}

Data* QueueNode::getData() {
	return pData;
}

QueueNode* QueueNode::getNext() {
	return pNext;
}

void QueueNode::setData(Data* newData) {
	pData = newData;
}

void QueueNode::setNext(QueueNode* newNext) {
	pNext = newNext;
}