/*
 * Roster.h
 *
 *  Created on: Apr 8, 2023
 *      Author: nicho
 */

#ifndef ROSTER_H_
#define ROSTER_H_

#include "Student.h"
#include "Degree.h"
#include <iostream>
#include <string>
#include <sstream>

class Roster {
	public:
		Roster();
		~Roster();
		void PrintAll();
		void PrintByID(std::string ID);
		void PrintByDegree(DegreeProgram degree);
		void PrintInvalidEmail();
		void PrintAvgDaysCourse(std::string ID);
		void parseData(const std::string studentData);
		void add(std::string StudentID, std::string firstName,
				std::string lastName, std::string emailAddress, int age,
				int daysInCourse1, int daysInCourse2, int daysInCourse3,
				DegreeProgram degree);
		void RemoveStudent(std::string ID);
	private:
		int TOTAL_STUDENTS;
		int inputCount;
		Student** student;
		std::string classRosterArray[9];
		std::string ID;
		std::string firstName;
		std::string lastName;
		std::string email;
		int age;
		int day1;
		int day2;
		int day3;
		int daysInCourse[3];
		DegreeProgram degree;


};

#endif /* ROSTER_H_ */
