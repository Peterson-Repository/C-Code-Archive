#include <iostream>
#include "persons.h"

using namespace std;

	person::person(){
	}

	person::person(string& name, int id ){
		this-> Name = name;
		this-> ID = id;
	}

	person::~person(){
	}

	void person::SetName(string & name){
		this-> Name = name;
	}

	string person::GetName(){
		return Name;
	}

	void person::SetID(int id){
		this-> ID = id;
	}

	int person::GetID(){
		return ID;
	}

