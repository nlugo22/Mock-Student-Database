/*
 * Student.h
 *
 *  Created on: Apr 8, 2023
 *      Author: nlugo
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include "Degree.h"
#include <string>

class Student {
	public:
		//constructor
		Student();
		~Student();
		Student(std::string StudentID, std::string firstName, std::string lastName,
		std::string emailAddress, int age, int* daysInCourse, DegreeProgram degree);
		//mutators
		void SetFirstName(std::string firstName);
		void SetLastName(std::string lastName);
		void SetID(std::string identificationNumber);
		void SetEmail(std::string email);
		void SetAge(int age);
		void SetDaysInCourse(int* daysInCourse);
		void SetDegreeProgram(DegreeProgram degree);

		//accessors
		std::string GetID() const;
		int GetAge() const;
		const int* GetDaysInCourse();
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetEmail() const;
		DegreeProgram GetDegreeProgram();
		void Print();

	private:
		//data variables
		std::string studentID;
		int studentAge;
		int numDaysToFinishCourse[3];
		std::string studentFirstName;
		std::string studentLastName;
		std::string studentEmail;
		DegreeProgram degree;


};

#endif /* STUDENT_H_ */
