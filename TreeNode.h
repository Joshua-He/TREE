#include <iostream>

#ifndef TREENODE_H
#define TREENODE_H



class TreeNode{
 public:
  TreeNode();
  ~TreeNode();
  TreeNode* getRight();
  TreeNode* getLeft();

  void setLeft(TreeNode* newLeft);
  void setRight(TreeNode* newRight);
  TreeNode* getNext();
  void setNext(TreeNode* newNext);
  char* getValue();
  void setValue(char newValue[100]);
 private:
  
  TreeNode* left;
  TreeNode* right;
  TreeNode* next;

  char value[100];
};

#endif
