/*
Name: Reid Pace
Class: 122
Assignment: PA4
Date: February 23rd, 2025
Lab Section: 10
Description: ExercisePlan class function declarations
*/

#pragma once
#include "include.hpp"

class ExercisePlan {
public:
	// constructor
	ExercisePlan();

	// destructor
	~ExercisePlan();

	// constructor with parameters
	ExercisePlan(int newSteps, string newName, string newDate);

	// copy constructior
	ExercisePlan(ExercisePlan& copyExercise);
	
	// gets goal from accessor
	int getSteps() const;

	// gets name from accessor
	string getName() const;

	// gets date from accessor
	string getDate() const;

	// set goal from mutator
	void setSteps(int newSteps);

	// set name from mutator
	void setName(string newName);

	// set date from mutator
	void setDate(string newDate);

	// asks for new goal to be edited, uses member mutator to set new goal
	void editGoal();


private:
	int steps;
	string name,
		date;
};

//overloaded file stream insertion to write to DietPlan in file
// returns new lhs
ostream& operator<<(ostream& lhs,  ExercisePlan& rhs);

//overloaded file stream extraction to write to DietPlan in console
// returns new lhs
fstream& operator<<(fstream& lhs,  ExercisePlan& rhs);

//overloaded file stream extraction to read DietPlan
// returns new lhs
fstream& operator>>(fstream& lhs,  ExercisePlan& rhs);