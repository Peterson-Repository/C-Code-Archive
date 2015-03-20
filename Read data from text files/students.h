#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
#include <iostream>
#include "persons.h"
#include "professors.h"

using namespace std;

class student: public person{

protected:
	float GPA;
	string Major;
	professor* Advisor;

public:
	student();
	student(string & name, int id );
	~student();
	void SetGPA(float gpa);
	float GetGPA();
	void SetMajor(string& major);
	string GetMajor();
	void SetAdvisor(professor *Advisor);
	professor *GetAdvisor();

};

#endif