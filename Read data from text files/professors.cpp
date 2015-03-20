#include <iostream>
#include "professors.h"
#include "persons.h"

using namespace std;

professor::professor(): person(){
}

professor::professor(string& name, int id ): person(name, id){
}

professor::~professor( ) {
}

void professor::SetLevel(int level){
	Level = level;
}

int professor::GetLevel( ){
	return Level;
}

void professor::SetSalary(float salary){
	this-> Salary = salary;
}

float professor::GetSalary( ){
	return Salary;
}

void professor::SetProgram(string& major){
	Program = major;
}

string professor::GetProgram( ){
	return Program;
}

