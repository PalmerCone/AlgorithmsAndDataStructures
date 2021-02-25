#include <stdlib.h>
#include <iostream>

using namespace std;

class Node{

  //Each node should have

  //- pointer to the parent node
Node* parent;
  //- pointer to left child
Node* left;
  //- pointer to right child
Node* right;
  //- int for storing the key value
int key;
public:
  //constructor
  //remember to always inizialize pointers to NULL
  Node(int val){
  parent = NULL;
  right = NULL;
  left = NULL;
  key = val;
  }
  Node(){
  parent = NULL;
  right = NULL;
  left = NULL;
  }
  //~Node();
  
  //getter and setter for nodes and value
  void setValue(int val){
    key = val;
  }
  int getValue(){
    return key;
  }
  Node* getParent(){
    return parent;
  }
  void setParent(Node* parent){
    this->parent = parent;
  }
  void setLeft(Node* left){
    this->left = left;
  }
   Node* getLeft(){
    return left;
  }

  void setRight(Node* right){
    this->right = right;
  }
   Node* getRight(){
    return right;
  }
};

class BinaryTree{

protected:
  //A tree should store only its root.
  Node* root;

public:
  //functions required

  //- constructor
  BinaryTree(){root = NULL;}
  ~BinaryTree(){delete root;}
  //- getter setter root
void setRoot(Node* root){ //maybe use NEW
  this->root = root;
}
Node* getRoot(){
  return root;
}
  //- a function for printing the inorder visit of the tree
void inorder(Node *r){
  if (r == NULL){
    return;
  }
  if (r->getLeft() != NULL){
    inorder(r->getLeft());
  }
  cout << r->getValue() << " ";
  if (r->getRight() != NULL){
    inorder(r->getRight());
  }
}
  //- a function for inserting a new value in the tree
  Node* insert(int val, Node* root){
    Node* newNode = NULL;
    if(root ==NULL){
      newNode = new Node(val);
      setRoot(newNode);
      return newNode;
    }
    newNode = root; //check this. Should be the root of tree
    Node* parent = NULL; 
    while (newNode != NULL){
      parent = newNode;
      if (val == newNode->getValue()){
        return newNode;//The case that the value is already in the function
      }
      if (newNode->getValue() > val){
        newNode = newNode->getLeft();
      }
      else {
        newNode = newNode->getRight();
      }
    }
    newNode = new Node(val);
    newNode->setParent(parent);

    if (parent->getValue() > newNode->getValue()){
      parent->setLeft(newNode);
    }
    else {
      parent->setRight(newNode);
    }
    return newNode;
  }
  //- a function for searching a value in the tree.
  Node * search(int key, Node* root){
    Node* node = root;
    while((node->getValue() != key) && node != NULL){
      if(node->getValue() > key){
        if(node->getLeft()!= NULL){
          node = node->getLeft();
        }
        else
          return node;
      }
      else{
        if (node->getRight() != NULL)
          node = node->getRight();
        else
          return node;
      }
    }
    return node;
  }
};
