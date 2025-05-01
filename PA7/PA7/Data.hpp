/*
Name: Reid Pace
Class: 122
Assignment: PA7
Date: March 29th, 2025
Lab Section: 10
Description: file for data class declaration
*/
#include "include.hpp"

class Data {
public:
	//constructor
	Data();
	//constructor value init
	Data(int record, int id, const string& studentName, const string& studentEmail, const string& studentUnits, const string& studentProgram, const string& studentLevel);
	
	//record number getter
	int getRecordNumber() const;
	//id number getter
	int getIdNumber() const;
	//name getter
	string getName() const;
	//email getter
	string getEmail() const;
	//unit getter
	string getUnits() const;
	//program getter
	string getProgram() const;
	//grade getter
	string getLevel() const;
	//absence getter
	int getAbsenceCount() const;
	//most recent absence getter
	string getMostRecentAbsenceDate() const;

	//record number setter
	void setRecordNumber(int record);
	//id number setter
	void setIdNumber(int id);
	//name setter
	void setName(const string& studentName);
	//email setter
	void setEmail(const string& studentEmail);
	//units setter
	void setUnits(const string& studentUnits);
	//program setter
	void setProgram(const string& studentProgram);
	//level setter
	void setLevel(const string& studentLevel);

	//add absences to student
	void addAbsence(const string& date);
	//remove absence from student
	void removeAbsence(const string& date);
	//the day the student was absent
	bool dateOfAbsence(const string& date) const;
	//getter for the absent days using stack
	stack<string> getAbsenceDates() const;

private:

	int recordNum;
	int idNum;
	string name;
	string email;
	string units;
	string program;
	string level;
	int absenceCount;
	stack<string> absenceDates;
};