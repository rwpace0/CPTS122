/*
Name: Reid Pace
Class: 122
Assignment: PA4
Date: February 23rd, 2025
Lab Section: 10
Description: ExercisePlan class function defintions
*/

#include "ExercisePlan.hpp"

ExercisePlan::ExercisePlan() {
	steps = 0;
	name = "";
	date = "";
}

ExercisePlan::ExercisePlan(int newSteps, string newName, 
	string newDate) 
{
	steps = newSteps;
	name = newName;
	date = newDate;

}

ExercisePlan::ExercisePlan(ExercisePlan& copyExercise) {
	steps = copyExercise.getSteps();
	name = copyExercise.getName();
	date = copyExercise.getDate();
}

ExercisePlan::~ExercisePlan() {

}

int ExercisePlan::getSteps() const {
	return steps;
}

string ExercisePlan::getName() const {
	return name;
}

string ExercisePlan::getDate() const {
	return date;
}

void ExercisePlan::setSteps(int newSteps) {
	steps = newSteps;
}

void ExercisePlan::setName(string newName) {
	name = newName;
}

void ExercisePlan::setDate(string newDate) {
	date = newDate;
}

void ExercisePlan::editGoal() {
	system("cls");
	int newGoal = 0;
	cout << "Enter new step goal: ";
	cin >> newGoal;
	setSteps(newGoal);
}

ostream& operator<<(ostream& lhs, ExercisePlan& rhs) {
	lhs << "Name: " << rhs.getName() << "\nSteps: " << rhs.getSteps() <<"\nDate: " << rhs.getDate() << "\n";

	return lhs;
}

fstream& operator<< (fstream& lhs, ExercisePlan& rhs) {
	lhs << rhs.getName() << endl;
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getDate() << endl;
	lhs << "\n";
	return lhs;
}

fstream& operator>>(fstream& lhs, ExercisePlan& rhs) {

	int steps = 0;
	string name, date, sSteps, newLine;

	getline(lhs, name);
	getline(lhs, sSteps);
	steps = stoi(sSteps);
	getline(lhs, date);
	getline(lhs, newLine);
	rhs.setName(name);
	rhs.setSteps(steps);
	rhs.setDate(date);

	return lhs;
	
}