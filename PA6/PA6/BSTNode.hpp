/*
Name: Reid Pace
Class: 122
Assignment: PA6
Date: March 20th, 2025
Lab Section: 10
Description: BSTNode class declarations
*/
#pragma once
#include "include.hpp"
using std::string;

class BSTNode {
public:
	//default constructor
	BSTNode() : english('\0'), morse(""), left(nullptr), right(nullptr) {}
	//constructor null values
	BSTNode(char eng1, string mor1) : english(eng1), morse(mor1), left(nullptr), right(nullptr) {}
	//constructor all values
	BSTNode(char eng1, string mor1, BSTNode *lef, BSTNode* rig) : english(eng1), morse(mor1), left(lef), right(rig) {}
	//destructor
	~BSTNode(){}
	//english character getter
	char getEnglish();
	//morse char getter
	string getMorse();
	//left pointer getter
	BSTNode* getLeft();
	//right pointer getter
	BSTNode* getRight();
	//english char setter
	void setEnglish(char newEng);
	//morse char setter
	void setMorse(string newMor);
	//left pointer setter
	void setLeft(BSTNode* newLeft);
	//right pointer setter
	void setRight(BSTNode* newRight);

private:
	char english;
	string morse;
	BSTNode* left;
	BSTNode* right;
};
