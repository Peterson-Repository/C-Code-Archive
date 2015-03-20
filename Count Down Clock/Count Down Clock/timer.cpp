/*
 * Program: Project 2
 * Author: Marco Peterson
 * Date: Sep-29-2011
 * Course: Object Oriented Programming
 *
 * Program Description
 * 
 *This Program counts down from a user specifed time in one of 2 way. 1)small numbers  2)Big numbers
 * 
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <windows.h>
using namespace std;



//Class Decloartion
class timer{
	private:
		int seconds;

	public:
		//accessors

		timer(int secondinput){
			seconds = secondinput;
		}
		

void DisplaySmallCountDown(){

	for (int sec = seconds; sec >= 0; sec--){

		if(sec < 5){
			cout <<"\a";
		}
			


		Sleep(1000);
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t" << sec << " :seconds remaining" << endl;
	}
}


void DisplayLargeCountDown(){
	int sec = seconds;

	string Digits[] ={//Zero
					"______",
					"|    |",
					"|    |",
					"|    |",
					"______",

					//One
					"   |  ",
					"   |  ",
					"   |  ",
					"   |  ",
					"   |  ",

					//Two
					" ---- ",
					"     |",
					" ---- ",
					"|     ",
					" ---- ",

					//Three
					" ---- ",
					"     |",
					" ---- ",
					"     |",
					" ---- ",

					//Four
					" |  | ",
					" ---- ",
					"    | ",
					"    | ",
					"    | ",

					//Five
					" ---- ",
					"|     ",
					" ---- ",
					"     |",
					" ---- ",

					//six
					"|     ",
					"|     ",
					" ---- ",
					"|    |",
					" ---- ",

					//Seven
					" ---- ",
					"     |",
					"     |",
					"     |",
					"     |",

					//Eight
					" ---- ",
					"|    |",
					" ---- ",
					"|    |",
					" ---- ",  

					//Nine
					" ---- ",
					"|    |",
					" ---- ",
					"     |",
					"     |",
	};

	while(sec != -1){
		cout<<"\n\n\n\n\n\n\n\n";

	for(int i = 0; i<5; i++){

		if(sec < 10){
			cout << "\t\t\t\t\t" << Digits[5*sec+i]  << endl;
		}

		else if(sec < 100){
			cout << "\t\t\t\t" << Digits[sec/10*5+i] << " " << Digits[sec%10*5+i] << endl; 
		}

		else if(sec <1000){
			cout << "\t\t\t\t" << Digits[sec/100*5+i] << " "  << Digits[(sec/10)%10*5+i] << " "  << Digits[(sec%10%10)*5+i] << endl;
		}
	}

sec--;
Sleep(1000);
system("cls");
	}
	cout<<"\a"<<endl;
}



};






		//mutators or mutator prototypes
		


//Impementation section for class member functions


	//constuctor

	//deconstutor




//Function prototypes for main/client program






void main(){

	int secondinput;
	int outputnumber;
 
	cout << "enter number of seconds for countdown" << endl;
	cin >> secondinput;

	while (secondinput <= -1 || secondinput > 1000){
		cout<<"Negative inputs and values over 1,000 are invald, please try again"<<endl;
		cin >> secondinput;
	}

	timer countdown1(secondinput);

	cout<<"Choose the format you would like to display count down." <<endl;
	cout<<"1. small numbers" <<endl;
	cout<<"2. Big numbers" <<endl;
	cin >> outputnumber;

		while(outputnumber <=0 || outputnumber >=3){
			cout<<"Please input a valid number" <<endl;
			cin >> outputnumber;
		}

		if(outputnumber == 1){
			countdown1.DisplaySmallCountDown();
		}

		else if(outputnumber == 2){
			countdown1.DisplayLargeCountDown();
		}


	Sleep(1000);
	cout << "\n\n\n\n\n\n\n\t\t\t\t PROGRAM TERMINATED" << endl;

}
