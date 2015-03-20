#ifndef PERSONS_H
#define PERSONS_H

#include <string>
#include <iostream>

using namespace std;

class person{

protected:
	string Name;
	int ID;

public:
	person();
	person(string & name, int id);
	~person();
	void SetName(string & name);
	string GetName();
	void SetID(int id);
	int GetID();

};

#endif