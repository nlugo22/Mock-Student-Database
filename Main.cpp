//============================================================================
// Author      : nlugo
// Version     : 1.0
//============================================================================

#include <iostream>
#include "Roster.h"
#include <string>

int main() {
	Roster* classRoster = new Roster();

	classRoster->PrintAll();
	classRoster->PrintInvalidEmail();
	classRoster->PrintAvgDaysCourse("A2");
	classRoster->PrintByID("A1");
	classRoster->PrintByDegree(SOFTWARE);
	classRoster->RemoveStudent("A3");
	classRoster->PrintAll();
	classRoster->RemoveStudent("A3");

/*	//was testing adding in students
 * classRoster->add("A6","TIMMEH","TheCruel","timmy@hotmail.com",150,1,2,3,SECURITY);
	classRoster->add("A7","JIMMEH","Neutron","jimmyn@ymail.com",867,1,1,1,NETWORK);
	classRoster->add("A8","Arthas","Menethol","purge strath@icc.com",42,7,8,9,SOFTWARE);
	classRoster->add("A9","Monty","Python","holygrail@google.com",149,10,11,12,SECURITY);
	classRoster->add("A10","Salem","TheCat","meow@hotmailcom",21,13,14,15,NETWORK);
*/
	delete classRoster;

	return 0;
}
