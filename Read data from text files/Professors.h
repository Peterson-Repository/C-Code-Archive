#ifndef PROFESSORS_H
#define PROFESSORS_H

#include <string>
#include <iostream>
#include "persons.h"


using namespace std;

class professor: public person{

protected:
	int Level;
	float Salary;
	string Program;

public:
	professor();
	professor(string& name, int id);
	~professor();
	void SetLevel(int level);
	int GetLevel();
	void SetSalary(float salary);
	float GetSalary();
	void SetProgram(string& major);
	string GetProgram();
};

#endif