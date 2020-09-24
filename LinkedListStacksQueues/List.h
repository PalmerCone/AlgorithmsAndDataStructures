/*
 * Name:Palmer Cone
 * Date Submitted:
 * Lab Section:001
 * Assignment Name:Lab 1
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
    start=nullptr;
    mySize=0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>//check this
List<T>::~List(){
    
    for (int i=0;i<mySize;i++){
        removeEnd();
    }
}

//Return the size of this list
template <class T>
int List<T>::size(){
    int count = 0;
    Node<T> * iterator = start;
    if(iterator==nullptr){
        return 0;
    }
    
    while(iterator != nullptr){
      iterator = iterator->next;
      count++;
    }
    return count;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
    if (size()==0)
        return true;
    else
        return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
    Node<T> *newNode=new Node<T>(value);//check if right
    if (start!=nullptr)
        newNode->next=start;
    start=newNode;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
    cout<<"Size: "<<size()<<endl;
    if(size()==0){
         insertStart(value);
    }
    else{
        Node<T> *newNode=new Node<T>(value);
        Node<T> * iterator = start;
        while (iterator->next != nullptr){
            iterator=iterator->next;//changed
        }
        iterator->next=newNode;
    }
     
     
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
    Node<T> * iterator = start;
    Node<T> *newNode=new Node<T>(value);
    if (j==0){//||size()==0
        insertStart(value);
    }
    else{
        for (int i=1;i<j;i++){
            if (iterator->next!=nullptr)
                iterator=iterator->next;//changed
        }
        if (iterator->next==nullptr){
            iterator->next=newNode;
        }
        else{
            newNode->next=iterator->next;
        
            iterator->next=newNode;
        }
    }
}

//Remove node at start
//Make no other changes to list
template <class T>//working
void List<T>::removeStart(){
    Node<T> * iterator = start->next;
    delete start;
    start=iterator;
}

//Remove node at end
//Make no other changes to list
template <class T>//working
void List<T>::removeEnd(){
    Node<T> * iterator = start;
    Node<T> * iterator2 = start;
    while (iterator->next->next != nullptr){//possible error
        iterator=iterator->next;
        iterator2=iterator2->next;
    }
    iterator=iterator->next;
    iterator2->next=nullptr;
    delete iterator;
    /*Node<T> * iterator = start;
    while (iterator->next != nullptr){//possible error
        iterator=iterator->next;
    }
    delete iterator;*/
    
    
}

//Remove node at position j
//Make no other changes to list
template <class T>//working
void List<T>::removeAt(int j){
    Node<T> * iterator = start;
    if (j==0){
        removeStart();
    }
    else if (j<=size()){
        for (int i=1;i<j;i++){
            iterator=iterator->next;//changed
        }
        Node<T> * iterator2 = iterator->next;
        iterator->next=iterator->next->next;
        delete iterator2;
    }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>//works
T List<T>::getFirst(){
    if (start==nullptr){
        return T();
    }
    else{
        return start->value;
    }
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
    if (start==nullptr){
        return T();
    }
    Node<T> * iterator = start;
    while (iterator->next != nullptr){
        iterator=iterator->next;//changed
    }
    return iterator->value;//May not be able to get value this way

}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
    if (start==nullptr){
        return T();
    }
    Node<T> * iterator = start;
    for (int i=0;i<j;i++){
            iterator=iterator->next;
    }
    return iterator->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
    Node<T> * iterator = start;
    int count=0;
    while (iterator != nullptr){
        
        if (key==iterator->value){
            return count;
        }
        count++;
        iterator=iterator->next;//changed
    }
    return -1;
}
