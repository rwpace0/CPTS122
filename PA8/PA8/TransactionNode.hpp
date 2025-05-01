/*
Name: Reid Pace
Class: 122
Assignment: PA8
Date: April 8th, 2025
Lab Section: 10
Description: Transaction Node header file for function declaration
*/
#ifndef TRANSACTIONNODE_H
#define TRANSACTIONNODE_H
#include "Node.hpp"


class TransactionNode : public Node {
public:

	//constructor, destructor
	TransactionNode(const string& data, int units);
	~TransactionNode();

	//setter getter
	void setUnits(int units);
	int getUnits() const;

	//inheritance function from node to print units
	virtual void printData() const override;

private:
	int mUnits;
};

#endif