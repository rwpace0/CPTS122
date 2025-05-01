/*
Name: Reid Pace
Class: 122
Assignment: PA8
Date: April 8th, 2025
Lab Section: 10
Description: TransactionNode header file for function declarations
*/
#include "TransactionNode.hpp"

TransactionNode::TransactionNode(const string& data, int units) : Node(data) {
	mUnits = units;
}

TransactionNode::~TransactionNode(){}

void TransactionNode::setUnits(int units){
	mUnits = units;
}

int TransactionNode::getUnits() const{
	return mUnits;
}

void TransactionNode::printData() const {
	cout << "Product: " << getData() << ", Units: " << mUnits << endl;
}