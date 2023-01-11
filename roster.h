#ifndef ROSTER_H
#define ROSTER_H


#include <array>
#include <string>
#include <vector>
#include "student.h"
using namespace std;

class Roster
{

public:
	Roster();
	~Roster();

	// Array variable of type student
	Student* classRosterArray[5];

	// Function that sets the variables to the student object, updating the classRosterArray
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int num) {

		(*classRosterArray[num]).setStudentID(studentID);
		(*classRosterArray[num]).setFirstName(firstName);
		(*classRosterArray[num]).setLastName(lastName);
		(*classRosterArray[num]).setEmailAddress(emailAddress);
		(*classRosterArray[num]).setAge(age);

		array<int, 3> daysInCourse;
		daysInCourse[0] = daysInCourse1;
		daysInCourse[1] = daysInCourse2;
		daysInCourse[2] = daysInCourse3;

		(*classRosterArray[num]).setDaysInCourse(daysInCourse);
		(*classRosterArray[num]).setDegreeProgram(degreeProgram);
	}


	// Function that deletes an object from the roster and creates a default object in its place
	void remove(string studentID) {

		int num;

		if (studentID == "A1")
			num = 0;
		else if (studentID == "A2")
			num = 1;
		else if (studentID == "A3")
			num = 2;
		else if (studentID == "A4")
			num = 3;
		else if (studentID == "A5")
			num = 4;
		else
			cout << endl << "A student with ID of " << studentID << "was not found." << endl;

		if ((*classRosterArray[num]).getStudentID() == "NoID") {
			cout << endl << "A student with ID of \"" << studentID << "\" was not found." << endl;
		}
		else {

			delete (classRosterArray[num]);

			classRosterArray[num] = new Student();
		}

	}

	// Function that loops through classRosterArray and calls the print function for each student
	void printAll(Roster classRoster) {
		for (int i = 0; i < 5; ++i) {
			(*classRoster.classRosterArray[i]).print();
		}
	}

	// Function that calculates the average of 3 integers representing the number of days left in course
	void printAverageDaysInCourse(string studentID) {

		array<int, 3> days;

		int result;

		int num;

		if (studentID == "A1")
			num = 0;
		else if (studentID == "A2")
			num = 1;
		else if (studentID == "A3")
			num = 2;
		else if (studentID == "A4")
			num = 3;
		else
			num = 4;


		switch (num) {

		case 0:
			days = (*classRosterArray[0]).getDaysInCourse();
			result = ((days[0] + days[1] + days[2]) / 3);
			cout << (*classRosterArray[0]).getStudentID() << "	Average of " << result << " days" << endl;
			break;
		case 1:
			days = (*classRosterArray[1]).getDaysInCourse();
			result = ((days[0] + days[1] + days[2]) / 3);
			cout << (*classRosterArray[1]).getStudentID() << "	Average of " << result << " days" << endl;
			break;
		case 2:
			days = (*classRosterArray[2]).getDaysInCourse();
			result = ((days[0] + days[1] + days[2]) / 3);
			cout << (*classRosterArray[2]).getStudentID() << "	Average of " << result << " days" << endl;
			break;
		case 3:
			days = (*classRosterArray[3]).getDaysInCourse();
			result = ((days[0] + days[1] + days[2]) / 3);
			cout << (*classRosterArray[3]).getStudentID() << "	Average of " << result << " days" << endl;
			break;
		default:
			days = (*classRosterArray[4]).getDaysInCourse();
			result = ((days[0] + days[1] + days[2]) / 3);
			cout << (*classRosterArray[4]).getStudentID() << "	Average of " << result << " days" << endl;
			break;

		}

	}

	// Function that evaluates the emails and looks for improper formatting such as email containg a space or without '@' or '.'
	void printInvalidEmails() {

		vector<string> emails;

		for (int i = 0; i < 5; ++i) {

			if ((*classRosterArray[i]).getEmailAddress().find(' ') != std::string::npos) {
				emails.push_back((*classRosterArray[i]).getEmailAddress());
			}

			if (((*classRosterArray[i]).getEmailAddress().find('@') != std::string::npos)
				&& ((*classRosterArray[i]).getEmailAddress().find('.') != std::string::npos)) {

			}
			else {
				emails.push_back((*classRosterArray[i]).getEmailAddress());
			}

		}

		cout << endl << "Invalid Emails Found:" << endl;

		for (unsigned int i = 0; i < emails.size(); ++i) {

			cout << emails[i] << endl;

		}

	}

	// Function that prints students to the screen based on the degree program from input
	void printByDegreeProgram(DegreeProgram degreeProgram) {

		vector<Student> students;

		for (int i = 0; i < 5; ++i) {
			if ((*classRosterArray[i]).getDegreeProgram() == degreeProgram) {
				students.push_back((*classRosterArray[i]));
			}
		}

		switch (degreeProgram) {
		case 0:
			cout << endl << "Student(s) doing a " << "SECURITY degree:" << endl;
			break;
		case 1:
			cout << endl << "Student(s) doing a " << "NETWORK degree:" << endl;
			break;
		case 2:
			cout << endl << "Student(s) doing a " << "SOFTWARE degree:" << endl;
			break;
		default:
			return;

		}

		for (unsigned int i = 0; i < students.size(); ++i) {

			students[i].print();
		}
	}
};


#endif // ROSTER_H
