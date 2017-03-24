#include <iostream>
#ifndef NODE_H
#define NODE_H

//Class Definition for Node class

class Node{
 public:
  Node();
  ~Node();
  Node* getNext();
  void setNext(Node* newNext);
  void setValue(char C);
  char getValue();
 private:
  Node* next;
  char value[20];
};
#endif
