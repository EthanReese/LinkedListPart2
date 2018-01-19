//A program to manage student records using linked lists
//Created by: Ethan Reese
//January 4, 2018

using namespace std;

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Student.h"
#include "Node.h"


void add(Student* newStudent, Node* &head);
void print(Node* next);
void deleteStudent(int, Node* head);
void toLowerCase(char (&arr)[80]);
void printAverage(Node* head);

int main(){
     //Fix the head of the linked list
     Node* head = NULL;
     //Run a while loop that can 
     while(true){
          cout << "Your command words are 'Add', 'Delete', 'Average,' 'Quit,' and 'Print'";
          char input[80];
          cin >> input;
          toLowerCase(input);
          //If they want to add a student to the list
          if(strcmp(input, "add") == 0){
               cout << "Please enter the name of the student: ";
               char nameInput[80];
	       cin.ignore();
               cin.getline(nameInput, 80);
               toLowerCase(nameInput);
               char* nameInputNew = new char[80];
               strcpy(nameInputNew, nameInput);
               cout << "Please enter the student's unique identifier: ";
               int ID = 0;
               cin >> ID;
               cout << "Please enter the student's GPA rounded to two decimal places: ";
               double gpa = 0.0;
               cin >> gpa;
               Student* student = new Student(nameInputNew, ID, gpa);
               add(student, head);
	       delete [] nameInputNew;
          }
          //If they want to delete a character
          else if(strcmp(input, "delete") == 0){
               cout << "Enter the ID of the student you would like to delete: ";
               int id;
	       cin >> id;
               deleteStudent(id, head);
          }
          //If they want to print out all of the students
          else if(strcmp(input, "print") == 0){
               print(head);
          }
          //If they want to print average of gpa
          else if(strcmp(input, "average") == 0){
               printAverage(head);
          }
          //If they want to quit
          else if(strcmp(input, "quit") == 0){
               return 0;
          }
     }          

}

//Function that takes an array and makes all the characters lowercase
void toLowerCase(char (&arr)[80]){
     //Loop through the character array and make every item lowercase
     for(int i = 0; i < 80; i++){
          arr[i] = tolower(arr[i]);
     }
}
//Function that can add a node to the linked list
void add(Student* newStudent, Node* &head){
	if(head == NULL){
		head = new Node(newStudent);
	}
	else{
    	 	head->add(newStudent);
	}
}
//Function that prints out every node
void print(Node* next){
     //Use Carson's brilliant print function that makes total sense to print out the linked list
     next->print();
}
//Function that can delete an item of the linked list given a name input
void deleteStudent(int ID, Node* head){
     Node* current = head;
     if(head->getStudent()->getId() == ID){
	Node* newFirst = head->getNext();
	delete head;
	head = newFirst;
	return;
     }
     //Loop over all the nodes and find one with a matching name
     while(current->getNext() != NULL){
          if(current->getNext()->getStudent()->getId() == ID){
               Node* newNext = current->getNext()->getNext();
               delete current->getNext();
               current->setNext(newNext);
               return;
          }
          current = current->getNext();
     }
     cout << "That name wasn't in the linked list" << endl;
}
//Function that can get the average of the gpas of all the students.
void printAverage(Node* head){
     Node* current = head;
     double total = 0;
     int numStudents = 0;
     //Loop over all of the nodes and get the gpa of the student in each one
     while(current != NULL){
             total += current->getStudent()->getGpa();
             ++numStudents;
             current = current->getNext();
     }
     cout << fixed << setprecision(2) << total/numStudents << endl;
}
