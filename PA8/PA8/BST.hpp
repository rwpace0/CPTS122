/*
Name: Reid Pace
Class: 122
Assignment: PA8
Date: April 8th, 2025
Lab Section: 10
Description: BST header file for function declarations
*/
#ifndef BST_H
#define BST_H
#include "TransactionNode.hpp"

class BST {
public:
    //constructor, destructor
    BST();
    ~BST();

    //root setter, getter
    void setRoot(Node* pRoot);
    Node* getRoot() const;

    //prints the inserted tree
    void insert(const string& data, int units);
    //traverses tree in decesnding order
    void inOrderTraversal() const;

    //goes to the left most node
    TransactionNode& findSmallest() const;
    // goes to the right most node
    TransactionNode& findLargest() const;
private:
	Node* mpRoot;
    //destroy tree called in destructor to delete the BST
	void destroyTree(Node*&pNode);
    //helper function that determines where to insert the new nodes
	void insert(Node*& pNode, const string & data, int units);
    //inserts data into bst by dyanmically casting
	void inOrderTraversal(Node* pNode) const;
};
#endif