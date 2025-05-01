/*
Name: Reid Pace
Class: 122
Assignment: PA6
Date: March 20th, 2025
Lab Section: 10
Description: BST class declarations
*/

#pragma once

#include "BSTNode.hpp"


class BST {
public:
	//default constructor
	BST();
	//destructor calls destroy root
	~BST() { destroy(root); }
	//root getter
	BSTNode* getRoot();
	//root setter
	void setRoot(BSTNode* newRoot);
	//calls insert helper function to insert current root into the tree
	void insert(char english, string morse);
	//helper function to find where to insert the new node in the tree
	void insertHelp(BSTNode* node, char english, string morse);
	//uses inordertraversal to display the bst to the screen
	void displayBST();
	//traverses and displays the node
	void inOrderTraversal(BSTNode* node);
	//uses helper for morse lookup
	string search(char& target);
	//helper function that returns target value after finding
	string search(BSTNode* n, char& target);

private:
	BSTNode* root;

	//destroys tree
	void destroy(BSTNode* node);

};
