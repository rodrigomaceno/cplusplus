#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include "degree.h"
#include <array>
#include <string>
using namespace std;

class Student
{

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    array<int, 3> daysInCourse;
    DegreeProgram degreeProgram;

public:
    Student();
    ~Student();


    // Setters
    void setStudentID(string ID) {
        studentID = ID;
    }

    void setFirstName(string fName) {
        firstName = fName;
    }

    void setLastName(string lName) {
        lastName = lName;
    }

    void setEmailAddress(string eAddress) {
        emailAddress = eAddress;
    }

    void setAge(int a) {
        age = a;
    }

    void setDaysInCourse(array<int, 3> dInCourse) {
        daysInCourse = dInCourse;
    }

    void setDegreeProgram(DegreeProgram dProgram) {
        degreeProgram = dProgram;
    }


    //Getters
    string getStudentID() {
        return studentID;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getEmailAddress() {
        return emailAddress;
    }

    int getAge() {
        return age;
    }

    array<int, 3> getDaysInCourse() {
        return daysInCourse;
    }

    DegreeProgram getDegreeProgram() {
        return degreeProgram;
    }

    // Print()
    void print() {

        string degree;

        if (degreeProgram == SECURITY) {
            degree = "SECURITY";
        }
        else if (degreeProgram == NETWORK) {
            degree = "NETWORK";
        }
        else if (degreeProgram == SOFTWARE) {
            degree = "SOFTWARE";
        }
        else
            degree = "NOTSET";

        cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: "
            << lastName << "\t" << "Email: " << emailAddress << "\t" << "Age: " << age
            << "\t" << "Days in course: {" << daysInCourse[0] << "," << daysInCourse[1]
            << "," << daysInCourse[2] << "}" << "\t" << "Degree Program: " << degree << endl;
    }

};


#endif // STUDENT_H
