/*
Name: Reid Pace
Class: 122
Assignment: PA5
Date: March 3rd, 2025
Lab Section: 10
Description: Data function definitions
*/
#include "Data.hpp"

Data::~Data(){}

Data::Data() : customerNumber(0), serviceTime(0), totalTime(0) {}

Data::Data(int cNum, int sTime, int tTime) : customerNumber(cNum), serviceTime(sTime), totalTime(tTime){}

int Data::getCustomer() {
	return customerNumber;
}

int Data::getService() {
	return serviceTime;
}

int Data::getTotal() {

	return totalTime;
}

void Data::setCustomer(int newNum) {
	customerNumber = newNum;
}

void Data::setService(int newService) {
	serviceTime = newService;
}

void Data::setTotal(int newTotal) {
	totalTime = newTotal;
}
