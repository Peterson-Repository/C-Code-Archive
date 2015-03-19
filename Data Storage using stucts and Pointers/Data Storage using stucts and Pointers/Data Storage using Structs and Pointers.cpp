/*
 * Program Data Storage using strcuts and pointers.cpp
 * Author: Marco Peterson
 * Date: 3-31-2011
 * Course: CSCI250
 *
 * Program Description
 * 
 * This program asks and stores student names, and test scores using a structure format.
 * 
 * F7 to Build
 * F5 to Run
 *
 * In order to Build in Visual C++ 2010 Express
 * Go to Tools > Options > Debugging > Native and check Load DLL Exports
 *
 */

#include <iostream>
#include <string>
using namespace std;

struct GradeBook{
	int score;
	string name;
};

void bubble(GradeBook *students, int NumOfStudents);
double Avg(GradeBook *students, int NumOfStudents);
 
int main(){

	int NumOfStudents;

	cout <<"Enter the number of students." <<endl;
	cin >> NumOfStudents;

	GradeBook *students = new GradeBook[NumOfStudents];

	for(int i = 0; i < NumOfStudents; i++){
		cout<<"Enter the Name and then the Score for student " << i+1 <<": ";
		cin >> students[i].name >> students[i].score;

			while(students[i].score < 0){
				cout <<"Negative numbers are invalid, try again ";
				cin >> students[i].score;
			}
	}
	cout<<endl;


	//Output
	for(int i = 0; i < NumOfStudents; i++){
		cout<< students[i].name <<" "<< students[i].score <<endl;
	}

	//Bubble Sort Call
	bubble(students, NumOfStudents);

	cout <<endl;
	cout <<"Student Scores In Sorted Order" <<endl;

	//Output Swaped DATA
	for(int i = 0; i < NumOfStudents; i++){
		cout<< students[i].name <<" "<< students[i].score <<endl;
	}
	cout <<endl;
	
	//Avg Functoin Call
	cout <<"The Class Avg is " << Avg(students, NumOfStudents);

	//end of Program
	cout <<endl;
	cout <<endl;
	return 0;
}



//BUBBLE Function
void bubble (GradeBook *students, int NumOfStudents){

	int temp;
	string nameTemp;
	bool swap;

	do{
		swap = false;
		for(int i = 0; i < (NumOfStudents - 1); i++){
			if (students[i].score > students[i + 1].score){
				
				//swaping scores
				temp = students[i].score;
				students[i].score = students[i + 1].score;
				students[i + 1].score = temp;

				//swaping names
				nameTemp = students[i].name;
				students[i].name = students[i + 1].name;
				students[i + 1].name = nameTemp;

				swap = true;
			}
		}

	}while (swap);
	
}

//Average Function
double Avg(GradeBook *students, int NumOfStudents){
	
	double total = 0;
	double Avg = 0;

	for(int i = 0; i < NumOfStudents; i++){
		total = total + students[i].score;
	}

	Avg = total / NumOfStudents;

	system("pause");

	return Avg;
}