//Carson cummins 2017
//this is the header for the node class
#ifndef NODE_H
#define NODE_H
class Node{
 public:
  void setNext(Node * next);
  Node* getNext();
  void print();
  void add(Student* s);
  Student* getStudent();
  Node(Student * s);
  ~Node();
 protected:
  Node* nxt;
  Student* myStudent;


};
#endif
