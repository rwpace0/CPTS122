/*
Name: Reid Pace
Class: 122
Assignment: PA8
Date: April 8th, 2025
Lab Section: 10
Description: BST source file for function definitions
*/
#include "BST.hpp"

BST::BST() {
    mpRoot = nullptr;
}

BST::~BST() {
    destroyTree(mpRoot);
}

void BST::setRoot(Node* pRoot) {
    mpRoot = pRoot;
}

Node* BST::getRoot() const {
    return mpRoot;
}

void BST::destroyTree(Node*& pNode)
{
    if (pNode != nullptr) {
        destroyTree(pNode->getLeft());
        destroyTree(pNode->getRight());

        delete pNode;
        pNode = nullptr;
    }
}

//public
void BST::insert(const string& data, int units) {
    insert(mpRoot, data, units);
}

//helper
void BST::insert(Node*& pNode, const string& data, int units) {
    if (pNode == nullptr) {
        pNode = new TransactionNode(data, units);
        return;
    }
    TransactionNode* pTNode = dynamic_cast<TransactionNode*>(pNode);

    if (pTNode == nullptr) {
        cout << "PTNode error" << endl;
        return;
    }
    if (units < pTNode->getUnits()) {
        insert(pNode->getLeft(), data, units);
    }
    else {
        insert(pNode->getRight(), data, units);
    }

}

//public
void BST::inOrderTraversal() const
{
    if (mpRoot == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    cout << "Tree contents (in order):" << endl;
    inOrderTraversal(mpRoot);
}

//helper
void BST::inOrderTraversal(Node* pNode) const
{
    if (pNode != nullptr){

        inOrderTraversal(pNode->getLeft());

        pNode->printData();
                
        inOrderTraversal(pNode->getRight());
    }
}

TransactionNode& BST::findSmallest() const {

    if (mpRoot == nullptr) {
        cout << "Tree is empty." << endl;
    }
    Node* pCur = mpRoot;

    // pCur to left most node
    while (pCur->getLeft() != nullptr) {
        pCur = pCur->getLeft();
    }
    TransactionNode* pTNode = dynamic_cast<TransactionNode*>(pCur);

    if (pTNode == nullptr)
    {
        cout << "Node is not a TransactionNode" << endl;
    }

    return *pTNode;

}

TransactionNode& BST::findLargest() const {

    if (mpRoot == nullptr) {
        cout << "Tree is empty." << endl;
    }
    Node* pCur = mpRoot;

    // pCur to left most node
    while (pCur->getRight() != nullptr) {
        pCur = pCur->getRight();
    }
    TransactionNode* pTNode = dynamic_cast<TransactionNode*>(pCur);

    if (pTNode == nullptr)
    {
        cout << "Node is not a TransactionNode" << endl;
    }

    return *pTNode;

}