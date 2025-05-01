/*
Name: Reid Pace
Class: 122
Assignment: PA8
Date: April 8th, 2025
Lab Section: 10
Description: Node header file for function declarations
*/
#ifndef NODE_H
#define NODE_H
#include "include.hpp"

class Node {
public:

	//constructor, destructor
	Node(const string& data);
	virtual ~Node();

	//setters
	void setData(const string& data);
	void setLeft(Node *newLeft);
	void setRight(Node* newRight);

	//getters
	string getData() const;
	Node*& getLeft();
	Node*& getRight();

	//parent printing functions
	virtual void printData() const = 0;

	private:
	string mData;
	Node* mpLeft;
	Node* mpRight;
};
#endif