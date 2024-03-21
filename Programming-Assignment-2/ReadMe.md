# CS210-Programming-Assignment-2

For this assignment you are required to develop a Binary Search Tree Data Structure.
Your program will have 3 classes.

1. Node (Reusable Data Independent Class)
   a. This class should be a template
   b. Private variables are:
   i. T* data
   ii. Node<T>* leftChild
   iii. Node<T>* rightChild
   iv. Node<T>* parent
   c. This class must have a constructor, it can be overloaded if you choose to
   d. This class must have a print method.
   e. Since all variables are private, to access them, you must write set & get
   methods for each variable:
   i. Set methods have one argument and perform assignment to the
   variable
   ii. Get method returns the value of the variable to the method calling it.
   Set the appropriate return type.

2. Binary Search Tree (Reusable Data Independent Class)
   a. This class should be a template
   b. Private variables are:
   i. Node<T>* root
   ii. int numberOfElements
   iii. int height
   c. Since all variables are private, to access them, you must write set & get
   methods for each variable:
   i. Set methods have one argument and perform assignment to the
   variable
   ii. Get method returns the value of the variable to the method calling it.
   Set the appropriate return type.
   d. This class must have a constructor, it can be overloaded if you choose to
   e. This class must have a destructor that is explicitly written.
   f. This class must have a print method – The print method must traverse the tree
   in “PRE ORDER” and print the elements that way. The actual data being printed
   however, cascades upwards and you cannot make it data class dependent.
   g. This class must also contain the following methods:
   i. findKthElement(int k) - this method finds the element in the kth in
   ascending order of elements in the tree and prints it. It returns nothing.
   Consider edge cases and account for them.
   ii. findSmallestElement() - this method finds the smallest element in the
   tree and prints it. It returns nothing.
   iii. findBiggestElement() - this method finds the biggest element in the tree
   and prints it. It returns nothing.
   iv. sortAscending() - this method prints all the elements stored in the BST
   in ascending order. It returns nothing.
   This method must be written recursively, not iteratively.
   This method returns nothing.
   v. sortDescending() - this method prints all the elements stored in the BST
   in descending order.
   This method must be written recursively, not iteratively.
   This method returns nothing.

3. Data
   a. Private Variable:
   i. int value
   b. Since all variables are private, to access them, you must write set & get
   methods for each variable:
   i. Set methods have one argument and perform assignment to the
   variable
   ii. Get method returns the value of the variable to the method calling it.
   Set the appropriate return type.
   c. This class must have a constructor, it can be overloaded if you choose to
   d. This class must have a print method.

Devise an algorithm to convert a BST to a balanced BST, ignoring the insert and delete
methods, your algorithm must run to an O(n) time.

Expected Output :
10, 45, 23, 12, 34, 67, 89, 99
4
10
99
45, 23, 12, 34, 67, 89, 99
34, 23, 12, 67, 89, 99
34, 23, 67, 89, 99
Number does not exist
34, 23, 67, 89, 99
23
99
67
Number does not exist
23
99
23, 34, 67, 89, 99
99, 89, 67, 34, 23