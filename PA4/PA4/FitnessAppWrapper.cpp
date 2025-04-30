/*
Name: Reid Pace
Class: 122
Assignment: PA4
Date: February 23rd, 2025
Lab Section: 10
Description: FitnessAppWrapper class definitions.
*/

#include "FitnessAppWrapper.hpp"

//constructor
FitnessAppWrapper::FitnessAppWrapper() {
}

//destructor
FitnessAppWrapper::~FitnessAppWrapper() {
}

void FitnessAppWrapper::runApp() {
	
	fstream dietFile, exerciseFile;
	DietPlan dietPlanArr[7] = {};
	ExercisePlan exercisePlanArr[7] = {};
	int choice = 0;
	bool run = true;
	int planNum = 0;
	
	while (run) {
		system("cls");
		displayMenu();
		choice = getChoice();
		switch (choice) {
		case 1: // Load weekly diet plan from file.
			system("cls");
			dietFile.open("dietPlans.txt");
			loadWeeklyPlan(dietFile, dietPlanArr);
			cout << "Weekly diet plan loaded." << endl;
			dietFile.close();
			system("pause");
			break;
		case 2: // Load weekly exercise plan from file.
			system("cls");
			exerciseFile.open("exercisePlans.txt");
			loadWeeklyPlan(exerciseFile, exercisePlanArr);
			cout << "Weekly exercise plan loaded." << endl;
			exerciseFile.close();
			system("pause");
			break;
		case 3: // Store weekly diet plan to file.
			system("cls");
			dietFile.open("dietPlans.txt");
			storeWeeklyPlan(dietFile, dietPlanArr);
			cout << "Weekly diet plan stored to file." << endl;
			dietFile.close();
			system("pause");
			break;
		case 4: // Store weekly exercise plan to file.
			system("cls");
			exerciseFile.open("exercisePlans.txt");
			storeWeeklyPlan(exerciseFile, exercisePlanArr);
			cout << "Weekly exercise plan stored to file." << endl;
			exerciseFile.close();
			system("pause");
			break;
		case 5: // Display weekly diet plan to screen.
			system("cls");
			displayWeeklyPlan(dietPlanArr);
			system("pause");
			break;
		case 6: // Display weekly exercise plan to screen.
			system("cls");
			displayWeeklyPlan(exercisePlanArr);
			system("pause");
			break;
		case 7: // Edit daily diet plan.
			system("cls");
			planNum = chooseGoal(dietPlanArr);
			dietPlanArr[planNum].editGoal();
			displayDailyPlan(dietPlanArr[planNum]);
			system("pause");
			break;
		case 8: // Edit daily exercise plan.
			system("cls");
			planNum = chooseGoal(exercisePlanArr);
			exercisePlanArr[planNum].editGoal();
			displayDailyPlan(exercisePlanArr[planNum]);
			system("pause");
			break;
		case 9: // Exit.
			dietFile.open("dietPlans.txt");
			storeWeeklyPlan(dietFile, dietPlanArr);
			cout << "\nWeekly diet plan stored to file." << endl;
			dietFile.close();
			exerciseFile.open("exercisePlans.txt");
			storeWeeklyPlan(exerciseFile, exercisePlanArr);
			cout << "\nWeekly exercise plan stored to file." << endl;
			exerciseFile.close();
			
			run = false;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
		
	}

}

void FitnessAppWrapper::displayMenu() {
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit.\n" << endl;
}

int FitnessAppWrapper::getChoice() {
	int choice = 0;
	cin >> choice;
	return choice;
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan& plan) {
	cout << plan << endl;
}
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan) {
	cout << plan << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": \n";
		displayDailyPlan(weeklyPlan[i]);
	}
}
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": ";
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream& outfile, DietPlan& plan) {
	outfile << plan;
}
void FitnessAppWrapper::storeDailyPlan(fstream& outfile, ExercisePlan& plan) {
	outfile << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream& outfile, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(outfile, weeklyPlan[i]);
	}
}
void FitnessAppWrapper::storeWeeklyPlan(fstream& outfile, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(outfile, weeklyPlan[i]);
	}
}

int FitnessAppWrapper::chooseGoal(DietPlan weeklyPlan[]) {
	bool run = true;
	int choice = 0;

	while (run) {
		system("cls");
		displayWeeklyPlan(weeklyPlan);
		cout << "What plan would you lke to edit? ";
		cin >> choice;
		if (choice > 0 && choice < 8) {
			run = false;
		}
	}
	return choice - 1; // array pos
}

int FitnessAppWrapper::chooseGoal(ExercisePlan weeklyPlan[]) {
	bool run = true;
	int choice = 0;

	while (run) {
		system("cls");
		displayWeeklyPlan(weeklyPlan);
		cout << "What plan would you lke to edit? ";
		cin >> choice;
		if (choice > 0 && choice < 8) {
			run = false;
		}
	}
	return choice - 1; // array pos
}