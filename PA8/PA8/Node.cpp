/*
Name: Reid Pace
Class: 122
Assignment: PA8
Date: April 8th, 2025
Lab Section: 10
Description: Node source file for function definitions
*/
#include "Node.hpp"

Node::Node(const string& data) {
	mData = data;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node() {}

void Node::setData(const string& data) {
	mData = data;
}

void Node::setLeft(Node* newLeft) {
	mpLeft = newLeft;
}

void Node::setRight(Node* newRight)
{
	mpRight = newRight;
}

// Getter implementations
std::string Node::getData() const
{
	return mData;
}

Node*& Node::getLeft()
{
	return mpLeft;
}

Node*& Node::getRight()
{
	return mpRight;
}