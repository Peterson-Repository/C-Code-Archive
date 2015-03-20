/*
 * Program:
 * Author: Marco Peterson
 * Date:
 * Course:
 *
 * Program Description
 * 
 * Input an Employees Income using Class
 * 
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;



//Class Decloartion
class Employee{
	protected:
		double salary;


	public:
		int ID;
		//accessors
		Employee(){
			ID = 0;
		}

		Employee(int IDinput){
			ID = IDinput;
		}

		int getID(){
			return ID;
		}

		double getSalary(){
			return salary;
		}


		//mutators or mutator prototypes

		void setSalary(double salaryinput){
			salary = salaryinput;
		}
};

class Manager : public Employee{

	private:
		double bonus;

	public:
		Manager(){
			ID = 0;
		}

		Manager(int IDinput){
			ID = IDinput;
		}

		void setBonus(double bonusInput){
			bonus = bonusInput;
		}

		double getBonus(){
			return bonus;
		}

};


//Implementation section for class member functions





//Function prototypes for main/client program




void main(){

	double salaryinput;
	double bonusinput;
	int IDinput;

	cout<<"Enter Emplyee ID Number: ";
	cin>> IDinput;

	while(IDinput < 0){
		cout<<"Invalid ID Number, please try again."<<endl;
		cout<<"Enter Emplyee ID Number: ";
		cin>> IDinput;
	}

	Manager staff1(IDinput);

	cout<<"Input Employee Salary: ";
	cin >> salaryinput;

	while(salaryinput < 0){
		cout<<"Negative numbers are invalid, pleasr try again."<<endl;
		cout<<"Input Employee Salary: ";
		cin >> salaryinput;
	}

	staff1.setSalary(salaryinput);

	cout<<"Input Employee Bonus: ";
	cin >> bonusinput;

	while(bonusinput < 0){
		cout<<"Negative numbers are invalid, please try again."<<endl;
		cout<<"Input Employee Bonus: ";
		cin >> bonusinput;
	}

	staff1.setBonus(bonusinput);

	cout<< endl;
	cout<<"Employee "<<staff1.getID() <<endl;
	cout<<"Salary: $"<<staff1.getSalary() <<endl;
	cout<<"bonus: $"<<staff1.getBonus()<<endl;

	system("pause");
}

