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
             //Get the students id for searching purposes
             int getId();
             //Get the students gpa for averaging purposes
             double getGpa();
     private:
             char* name;
             int ID;
             double gpa;
};
#endif
