#include "BinaryTree.h"

//class implementing the Splay tree
class SplayTree : public BinaryTree{

  //extending the Binary you raughly have everything you need

public:

  //TODO:

  //a new function for inserting a node into the tree
    //here you can call an insert from the binary tree
    //additionally you have to perform splay's
  Node *insert(int key){
    Node* last = BinaryTree::insert(key, getRoot());
    if (last != NULL)
      splay(last);
    return last;
  }
  /*void rotate_left(Node* x){
    Node *y = NULL;
    y = x->getRight();
    if (y == NULL){
      return;
    }
    x->setRight(y->getLeft());
    if (y->getLeft() != NULL){
      y->getLeft()->setParent(x);
    }
    y->setParent(x->getParent());
    if (x->getParent()==NULL)
      setRoot(y);
    else if (x == x->getParent()->getLeft())
      x->getParent()->setLeft(y);
    else{
      x->getParent()->setRight(y);
    }
    x->setLeft(x);
    x->setParent(y);
  }*/
  void rotate_left(Node* x){//rewriting this fctn
    Node *y = NULL;
    y = x->getRight();
    if (y != NULL){
      x->setRight(y->getLeft());
      if (y -> getLeft()){
        y->getLeft()->setParent(x);
      }
      y->setParent(x->getParent());
    }
    if(x->getParent() == NULL){
      setRoot(y);
    }
    else if(x == x->getParent()->getLeft()){
      x->getParent()->setLeft(y);
    }
    else{
      x->getParent()->setRight(y);
    }
    if(y!=NULL){
      y->setLeft(x);
      x->setParent(y);
    }
  }






  /*void rotate_right(Node* y){
    if (y == NULL){
      return;
    }
    Node *x = NULL;
    x = y->getLeft();
    if (x == NULL){ //fix for segfault. May not be ok if y is leftmost
      return;
    }
    y->setLeft(x->getRight());
    if(x->getRight() != NULL){
      x->getRight()->setParent(y);
    }
    x->setParent(y->getParent());
    if(y->getParent()==NULL){
        setRoot(x);
    }
    else if( y == y->getParent()->getLeft()){//changed
      y->getParent()->setLeft(x);
    }
    else{
      y->getParent()->setRight(x);//changed
    }
    y->setRight(y);
    y->setParent(x);
  }*/
  void rotate_right(Node* x){
    Node *y = NULL;
    y = x->getLeft();
    if (y!=NULL){
      x->setLeft(y->getRight());
      if(y->getRight()!=NULL){
        y->getRight()->setParent(x);
      }
      y->setParent(x->getParent());
    }
    if(x->getParent() == NULL){
      setRoot(y);
    }
    else if(x == x->getParent()->getLeft()){
      x->getParent()->setLeft(y);
    }
    else{
      x->getParent()->setRight(y);
    }
      if (y != NULL)
        y->setRight(x);
      x->setParent(y);

  }
  //a new function for searching a node into the tree
    //here you can call a search from the binary tree
    //additionally you have to perform splay's
  Node * search(int key){
    Node* last = BinaryTree::search(key, getRoot());
    if (last != NULL)
      splay(last);
    return last;
  }
  //a new function for performing splay
  void splay(Node* last){
    if (last == NULL){
      return;
    }
    int timeout_counter = 0;
   while (last->getParent() != NULL){
    Node* parent = last->getParent();
    if(last->getParent()->getParent() == NULL){
      /*if (last == getRoot()||last->getParent()==NULL){
          return;
          break;
        }*/
      if (last == last->getParent()->getLeft()){
        zig_right(last);
        break;
      }
      else {
        zig_left(last);
        break;
      }
    }
    else if (last == last->getParent()->getLeft() && last->getParent() == last->getParent()->getParent()->getLeft()){
      zig_zig_left(last);
    }
    else if(last == last->getParent()->getRight() && last->getParent() == last->getParent()->getParent()->getRight()){
      zig_zig_right(last);
    }
    else if (last == last->getParent()->getRight() && last->getParent()->getParent()->getLeft()== last->getParent()){
        zig_zag_left(last);
    }
    else{
        zig_zag_right(last);
    }
      /*if (timeout_counter == 1000){
        cout << "timeout counter reached 1000. exiting loop."<<endl;
        break;
      }
      timeout_counter++;*/
   }
   //inorder(getRoot());
  }
  //two new functions for performring a zig zig splay (on the left and on the right)
  void zig_zig_left(Node* last){
    rotate_right(last->getParent()->getParent());
    rotate_right(last->getParent());
   }
   void zig_zig_right(Node* last){
    rotate_left(last->getParent()->getParent());
    rotate_left(last->getParent());
   }

  //two new functions for performring a zig zag splay (on the left and on the right)

  void zig_zag_left(Node* last){
    rotate_left(last->getParent());
    rotate_right(last->getParent());
  }
  void zig_zag_right(Node* last){
    rotate_right(last->getParent());
    rotate_left(last->getParent());
  }
  //two new functions for performring a zig splay (on the left and on the right)
  
  void zig_left(Node* last){
    if( last->getParent()!= NULL)
      rotate_left(last->getParent());
    
  } 
  void zig_right(Node* last){
    if( last->getParent()!= NULL)
      rotate_right(last->getParent());
  }
};
