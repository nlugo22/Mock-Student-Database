/*
 * Roster.cpp
 *
 *  Created on: Apr 8, 2023
 *      Author: nlugo
 */

#include "Roster.h"

Roster::Roster(){
	this->TOTAL_STUDENTS = 5;         //setting number of students
	this->student = new Student*[TOTAL_STUDENTS]; //making an array of pointers
	//the data given in instructions
	const std::string studentData[] =
			{"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
			 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			 "A5,Nicholas,Lugo,nlugo@wgu.edu,27,30,31,32,SOFTWARE"
			};
	//initialize a count to check how many students there are
	this->inputCount = 0;
	//making Student objects
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		parseData(studentData[i]);
		student[i] = new Student(ID, firstName, lastName, email, age, daysInCourse, degree);
		this->inputCount++;
	}

}

Roster::~Roster(){
	delete student;
}

void Roster::parseData(const std::string studentData){
	unsigned int i;
	std::istringstream inputSS(studentData);
	std::string tempString;
	std::string degreeProgram;

	//using istringstream to separate out all the data into an array
	for (i = 0; i < 9; ++i){
		getline(inputSS, tempString, ',');
		classRosterArray[i] = tempString;
	}
	//setting up all input data
	ID = classRosterArray[0];
	firstName = classRosterArray[1];
	lastName = classRosterArray[2];
	email = classRosterArray[3];
	age = std::stoi(classRosterArray[4]);
	day1 = std::stoi(classRosterArray[5]);
	day2 = std::stoi(classRosterArray[6]);
	day3 = std::stoi(classRosterArray[7]);
	daysInCourse[0] = day1;
	daysInCourse[1] = day2;
	daysInCourse[2] = day3;
	//not required but I changed it so the studentData[] data can be uppercase
	//or lower... add() still needs enum type though
	degreeProgram = classRosterArray[8];
	for (i = 0; i < degreeProgram.size(); ++i){
		degreeProgram.at(i) = tolower(degreeProgram.at(i));
	}
	//setting the ENUM type for the studentData[]
	if (degreeProgram == "security"){
		degree = SECURITY;
	}
	else if (degreeProgram == "network"){
		degree = NETWORK;
	}
	else if (degreeProgram == "software"){
		degree = SOFTWARE;
	}
	else{
		std::cout << "Invalid degree type";
	}
}

//used to add a new student to the system
void Roster::add(std::string ID, std::string firstName, std::string lastName,
		std::string email, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, DegreeProgram degree){
	//increasing the number of students by 1 to add new
	TOTAL_STUDENTS++;
	//assigning data to the array
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	//making space for the new students so make bigger array.
	Student** makeSpace = new Student*[TOTAL_STUDENTS];
	for (int i = 0; i < TOTAL_STUDENTS - 1; ++i){
		makeSpace[i] = student[i];
	}
		delete student;
		this->student = new Student*[TOTAL_STUDENTS];
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		student[i] = makeSpace[i];
	}
	//free the temporary student array
	delete makeSpace;
		student[inputCount] = new Student(ID, firstName, lastName, email, age, daysInCourse, degree);
		this->inputCount++;
}

//Prints all students
void Roster::PrintAll(){
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		student[i]->Print();
	}
std::cout << std::endl;
}

void Roster::RemoveStudent(std::string ID){
	bool match = false;
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		if (student[i]->GetID() == ID){
			match = true;
			int index = i;
			std::cout << "Removing student: " << student[i]->GetID() << std::endl;
			for (i = index; i < TOTAL_STUDENTS -1; ++i){
				student[i] = student[i + 1];

			}
			TOTAL_STUDENTS--;
		}
	}
	std::cout << std::endl;
	if (!match){
		std::cout << "Student with that ID does not exist." << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
//prints everystudent with a given ID
void Roster::PrintByID(std::string ID){
	bool match = false;
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		if (student[i]->GetID() == ID){
			std::cout << "Printing student: " << student[i]->GetID() << std::endl;
			student[i]->Print();
			match = true;
		}
	}
		if (!match){
			std::cout << "No such ID exists." << std::endl;
		}
	std::cout << std::endl;
}
//prints all students with a given enum degreetype
void Roster::PrintByDegree(DegreeProgram degree){
	bool match = false;
	std::cout << "Printing by degree: " << std::endl;
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		if (student[i]->GetDegreeProgram() == degree){
			student[i]->Print();
			match = true;
		}
	}
		if (!match){
			std::cout << "No such ID exists.";
		}
		std::cout << std::endl;
}

void Roster::PrintInvalidEmail(){
	std::string checkEmail;
	int atPosition;
	int periodAfterAt;
	int spaceInEmail;
	std::cout << "Invalid Emails: " << std::endl;
	//if atPosition or periodAFterAt has no value, invalid email.
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		checkEmail = (student[i]->GetEmail());
		atPosition = checkEmail.find('@');
		periodAfterAt = checkEmail.find('.', atPosition);
		spaceInEmail = checkEmail.find(' ');
		if ((atPosition == std::string::npos) || (periodAfterAt == std::string::npos) || (spaceInEmail != std::string::npos)){
			std::cout << checkEmail << std::endl;
		}
	}
	std::cout << std::endl;
}
//grabs the daysInCourse array, adds all data for that student, outputs average
void Roster::PrintAvgDaysCourse(std::string ID){
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		if (student[i]->GetID() == ID){
			std::cout << "Average days in course for student: " << student[i]->GetID() << std::endl;
			const int* addDays;
			int averageDays = 0;
			for (int d = 0; d < 3; ++d){
				addDays = student[i]->GetDaysInCourse();
				averageDays += addDays[d];
			}
			averageDays = averageDays/3;
			std::cout << averageDays << std::endl;
			std::cout << std::endl;

		}
	}
}

