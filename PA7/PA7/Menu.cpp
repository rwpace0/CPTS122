#include "Menu.hpp"

Menu::Menu() {

}

/*
Name: Reid Pace
Class: 122
Assignment: PA7
Date: March 29th, 2025
Lab Section: 10
Description: file for menu class definitions
*/

void Menu::run() {
	int choice = 0;

	do {
		displayMainMenu();
		cout << "\nEnter your choice: ";
		cin >> choice;
		cin.ignore(); // clear input buffer
		cout << endl;
		switch (choice) {
		case 1:
			importCourseList();
			
			break;
		case 2:
			loadMasterList();
			break;
		case 3:
			storeMasterList();
			break;
		case 4:
			markAbsences();
			break;
		case 5:
			editAbsences();
			break;
		case 6:
			generateReport();
			break;
		case 7:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
			break;
		}
		
		cout << endl;
		system("pause");
		system("cls");
	} while (choice != 7);
}

void Menu::displayMainMenu() const {
	cout << "=== Attendance Tracker Menu ===" << endl;
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Edit absences" << endl;
	cout << "6. Generate report" << endl;
	cout << "7. Exit" << endl;
}

void Menu::displayReportMenu() const {
	cout << "=== Report Options ===" << endl;
	cout << "1. Generate report for all students" << endl;
	cout << "2. Generate report for students with too many absences" << endl;
	cout << "3. Return to main menu\n" << endl;

}

string Menu::getCurrentDate() const {
	time_t t = time(0);
	struct tm* now = localtime(&t);

	stringstream ss;
	//altered time struct to make sure the date would print
	ss << (now->tm_year + 1900) << '-'
		<< setw(2) << setfill('0') << (now->tm_mon + 1) << '-'
		<< setw(2) << setfill('0') << now->tm_mday;

	return ss.str();
}

void Menu::importCourseList() {
	if (masterList.importFile("classList.csv")) {
		cout << "Course list imported successfully!" << endl;
	}
	else {
		cout << "Failed to import course list." << endl;
	}
}

void Menu::loadMasterList() {
	if (masterList.importFile("master.csv")) {
		cout << "Master list imported successfully!" << endl;
	}
	else {
		cout << "Failed to load Master List." << endl;
	}
}

void Menu::storeMasterList() {
	if (masterList.saveFile("master.csv")) {
		cout << "Master list saved successfully!" << endl;
	}
	else {
		cout << "Failed to save Master List." << endl;
	}
}

void Menu::markAbsences() {
	if (masterList.isEmpty()) {
		cout << "The master list is empty. Please import a course list first." << endl;
	}
	string currentDate = getCurrentDate();
	cout << "Marking absences for date: " << currentDate << endl;

	Node<Data>* current = masterList.getHead();
	char answer;

	while (current != nullptr) {
		Data& studentData = current->getData();
		cout << "Is " << studentData.getName() << " absent? (y/n): ";
		cin >> answer;
		cin.ignore();

		if (answer == 'y' || answer == 'Y') {
			studentData.addAbsence(currentDate);
			cout << "Marked as absent." << endl;
		}
		current = current->getNext();
	}
	cout << "Absence marking completed for all students." << endl;
}
//bonus
void Menu::editAbsences() {
	if (masterList.isEmpty()) {
		cout << "The master list is empty. Please import a course list first." << endl;
		return;
	}

	cout << "How would you like to search for a student?" << endl;
	cout << "1. By ID number" << endl;
	cout << "2. By name" << endl;
	cout << "Enter your choice: ";

	int choice;
	cin >> choice;
	cin.ignore(); 

	Node<Data>* studentNode = nullptr;

	if (choice == 1) {
		int id;
		cout << "Enter student ID: ";
		cin >> id;
		cin.ignore();

		studentNode = masterList.findByID(id);
	}
	else if (choice == 2) {
		string name;
		cout << "Enter student name (last, first): ";
		getline(cin, name);

		studentNode = masterList.findByName(name);
	}
	else {
		cout << "Invalid choice." << endl;
		return;
	}

	if (studentNode == nullptr) {
		cout << "Student not found." << endl;
		return;
	}

	Data& studentData = studentNode->getData();
	cout << "Found student: " << studentData.getName() << endl;
	cout << "Absence count: " << studentData.getAbsenceCount() << endl;

	if (studentData.getAbsenceCount() == 0) {
		cout << "This student has no absences to edit." << endl;
		return;
	}

	cout << "Enter the date of absence to edit (YYYY-MM-DD): ";
	string date;
	getline(cin, date);

	if (!studentData.dateOfAbsence(date)) {
		cout << "No absence record found for this date." << endl;
		return;
	}

	cout << "Student was marked absent on " << date << ". Remove this absence? (y/n): ";
	char answer;
	cin >> answer;

	if (answer == 'y' || answer == 'Y') {
		studentData.removeAbsence(date);
		cout << "Absence record removed." << endl;
	}
	else {
		cout << "No changes made." << endl;
	}
}

void Menu::generateReport() {
	if (masterList.isEmpty()) {
		cout << "The master list is empty. Please import a course list first." << endl;
		return;
	}
	int choice = 0;
	do {
		displayReportMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			generateAllStudentsReport();
			break;
		case 2:
			generateThresholdReport();
			break;
		case 3:
			cout << "Returning to main menu." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
			break;
		}
		 
	} while (choice != 3);
}

void Menu::generateAllStudentsReport() {
	ofstream reportFile("all_students_report.txt");
	if (!reportFile.is_open()) {
		cout << "Failed to create report file." << endl;
		return;
	}
	reportFile << "=== All Students Attendance Report ===" << endl;
	reportFile << "Date: " << getCurrentDate() << endl << endl;
	reportFile << left
		<< setw(30) << "Name" //setw sets a max char of 30
		<< setw(10) << "ID"
		<< setw(10) << "Absences"
		<< "Most Recent Absence" << endl;
	reportFile << string(70, '-') << endl;

	Node<Data>* current = masterList.getHead();
	while (current != nullptr) {
		const Data& studentData = current->getData();

		reportFile << left
			<< setw(30) << studentData.getName()
			<< setw(10) << studentData.getIdNumber()
			<< setw(10) << studentData.getAbsenceCount()
			<< studentData.getMostRecentAbsenceDate() << endl;

		current = current->getNext();
	}

	reportFile.close();
	cout << "Report generated successfully." << endl;
}

void Menu::generateThresholdReport() {
	int threshold;
	cout << "Enter absence threshold: ";
	cin >> threshold;
	cin.ignore(); 

	ofstream reportFile("threshold_report.txt");
	if (!reportFile.is_open()) {
		cout << "Failed to create report file." << endl;
		return;
	}

	reportFile << "=== Students with " << threshold << " or More Absences ===" << endl;
	reportFile << "Date: " << getCurrentDate() << endl << endl;
	reportFile << left
		<< setw(30) << "Name"
		<< setw(10) << "ID"
		<< "Absences" << endl;
	reportFile << string(50, '-') << endl;

	Node<Data>* current = masterList.getHead();
	int matchCount = 0;

	while (current != nullptr) {
		const Data& studentData = current->getData();

		if (studentData.getAbsenceCount() >= threshold) {
			reportFile << left
				<< setw(30) << studentData.getName()
				<< setw(10) << studentData.getIdNumber()
				<< studentData.getAbsenceCount() << endl;
			matchCount++;
		}

		current = current->getNext();
	}

	if (matchCount == 0) {
		reportFile << "No students found with " << threshold << " or more absences." << endl;
	}

	reportFile.close();
	cout << "Report generated successfully." << endl;
}