/*
Name: Reid Pace
Class: 122
Assignment: PA7
Date: March 29th, 2025
Lab Section: 10
Description: file for data class definitions
*/
#include "Data.hpp"

Data::Data() : recordNum(0), idNum(0), absenceCount(0) {}

Data::Data(int record, int id, const string& studentName, const string& studentEmail, const string& studentUnits, const string& studentProgram, const string& studentLevel) : recordNum(record), idNum(id), name(studentName), email(studentEmail), units(studentUnits), program(studentProgram), level(studentLevel), absenceCount(0) {}

int Data::getRecordNumber() const {
    return recordNum;
}

int Data::getIdNumber() const {
    return idNum;
}

string Data::getName() const {
    return name;
}

string Data::getEmail() const {
    return email;
}

string Data::getUnits() const {
    return units;
}

string Data::getProgram() const {
    return program;
}

string Data::getLevel() const {
    return level;
}

int Data::getAbsenceCount() const {
    return absenceCount;
}

string Data::getMostRecentAbsenceDate() const {
    if (!absenceDates.empty()) {
        return absenceDates.top();
    }
    return "None";
}

void Data::setRecordNumber(int record) {
    recordNum = record;
}

void Data::setIdNumber(int id) {
    idNum = id;
}

void Data::setName(const string& studentName) {
    name = studentName;
}

void Data::setEmail(const string& studentEmail) {
    email = studentEmail;
}

void Data::setUnits(const string& studentUnits) {
    units = studentUnits;
}

void Data::setProgram(const string& studentProgram) {
    program = studentProgram;
}

void Data::setLevel(const string& studentLevel) {
    level = studentLevel;
}

void Data::addAbsence(const std::string& date) {
    stack<string> tempStack = absenceDates;
    bool dateExists = false;

    while (!tempStack.empty() && !dateExists) {
        if (tempStack.top() == date) dateExists = true;
        tempStack.pop();
    }
    if (!dateExists) {
        absenceDates.push(date);
        absenceCount++;
    }
}

void Data::removeAbsence(const string& date) {
    stack<string> tempStack;
    bool dateFound = false;

    while (absenceDates.empty()) {
        string currentDate = absenceDates.top();
        absenceDates.pop();

        if (currentDate != date) {
            tempStack.push(currentDate);
        }
        else {
            dateFound = true;
        }
    }
    while (!tempStack.empty()) {
        absenceDates.push(tempStack.top());
        tempStack.pop();
    }
    if (dateFound) absenceCount--;
}

bool Data::dateOfAbsence(const string& date) const {
    stack<string> tempStack = absenceDates;

    while (!tempStack.empty()) {
        if (tempStack.top() == date) return true;
        tempStack.pop();
    }
    return false;
}

stack<string> Data::getAbsenceDates() const {
    return absenceDates;
}