/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: Queue function definitions
*/
#include "Queue.hpp"

Queue::Queue() : pHead(nullptr), pTail(nullptr){}

Queue::~Queue() {
	while (pHead != nullptr) {
		dequeue();
	}
}

void Queue::enqueue(int customers, int service) {
	int prevTotalTime = 0;
	if (pTail != nullptr) {
		Data* tailData = pTail->getData();// previous node data
		if (tailData != nullptr) {
			prevTotalTime = tailData->getTotal();// previous's total time
		}
	}

	int newTotalTime = prevTotalTime + service; // total time is updated with prev

	//create new customer
	Data* newCustomer = new Data(customers, service, newTotalTime);
	QueueNode* newNode = new QueueNode(newCustomer);

	if (pHead == nullptr) {// empty
		pHead = newNode;
		pTail = newNode;
	}
	else { // append
		pTail->setNext(newNode);
		pTail = newNode;
	}

}

// clear node
void Queue::dequeue() {
	if (pHead != nullptr) {
		QueueNode* temp = pHead;
		pHead = pHead->getNext();
		if (pHead == nullptr) {
			pTail = nullptr;
		}
		delete temp;
	}
	else {
		cout << "Queue empty" << endl;
	}
}

// data display
void Queue::displayQueue() {
	QueueNode* pCur = pHead;
	while (pCur != nullptr) {
		Data* temp = pCur->getData();
		cout << "Customer Number: " << temp->getCustomer() << endl;
		cout << "Service Time: " << temp->getService() << endl;
		cout << "Total Time: " << temp->getTotal() << endl;
		cout << "\n" << endl;
		pCur = pCur->getNext();
	}
}

// unused time increment function
void Queue::time() {
	QueueNode* pCur = pHead;
	while (pCur != nullptr) {
		int temp = pCur->getData()->getTotal(); 
		temp++;
		pCur->getData()->setTotal(temp); 
		pCur = pCur->getNext();
	}
}

void Queue::process() {
	if (pHead != nullptr) {
		int temp = pHead->getData()->getService();
		temp--;
		pHead->getData()->setService(temp);
		if (pHead->getData()->getService() == 0) { // dequeue when service time is done
			cout << "Customer Processed" << endl;
			dequeue();
		}
	}
}

QueueNode* Queue::getHead() {
	return pHead;
}

QueueNode* Queue::getTail() {
	return pTail;
}

void Queue::setHead(QueueNode* newHead) {
	pHead = newHead;
}

void Queue::setTail(QueueNode* newTail) {
	pTail = newTail;
}