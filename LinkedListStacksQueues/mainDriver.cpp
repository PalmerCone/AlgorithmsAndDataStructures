#include <iostream>
#include "List.h"
#include "Node.h"
#include "ListStack.h"
#include "ListQueue.h"
using namespace std;
int main(){
   ListStack<char> stack3;
  char c[] = {'m', 'l', 'k', 'j', 'i', 'h', 'e', 'c', 'b', 'a', 'p', 'z'};
  for(int i = 0; i < 12; i++){
    stack3.push(c[i]);
  }
  stack3.print("list");

}