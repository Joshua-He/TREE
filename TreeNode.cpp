#include <iostream>
#include "TreeNode.h"
#include <string.h>


using namespace std;


TreeNode::TreeNode(){
  next = NULL;
  left = NULL;
  right = NULL;
  value[0] = '\0';
}


TreeNode::~TreeNode(){
  
}

void TreeNode::setLeft(TreeNode* newLeft){
  left = newLeft;
}

void TreeNode::setRight(TreeNode* newRight){
  right = newRight;
}

TreeNode* TreeNode::getLeft(){
  return left;
}

TreeNode* TreeNode::getRight(){
  return right;
}

TreeNode* TreeNode::getNext(){
  return next;
}

void TreeNode::setNext(TreeNode* newNext){
  next = newNext;
}

char* TreeNode::getValue(){
  return value;
}

void TreeNode::setValue(char newValue[100]){
  strcpy(value, newValue);
}





