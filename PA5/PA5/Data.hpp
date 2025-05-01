/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: Data class and function declarations
*/
//guard
#ifndef DATA_HPP
#define DATA_HPP

#include "include.hpp"

class Data
{
public: // Member functions
	// destructor
	~Data();
	// default constructor 
	Data();
	// constructor with private init
	Data(int cNum, int sTime, int tTime);
	// getter for customerNumber
	int getCustomer();
	// getter for serviceTime
	int getService();
	// getter for totalTime
	int getTotal();
	// setter for customerNumber
	void setCustomer(int newNum);
	// setter for serviceTime
	void setService(int newService);
	// setter for totalTime
	void setTotal(int newTotal);

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; // Random time; varies between express and normal lanes; units in
	// minutes
	int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line
	// before this customer; units in minutes
}; // This memory needs to be allocated on the heap!
#endif