#include <iostream>
#include "roster.h"
#include <vector>
using namespace std;

// Function to parse the strings from the original table and store the data in a vector
vector<string> parseString(const string studentData[]) {

	vector<string> words;

	for (int num = 0; num < 5; ++num) {

		unsigned int counter = 0;

		string word;

		int count = 0;

		do {

			while (studentData[num][counter] != ',' && counter < studentData[num].length()) {
				word += studentData[num][counter];
				counter++;
			}

			words.push_back(word);

			counter++;

			word = "";

			count++;

		} while (count < 9);
	}

	return words;
}

// Function to convert the enumarated item to a string
DegreeProgram parseDegree(string n) {

	DegreeProgram a;

	if (n == "SECURITY")
		a = SECURITY;
	else if (n == "NETWORK")
		a = NETWORK;
	else if (n == "SOFTWARE")
		a = SOFTWARE;
	else
		a = NOTSET;

	return a;
}

int main(int argc, char** argv)
{
	// Header with my personal information
	cout << "Course Title: \tScripting and Programming - Applications - C867" << endl;
	cout << "Prog Language: \tC++" << endl;
	cout << "My WGU ID: \t008830456" << endl;
	cout << "Name: \t\tRodrigo Ferreira Maceno" << endl;

	cout << endl;

	// Original table with data
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
									"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
									"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
									"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
									"A5,Rodrigo,Ferreira,rmaceno3@gmail.com,34,45,36,25,SOFTWARE" };


	Roster* classRoster = new Roster;

	// Created a vector of type string to store each data for each student
	vector<string> student = parseString(studentData);

	// Call to add() function for each student
	(*classRoster).add(student[0],
		student[1],
		student[2],
		student[3],
		std::stoi(student[4]),
		std::stoi(student[5]), std::stoi(student[6]), std::stoi(student[7]),
		parseDegree(student[8]), 0);

	(*classRoster).add(student[9],
		student[10],
		student[11],
		student[12],
		std::stoi(student[13]),
		std::stoi(student[14]), std::stoi(student[15]), std::stoi(student[16]),
		parseDegree(student[17]), 1);

	(*classRoster).add(student[18],
		student[19],
		student[20],
		student[21],
		std::stoi(student[22]),
		std::stoi(student[23]), std::stoi(student[24]), std::stoi(student[25]),
		parseDegree(student[26]), 2);

	(*classRoster).add(student[27],
		student[28],
		student[29],
		student[30],
		std::stoi(student[31]),
		std::stoi(student[32]), std::stoi(student[33]), std::stoi(student[34]),
		parseDegree(student[35]), 3);

	(*classRoster).add(student[36],
		student[37],
		student[38],
		student[39],
		std::stoi(student[40]),
		std::stoi(student[41]), std::stoi(student[42]), std::stoi(student[43]),
		parseDegree(student[44]), 4);


	// Call to printAll() function from Roster class
	(*classRoster).printAll(*classRoster);


	// print Invalid Emails
	(*classRoster).printInvalidEmails();


	cout << endl;


	cout << "Average Days Left in Course:" << endl;

	// loop through classRosterArray and call printAverageDaysInCourse to calculate the average for each student
	for (int i = 0; i < 5; ++i) {
		(*classRoster).printAverageDaysInCourse((*(*classRoster).classRosterArray[i]).getStudentID());
	}


	(*classRoster).printByDegreeProgram(SOFTWARE);


	(*classRoster).remove("A3");


	cout << endl << "After Removing:" << endl;


	(*classRoster).printAll(*classRoster);


	(*classRoster).remove("A3");


	delete classRoster;


	return 0;
}
