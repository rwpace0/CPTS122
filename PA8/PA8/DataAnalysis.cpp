/*
Name: Reid Pace
Class: 122
Assignment: PA8
Date: April 8th, 2025
Lab Section: 10
Description: DataAnalysis source file for function definition
*/
#include "DataAnalysis.hpp"

DataAnalysis::DataAnalysis() {

}

DataAnalysis::~DataAnalysis() {

	if (mCsvStream.is_open()) {
		mCsvStream.close();
	}

}

bool DataAnalysis::openCSV(const string& filename) {
	
	mCsvStream.open(filename);

	if (!mCsvStream.is_open())
	{
		cout << "Error: Could not open file " << filename << endl;
		return false;
	}

	//skip first line
	string header;
	getline(mCsvStream, header);

}

bool DataAnalysis::readLine(string& units, string& type, string& transaction) {

	string line;

	if (!getline(mCsvStream, line) || line.empty()) return false;

	stringstream ss(line);

	//store all
	getline(ss, units, ',');
	getline(ss, type, ',');
	getline(ss, transaction, ',');

	return true;

}

void DataAnalysis::insertTree(const string& type, int units, const string& transaction) {

	if (transaction == "Sold") mTreeSold.insert(type, units);
	else if (transaction == "Purchased") mTreePurchased.insert(type, units);
	else cout << "Unkown transaction: " << transaction << endl;

}

void DataAnalysis::insertAll() {

	string units, type, transaction;

	while (readLine(units, type, transaction)) {
		
		int unitsVal = stoi(units);

		insertTree(type, unitsVal, transaction);
	}

	cout << "\n=== PRODUCTS SOLD ===\n";
	mTreeSold.inOrderTraversal();

	cout << "\n=== PRODUCTS PURCHASED ===\n";
	mTreePurchased.inOrderTraversal();

}

void DataAnalysis::displayTrends() const {

	cout << "\n=== TREND ANALYSIS ===\n";

	//sold
	const TransactionNode& leastSold = mTreeSold.findSmallest();
	const TransactionNode& mostSold = mTreeSold.findLargest();

	//purchased
	const TransactionNode& leastPurchased = mTreePurchased.findSmallest();
	const TransactionNode& mostPurchased = mTreePurchased.findLargest();

	cout << "Most Sold: " << mostSold.getData() << " with " << mostSold.getUnits() << " units.\n";
	cout << "Least Sold: " << leastSold.getData() << " with " << leastSold.getUnits() << " units.\n";
	cout << "Most Purchased: " << mostPurchased.getData() << " with " << mostPurchased.getUnits() << " units.\n";
	cout << "Least Purchased: " << leastPurchased.getData() << " with " << leastPurchased.getUnits() << " units.\n";
}

void DataAnalysis::runAnalysis()
{

	if (openCSV("data.csv"))
	{
		insertAll();
		displayTrends();
	}
	else cout << "Analysis failed: File error" << endl;
}