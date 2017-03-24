#include <iostream>
#include <string.h>
#include "Node.h"

using namespace std;

Node::Node(){
  next = NULL;

}

Node::~Node(){

}
  

// get next

Node* Node::getNext(){
  return next;
}

// get value

char Node::getValue(){
  return value[0];
}

//set next

void Node::setNext(Node* newNext){
  next = newNext;
}

// set value to the operator being passed in
void Node::setValue(char C){
  value[0] = C;
  value[1] = '\0';
}




