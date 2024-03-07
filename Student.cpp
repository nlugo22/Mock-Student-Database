/*
 * Student.cpp
 *
 *  Created on: Apr 8, 2023
 *      Author: nlugo
 */

#include "Student.h"

#include <iostream>

//student.h used to set all the data as well as get the current data
Student::Student(){
	studentID = "ID_ERROR";
	studentAge = -1;
	for (int i = 0; i < 3; ++i){
	numDaysToFinishCourse[i] = -1;
	}
	studentFirstName = "FNAME_ERROR";
	studentLastName = "LNAME_ERROR";
	studentEmail = "EMAIL_ERROR";
	degree = SOFTWARE;
}

Student::~Student(){
}

Student::Student(std::string StudentID, std::string firstName, std::string lastName,
		std::string emailAddress, int age, int* daysInCourse, DegreeProgram degree){

	this->SetID(StudentID);
	this->SetFirstName(firstName);
	this->SetLastName(lastName);
	this->SetEmail(emailAddress);
	this->SetAge(age);
	this->SetDaysInCourse(daysInCourse);
	this->SetDegreeProgram(degree);
	}

//setters (mutators)
void Student::SetFirstName(std::string firstName){
	studentFirstName = firstName;
}

void Student::SetLastName(std::string lastName){
	studentLastName = lastName;
}

void Student::SetID(std::string identificationNumber){
	studentID = identificationNumber;
}

void Student::SetEmail(std::string email){
	studentEmail = email;
}

void Student::SetAge(int age){
	studentAge = age;
}

void Student::SetDaysInCourse(int* daysInCourse){
		this->numDaysToFinishCourse[0] = daysInCourse[0];
		this->numDaysToFinishCourse[1] = daysInCourse[1];
		this->numDaysToFinishCourse[2] = daysInCourse[2];
}

//getters (accessors)
void Student::SetDegreeProgram(DegreeProgram degree){ this->degree = degree;}

std::string Student::GetID() const{ return studentID;}

std::string Student::GetFirstName() const{ return studentFirstName;}

std::string Student::GetLastName() const{ return studentLastName;}

std::string Student::GetEmail() const{ return studentEmail;}

int Student::GetAge() const{ return studentAge;}

const int* Student::GetDaysInCourse() {return numDaysToFinishCourse;}

DegreeProgram Student::GetDegreeProgram(){ return degree;}

//print function for students
void Student::Print(){
	//print all the data values of student
	std::cout << GetID() << "\t"
			 << "First Name: " << GetFirstName() << "\t"
			 << "Last Name: " << GetLastName() << "\t"
			 << "Email: " << GetEmail() << "\t"
			 << "Age: " << GetAge() << "\t";
	//prints the array elements stored in numDaysToFinishCourse
	const int* x;
	x = GetDaysInCourse();
	std::cout << "daysInCourse: {";
	for (int i = 0; i < 3; ++i){
		if (i < 2){
			std::cout << *x << ", ";
		}
		else{
			std::cout << *x << "} ";
		}
		x++;
	}
	std::cout << "Degree Program: ";
	if (GetDegreeProgram() == 0){
		std::cout << "Security";
	}else if (GetDegreeProgram() == 1){
		std::cout << "Network";
	}else if (GetDegreeProgram() == 2){
		std::cout << "Software";
	}
	std::cout << std::endl;
}


