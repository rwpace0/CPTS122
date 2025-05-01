/*
Name: Reid Pace
Class: 122
Assignment: PA8
Date: April 8th, 2025
Lab Section: 10
Description: DataAnalysis header file for function declarations
*/
#ifndef DATA_ANALYSIS_H
#define DATA_ANALYSIS_H
#include "BST.hpp"

class DataAnalysis {
public:

	//constructor, destructor
	DataAnalysis();
	~DataAnalysis();
	
	//run the app
	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	//opens the data.csv and skips the header line for reading
	bool openCSV(const string& filename);
	//returns true when all lines are read and stored and false otherwise
	bool readLine(string& units, string& type, string& transaction);
	//inserts all products in order and displays them
	void insertAll();
	//inserts and categorizes all elements into the tree
	void insertTree(const string& type, int units, const string& transaction);
	//displays all of the least and most sold and purchased prducts
	void displayTrends() const;
};

#endif