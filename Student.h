#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student{
     public:
             //Constructor
             Student(char*, int, double);
             //Destructor
             ~Student();
             //Print out the nessecary information about the student
             void printStuff();
	     void print();
             //Get the students id for searching purposes
             int getId();
	     int getID();
             //Get the students gpa for averaging purposes
             double getGpa();
	     //Get the students name for any reason you might need
	     char* getName();
     private:
             char* name;
             int ID;
             double gpa;
};
#endif
