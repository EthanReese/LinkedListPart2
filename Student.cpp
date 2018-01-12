#include "Student.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

Student::Student(char* newName, int newID, double newGpa){
     //Assign all of the nessecary variables
     name = new char[80];
     strcpy(name, newName);
     gpa = newGpa;
     ID = newID;
}

Student::~Student(){
     //Destructor class
     delete name;
}

void Student::printStuff(){
     cout << name << ", ";
     cout << ID << " ,";
     cout << gpa << endl;
}

void Student::print(){
	cout << name << ", ";
	cout << ID << " ,";
	cout << gpa << endl;
}

int Student::getId(){
     return ID;
}

double Student::getGpa(){
     return gpa;
}
char* Student::getName(){
	return name;
}
int Student::getID(){
	return ID;
}
