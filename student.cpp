#include "student.h"
#include "degree.h"
using namespace std;


Student::Student()
{
    // Constructor for class Student with default values
    studentID = "NoID";
    firstName = "NoFirstName";
    lastName = "NoLastName";
    emailAddress = "NoEmailAddress";
    age = -1;
    daysInCourse = { 0, 0, 0 };
    degreeProgram = NOTSET;
}


Student::~Student()
{
}


