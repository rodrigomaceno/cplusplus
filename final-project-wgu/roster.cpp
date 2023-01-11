#include "roster.h"
#include "student.h"
using namespace std;


Roster::Roster()
{
	// constructor for Roster class that initializes an object of type Student and populates the classRosterArray
	classRosterArray[0] = new Student();
	classRosterArray[1] = new Student();
	classRosterArray[2] = new Student();
	classRosterArray[3] = new Student();
	classRosterArray[4] = new Student();

}


Roster::~Roster()
{
}








