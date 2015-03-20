/*
 * Program:
 * Author: Marco Peterson
 * Date:Nov-9-2011
 * Course:Object Orinted 
 *
 * Program Description Programing
 * 
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

#include "students.h"
#include "professors.h"
#include "persons.h"

using namespace std;

void main(){
	int id;
	string name;
	int studentID;
	string major;
	int professorID;
	int level;
	float salary;
	student *s;
	professor *p1;
	professor *p2;
	float gpa;
	vector<student*> studentList;
	vector<professor*> professorList;


	//-------------------------------------------------------------------------------------------------------------------------------------
	//open professor text file

	ifstream inputFile;
	inputFile.open("professorInfo.txt");
	
	while(!inputFile.eof()){
		if(inputFile.fail()){
			cout <<"professor File did not open" <<endl;

		}

		else{
			inputFile >> name >> professorID >> level;
			p1 = new professor(name, professorID);
			p1->SetLevel(level);
			p1->SetSalary(salary);
			p1->SetProgram(major);
			professorList.push_back(p1);
		}
	}

	inputFile.close();

	professorList.pop_back();

	//------------------------------------------------------------------------------------------------------------------------------------
	//open student text File

	inputFile.open("studentsInfo.txt");
	while(!inputFile.eof()){

		if(inputFile.fail()){
			cout <<"student File did not open" <<endl;
		}

		else{
			inputFile >> name >> studentID >> gpa >> major >> professorID;
			s = new student(name, studentID);
			s->SetGPA(gpa);
			s->SetMajor(major);

			for(unsigned int i = 0; i < professorList.size(); i++){
				p1 = professorList[i];
				if(professorID == p1->GetID()){
					p2 = p1;
				}
			}

			s -> SetAdvisor(p2);
			studentList.push_back(s);
		}
	}

	studentList.pop_back();
	inputFile.close();

	//----------------------------------------------------------------------------------------------------------------------------------------

	cout <<"Enter an ID number: ";
	cin >> id;

	for(unsigned int i = 0; i <studentList.size(); i++){
		s = studentList[i];

		if(id == s->GetID()){
			cout << s->GetName() << endl;
		}
	}

	for(unsigned int i = 0; i < professorList.size(); i++){
		p1 = professorList[i];
		if(id == p1->GetID()){
			cout << p1->GetName();
		}
	}

	//-----------------------------------------------------------------------------------------------------------------------------------------

	cout <<"Enter student name to see GPA ";
	cin >> name;

	for(unsigned int i = 0; i < studentList.size(); i++){
		s = studentList[i];

		if(name == s->GetName()){
			cout << s->GetName() <<" 's GPA is " << s->GetGPA() << endl;
		}
	}

	//-------------------------------------------------------------------------------------------------------------------------------------------

	cout <<"Enter a student's name to locate thier advisor ";
	cin >>name;

	for(unsigned int i = 0; i < studentList.size(); i++){
		s = studentList[i];

		if(name == s->GetName()){
			cout << s->GetName() <<" 's advisor is " << s->GetAdvisor() <<endl;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------------

	cout <<"Enter a professor's name to view salary";
	cin >> name;

	for(int i = 0; i = professorList.size(); i++){
		p1 = professorList[i];

		if(name == p1->GetName()){
			cout << p1->GetName() <<"'s salary is "<< p1->GetSalary() <<endl;
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------------------

	cout <<"Enter a professor's name to view advisees ";
	cin >> name;

	cout << name <<" advisees "<<endl;

	for(unsigned int i = 0; i <studentList.size(); i++){
		s = studentList[i];

		if(name == s->GetAdvisor()->GetName()){
			cout << s->GetName() <<endl;
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------------------------

	cout <<"Professors with more then 3 advisees are ";

	int count = 0;

	for(unsigned int i = 0; i < professorList.size(); i++){
		p1 = professorList[i];


		for(unsigned int i = 0; i < studentList.size(); i++){
			if(s->GetAdvisor() -> GetName() == p1 -> GetName()){ 
				count++;
			}
		}
	}

		if(count >= 3){
			cout << p1->GetName();
		}

	//-----------------------------------------------------------------------------------------------------------------------------------------

	cout<<"list of students whos majors do not match their advisors" <<endl;

	for(unsigned int i = 0; i < studentList.size(); i++){
		s = studentList[i];

		if(s->GetMajor() != s->GetAdvisor()->GetProgram()){
			cout << s->GetName() <<endl;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------------
	
	cout <<endl;
	cout <<"Student with highest GPA" <<endl;
	student* highGPA = s;

	for(unsigned int i = 0; i < studentList.size(); i++){
		s = studentList[i];

		if(highGPA -> GetGPA() < s->GetGPA()){
			highGPA = s;
		}
	}

	
	cout<< highGPA->GetName() <<" has the highest GPA." <<endl;
	cout <<endl;

	//-----------------------------------------------------------------------------------------------------------------------------------------

	cout<<"Dr. Millers advisees with a GPA over 3.0" <<endl;

	for(unsigned int i = 0; i < studentList.size(); i++){
		s = studentList[i];

		if(s->GetGPA() > 3.0 && s->GetAdvisor()->GetName() == "Miller"){ //
			cout << s->GetName() <<endl;
		}
	}
	
	//---------------------------------------------------------------------------------------------------------------------------------------------
system ("pause");
}

