# Binary trees and Splay trees

In this assignment, we will implement two distinct data structures. One is a simple Binary Search Tree and the second one is a Splay tree.

All the information you need regarding these two data structures can be found in your textbook (Algorithm Analysis and Design, Chapter 4).


# Step 1 - Setup

The `main.cpp` file provided with the assignment will be used at the end for testing the performances of the data structures. For the initial debugging phase I suggest you create a simple `main.cpp` file with the minimal instructions you need for verifying that the implemented structures are working correctly.

### Suggestion
keep your code hierarchy simple. Ideally, you should always be able to compile everything with something like `g++ main.cpp -o main`

# Step 2 - Implementing the Binary tree

Use the draft provided in `BinaryTree.h` for implementing a binary search tree. The comments provided in the file should guide you through the definition of all the required variables/functions.


### Suggestion
Simplify your code by creating simpler recursive functions. For example, instead of creating a function `insert(int val)` that accepts only the key, define a function `insert(int val, Node* node)` that also accepts the node from which starting the insertion. This way you can implement only one function instead of two by using the recursive call directly on `insert`.

### Suggestion
The inorder visit can be a powerful debugging tool. Remember that in a Binary search tree, as well as in the Splay tree, an inorder visit should always return the keys stored in the tree in ascending order. If this is not happening, it means that something is wrong with your insert/splay implementations.

### Suggestion
Every time you perform a `search` and an `insert` in a Splay tree you need to return the last (non null) node touched. You can implement this in the Binary search tree as well. This way we will reuse the same functions for implementing the `insert` and `search` in the Splay tree.  



# Step 3 - Implementing the Splay tree

Use the draft provided in `SplayTree.h` for implementing a Splay tree. The comments provided in the file should guide you through all the required variables/functions you will need to define.

#### Suggestion
There are three types of rotations in the Splay tree (zig, zig zig, zig zag). Each of them can be performed on the left or on the right. I strongly encourage you to define six distinct functions for implementing each combination (zig_left, zig_right, zig_zig_left, zig_zig_right, etc.)

### Suggestion
If you have implemented the `insert` and `search` functions in the Binary tree as suggested, you should be able to reuse your code. Ideally, your functions here should be something like

```c++
  bool insert(int key){
    Node* last = BinaryTree::insert(key, getRoot());
    splay(last)
  }
```

```c++
  bool search(int key){
    Node* last = BinaryTree::search(key, getRoot());
    splay(last)
  }
```

# Step 4 - Submission

Assuming that you have implemented everything and debugged your code you can go back to the `main.cpp` file provided with the assignment and fill the missing lines identified by `TODO` (these should be only simple calls to your data structure functions).

Copy and paste here the result print by your inorder function.

Time for building 4.55e-05
Time for searches 7.39e-05
34 194 701 1443 2090 2699 3683 4256 8020 9484 10624 11512 12950 13806 14242 15441 15963 16227 16603 17139 18357 19746 19966 20385 20860 
21340 22497 24527 25743 25890 25951 27498 27755 28177 28695 29049 31618 32938 33166 34675 34767 38160 40526 41478 42522 44219 47696 47916 48270 48515 52310 52465 54404 54624 54671 56174 57463 59170 59426 59516 59586 59841 60977 63790 67805 68232 69339 69422 70169 70355 70803 72321 73541 73848 75686 77724 78077 83926 85762 86073 86798 91662 92192 92368 92798 94216 94485 94519 94947 95622 95830 96696 97035 
97071 97170 97298 98787 98970 99411 9948