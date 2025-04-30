/*
Name: Reid Pace
Class: 122
Assignment: PA4
Date: February 23rd, 2025
Lab Section: 10
Description: DietPlan class function declarations
*/

#pragma once
#include "include.hpp"

class DietPlan {
public:
	// constructor
	DietPlan();

	// destructor
	~DietPlan();

	// constructor with parameters
	DietPlan(int newCals, string newName, string newDate);

	// copy constructor
	DietPlan(DietPlan& copyDiet);
	
	// gets goal from accessor
	int getCals() const;

	// gets name from accessor
	string getName() const;

	// gets date from accessor
	string getDate() const;

	// set goal from mutator
	void setCals(int newCals);

	// set name from mutator
	void setName(string newName);

	// set date from mutator
	void setDate(string newDate);

	// asks for new goal to be edited, uses member mutator to set new goal
	void editGoal();

private:
	int cals;
	string name,
		date;
};

//overloaded file stream insertion to write to DietPlan in file
// returns new lhs
ostream& operator<<(ostream& lhs, DietPlan& rhs);

//overloaded file stream extraction to write to DietPlan in console
// returns new lhs
fstream& operator<<(fstream& lhs, DietPlan& rhs);

//overloaded file stream extraction to read DietPlan
// returns new lhs
fstream& operator>>(fstream& lhs, DietPlan& rhs);