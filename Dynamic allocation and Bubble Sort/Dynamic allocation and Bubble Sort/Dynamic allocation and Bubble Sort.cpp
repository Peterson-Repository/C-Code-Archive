/*
 * Program Dynamic allocation and Bubble Sort.cpp
 * Author: Marco Peterson
 * Date: 3-23-2011
 * Course: CSCI250
 *
 * Program Description
 * 
 * Dynamically allocates an array of test scores, then sorts and displays the Avg of test Scores.
 *
 * F7 to Build
 * F5 to Run
 *
 * In order to Build in Visual C++ 2010 Express
 * Go to Tools > Options > Debugging > Native and check Load DLL Exports
 *
 */

#include <iostream>
using namespace std;

void bubble(int array2[], int size);
double Avg(int array2[], int size);

int main(){

	int NumOfTests;
	cout <<"How many test Scores would you like to Enter?" <<endl;
	cin >> NumOfTests;

	int *tests;
	tests = new int[NumOfTests];

	for(int i = 0; i < NumOfTests; i++){
		cout <<"Enter score for test " << i+1 <<" :" <<endl;
		cin >> *(tests + i);

		while( *(tests + i) < 0){
			cout <<"Negative test scores are not valid, try again." <<endl;
			cin >> *(tests + i);
		}
	}

	bubble(tests, NumOfTests);

	cout <<"Sorted Test Scores: "<<endl;
	for(int i = 0; i < NumOfTests; i++){
		cout << tests[i] <<" ";
	}
	
	cout <<endl;
	cout <<"Average is " << Avg(tests, NumOfTests);
	cout <<endl;


	system("pause");
	return 0;
}



//BUBBLE Function
void bubble (int array1[], int size){

	int temp;
	bool swap;
	int swapNum = 0;

	do{
		swap = false;
		for(int count = 0; count < (size - 1); count++){
			if (array1[count] > array1[count + 1]){
				                                        //counter
				temp = array1[count];
				array1[count] = array1[count + 1];
				array1[count + 1] = temp;
				swap = true;
			}
		}

	}while (swap);
	
}

//Average Function
double Avg(int array2[], int size){
	
	double total = 0;
	double Avg = 0;

	for(int i = 0; i < size; i++){
		total = total + array2[i];
	}

	Avg = total / size;

	return Avg;
}