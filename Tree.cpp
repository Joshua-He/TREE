#include <iostream>
#include <string.h>
#include <stack>
#include "Node.h"
#include "TreeNode.h"
#include <cstring>

using namespace std;


/*

Joshua He 

Period 7 

This program converts an Infix expression to postfix using a linked lsit stack and the shunting yard algorithm.
It then takes that postfix string and builds a prefix, infix, or postfix expression tree depending on what the user wants

 */
void push(Node* &head, char C);
void pop(Node* &head, char C, char postArray[1000]);
void processToken(Node* &stack, char* token, char postArray[1000]);
int isOperator(char C);
bool isOperand(char C);
bool isSpace(char C);
void popParentheses(Node* &head, char op);
void buildExpressionTree(char postArray[1000], TreeNode* &head);
void addToTree(char token[100], TreeNode* &head);
void printPrefix(TreeNode* head);
void printInfix(TreeNode* head);
void printPostfix(TreeNode* head);

int main(){
  
  char array[100];
  char postArray[1000] = "";
  char output[100] = "";
  char token[100]= "";
  char input[10];
  int length;
  Node* stack = NULL;
  TreeNode* head = NULL;
  
  cout << "Enter an Infix expression. Please enter with a space separating each operator and operand" << endl;
  cout << "For example: 3 + ( 2 * 5 ) + 3" << endl;
  cin.getline(array, 101);
  length = strlen(array);
  cout << "The postfix is: " << endl;

  //Scan the entered string and process each individual token separated by space
  for(int i = 0; i < length; i++){
    if (array[i] == ' '){
      //cout << token << endl;
      processToken(stack, token, postArray);
      token[0] = '\0';      
    }
    else {
      strncat(token, &(array[i]), 1);
    }
    
  }
  //cout << token << endl;
  processToken(stack, token, postArray);
  pop(stack, ' ', postArray);
  //Use postfix string to create the tree
  buildExpressionTree(postArray, head);
  cout << endl;
  cout << "Would you like the tree in prefix, infix, or postfix? (Type \"prefix\", \"infix\", or \"postfix\")" << endl;
  cin >> input;

  //Print the expression tree in 3 ways
  if (strcmp(input, "prefix") == 0){
    printPrefix(head);
  }
  if (strcmp(input, "infix") == 0){
    printInfix(head);
  }
  if (strcmp(input, "postfix") == 0){
    printPostfix(head);
  }
}

//Function to process the different token types 
void processToken(Node* &stack, char* token, char postArray[1000]){
  if (token[0] == ' ' || token[0] == '\0') {
    return;
  }
  
  if (isOperator(token[0]) >0){

    // When the token is not a ^
    if (token[0] != '^') {
      pop(stack, token[0], postArray);
    }
    // Push the operator 
    push(stack, token[0]);
  }
  if (isOperand(token[0]) == true){
    strcat(postArray, token);
    strcat(postArray, " ");
    cout << token << " ";
  }
  if (token[0] == '('){
    push(stack, token[0]);
  }
  if (token[0] == ')'){
    popParentheses(stack, token[0]);
  }
}
//Evaluate if the character is an operator
int isOperator(char C){

  if (C == '+' || C == '-'){
    return 1;
  }
  if (C == '*' || C == '/'){
    return 2;
  }
  if (C == '^'){
    return 3;
  }
  else return 0;
}

//Evaluate if the character is a letter or number 
bool isOperand(char C){
  if ((int)C >= (int)'0' && (int)C <= (int)'9'){
    return true;
  }
  if ((int)C >= (int)'a' && (int)C <= (int)'z'){
    return true;
  }
  if ((int)C >= (int)'A' && (int)C <= (int)'Z'){
    return true;
  }
  else {
    return false;
  }
}

//evaluate if the character is a space
bool isSpace(char C){
  if (C == ' '){
    return true;
  }
  else {
    return false;
  }
}


// pushes an operator into the stack
void push(Node* &head, char C){
  Node* temp = new Node;
  temp->setValue(C);
  if (head == NULL){
    temp->setNext(NULL);
    head = temp;
  }
  else {
    temp->setNext(head);
    head = temp;
  }
}

// function to pop the head value of the stack
void pop(Node* &head, char op, char postArray[1000]){
  Node* temp;
  temp = head;
  char tempOp[100];
  
  while (temp != NULL && isOperator(temp->getValue()) >= isOperator(op)){
    tempOp[0] = temp->getValue();
    strncat(postArray, tempOp, 1);
    strcat(postArray, " ");
    
    cout << temp->getValue() << " ";
    head = temp->getNext();
    delete temp;
    temp = head;
    }
}

//Special pop case for when there are parentheses
void popParentheses(Node* &head, char op){
  Node* temp;
  temp = head;

  while (temp != NULL && temp->getValue() != '('){
    cout << temp->getValue() << " ";
    head = temp->getNext();
    delete temp;
    temp = head;
    }
  if (temp != NULL && temp->getValue() == '('){
    head = temp->getNext();
    delete temp;
    temp = head;
  }
}

//Take the postfix expression and builds a tree; head returns the root of the tree
void buildExpressionTree(char postArray[1000], TreeNode* &head){
  char token[100] = "";
  int length = strlen(postArray);
   for(int i = 0; i <= length; i++){
    if (postArray[i] == ' ' || postArray[i] == '\0'){
      //cout << token << endl;
      addToTree(token, head);
      token[0] = '\0';
    }
    else {
      strncat(token, &(postArray[i]), 1);
    }

  }

}

//Add a single number or operator into the expression tree
void addToTree(char token[100], TreeNode* &head){
  if(token[0] == ' ' || token[0] == '\0'){
    //Return if there is nothing
    return;
  }
  if(isOperand(token[0]) == true){
    TreeNode* newNode = new TreeNode;
    newNode->setValue(token);
    newNode->setNext(head);
    head = newNode;
  }

  //If isoperator returns 1, 2 or 3
  if(isOperator(token[0])){
    TreeNode* temp = new TreeNode;
    temp->setValue(token);
    temp->setRight(head);
    head = head->getNext();
    temp->setLeft(head);
    head = head->getNext();
    temp->setNext(head);
    head = temp;
  }
}

//Print tree in infix

void printInfix(TreeNode* head){
  if (head == NULL){
    return;
  }
  printInfix(head->getLeft());
  cout << head->getValue() << " ";
  printInfix(head->getRight());
}

void printPrefix(TreeNode* head){
  if (head == NULL){
    return;
  }
  cout << head->getValue() << " ";
  printPrefix(head->getLeft());
  printPrefix(head->getRight());
  
}

void printPostfix(TreeNode* head){
  if (head == NULL){
    return;
  }
  printPostfix(head->getLeft());
  printPostfix(head->getRight());
  cout << head->getValue() << " ";
  
}
