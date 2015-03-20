#include <iostream>
#include "students.h"
#include "persons.h"
#include "professors.h"

using namespace std;

student::student(): person(){
}

student::student(string & name, int id ): person(name, id){
}

student::~student() {
}

void student::SetGPA(float gpa){
	this -> GPA = gpa;
}

float student::GetGPA(){
	return GPA;
}

void student::SetMajor(string& major){
	this -> Major = major;
}

string student::GetMajor(){
	return Major;
}

void student::SetAdvisor(professor* advisor){
	this -> Advisor = advisor;
}

professor* student::GetAdvisor(){
	return Advisor;
}

