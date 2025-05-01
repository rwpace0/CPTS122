/*
Name: Reid Pace
Class: 122
Assignment: PA6
Date: March 20th, 2025
Lab Section: 10
Description: BST class definitions
*/
#include "include.hpp"
#include "BST.hpp"

using std::fstream;
using std::cout;

// public
BST::BST(){
	
	fstream morseTable;
	morseTable.open("MorseTable.txt");
	if (morseTable.is_open()) {
		char rootEng;
		morseTable >> rootEng;
		string rootMor;
		morseTable >> rootMor;
		BSTNode* root = new BSTNode(rootEng, rootMor);
		insert(rootEng, rootMor);
		setRoot(root);
		while (!morseTable.eof()) {
			morseTable >> rootEng;
			morseTable >> rootMor;
			insert(rootEng, rootMor);
		}
	}
	morseTable.close();
}

BSTNode* BST::getRoot() {
	return root;
}

void BST::setRoot(BSTNode* newRoot) {
	root = newRoot;
}

void BST::insert(char english, string morse) {
	insertHelp(this->root, english, morse);
}

void BST::insertHelp(BSTNode* node, char english, string morse) {
	if (node == nullptr) {
		 BSTNode* newNode = new BSTNode(english, morse);
	}
	else {
		if (english < node->getEnglish()) {
			if (node->getLeft() != nullptr) {
				insertHelp(node->getLeft(), english, morse);
			}
			else {
				BSTNode* temp = new BSTNode(english, morse);
				node->setLeft(temp);
			}
		}
		else if (english > node->getEnglish()) {
			if (node->getRight() != nullptr) {
				insertHelp(node->getRight(), english, morse);
			}
			else {
				BSTNode* temp = new BSTNode(english, morse);
				node->setRight(temp);
			}
		}
		else {}
	}
}

void BST::displayBST() {
	inOrderTraversal(this->root);
}

void BST::inOrderTraversal(BSTNode* node) {
	if (node != nullptr) {
		inOrderTraversal(node->getLeft());
		cout << node->getEnglish() << " ";
		inOrderTraversal(node->getRight());
	}

}

string BST::search(char& target) {
	string morse = search(this->root, target);
	return morse;
}

//private


string BST::search(BSTNode* n, char& target) {
	// spaces
	if (target == ' ') return " ";
	//base
	if (n->getEnglish() == target) return n->getMorse();
	else if (target < n->getEnglish()) return search(n->getLeft(), target);
	else if (target > n->getEnglish()) return search(n->getRight(), target);
	
}

void BST::destroy(BSTNode* node) {
	if (node != nullptr) {
		destroy(node->getLeft());
		destroy(node->getRight());
		delete node;
	}
}