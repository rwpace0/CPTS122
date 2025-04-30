/*
Name: Reid Pace
Class: 122
Assignment: PA4
Date: February 23rd, 2025
Lab Section: 10
Description: FitnessAppWrapper class declarations.
*/

#include "include.hpp"
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

class FitnessAppWrapper {
public:

	// constructor
	FitnessAppWrapper();

	// destructor
	~FitnessAppWrapper();

	// handles program execution
	void runApp();

	// displays a menu to user
	void displayMenu();

	// loads individual plans from input files
	// stores into respective plan
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);

	// loads the entire plan from the input files
	// stores into an array for respective plans
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);

	// displays individual plan to user
	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);

	// displays entire plan to user
	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

	// stores individual plan to respective output 
	void storeDailyPlan(fstream &outfile, DietPlan &plan);
	void storeDailyPlan(fstream& outfile, ExercisePlan& plan);

	//stores entire plan to respective output
	void storeWeeklyPlan(fstream& outfile, DietPlan weeklyPlan[]);
	void storeWeeklyPlan(fstream& outfile, ExercisePlan weeklyPlan[]);

	// gets input from the user and returns the input
	int getChoice();

	// asks user what plan they want to edit and returns the number they input
	int chooseGoal(DietPlan weeklyPlan[]);
	int chooseGoal(ExercisePlan weeklyPlan[]);

};