/*
Name: Reid Pace
Class: 122
Assignment: PA6
Date: March 20th, 2025
Lab Section: 10
Description: main file for program execution
*/
#include "include.hpp"
#include "BST.hpp"

using std::cout;
using std::endl;
using std::fstream;

int main() {
	BST tree;
	fstream convertF;
	cout << "Tree:" << endl;
	tree.displayBST();
	cout << endl;
	convertF.open("Convert.txt");
	if (convertF.is_open()) {
		while (!convertF.eof()) {
			string line;
			getline(convertF, line);
			for (int i = 0; i < line.length(); i++) {
				char target = toupper(line.at(i));
				cout << tree.search(target) << " ";
			}
			cout << endl;
		}
		convertF.close();
	}
	else {
		cout << "Convert.txt open fail." << endl;
	}
	
	return 0;
}