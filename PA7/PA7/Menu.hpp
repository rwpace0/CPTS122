/*
Name: Reid Pace
Class: 122
Assignment: PA7
Date: March 29th, 2025
Lab Section: 10
Description: menu class header for function declaration
*/
#include "List.hpp"

class Menu {
public:
	Menu();
	void run();

private:
	List<Data> masterList;
	string getCurrentDate() const;
    void displayMainMenu() const;
    void displayReportMenu() const;
    void importCourseList();
    void loadMasterList();
    void storeMasterList();
    void markAbsences();
    void editAbsences(); // bonus
    void generateReport();
    void generateAllStudentsReport();
    void generateThresholdReport();
};