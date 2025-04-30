/*
Name: Reid Pace
Class: 122
Assignment: PA4
Date: February 23rd, 2025
Lab Section: 10
Description: DietPlan class function definitions
*/

#include "DietPlan.hpp"

DietPlan::DietPlan(){
	cals = 0;
	name = "";
	date = "";
}

DietPlan::DietPlan(int newCals, string newName,
	string newDate)
{
	name = newName;
	cals = newCals;
	date = newDate;

}

DietPlan::DietPlan(DietPlan& copyDiet) {
	name = copyDiet.getName();
	cals = copyDiet.getCals();
	date = copyDiet.getDate();
}

DietPlan::~DietPlan() {

}

int DietPlan::getCals () const {
	return cals;
}

string DietPlan::getName() const {
	return name;
}

string DietPlan::getDate() const {
	return date;
}

void DietPlan::setCals(int newCals) {
	cals = newCals;
}

void DietPlan::setName(string newName) {
	name = newName;
}

void DietPlan::setDate(string newDate) {
	date = newDate;
}

void DietPlan::editGoal() {
	system("cls");
	int newGoal = 0;
	cout << "Enter new calorie goal: ";
	cin >> newGoal;
	setCals(newGoal);
}

ostream& operator<<(ostream& lhs, DietPlan& rhs) {
	lhs << "Name: " << rhs.getName() << "\nCalories: " << rhs.getCals() << "\nDate: " << rhs.getDate() << "\n";

	return lhs;
}

fstream& operator<< (fstream& lhs, DietPlan& rhs) {
	lhs << rhs.getName() << endl;
	lhs << rhs.getCals() << endl;
	lhs << rhs.getDate() << endl;
	lhs << "\n";
	return lhs;
}

fstream& operator>>(fstream& lhs, DietPlan& rhs) {

	int cals = 0;
	string name, date, sCals, newLine;

	getline(lhs, name);
	getline(lhs, sCals);
	cals = stoi(sCals);
	getline(lhs, date);
	getline(lhs, newLine);
	rhs.setName(name);
	rhs.setCals(cals);
	rhs.setDate(date);

	return lhs;
}
