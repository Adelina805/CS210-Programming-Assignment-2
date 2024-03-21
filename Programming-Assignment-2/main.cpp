#include <iostream>
#include <sstream>
using namespace std;

// Node Class: Node for the BST
template<typename T>
class Node {
private:
    T *data;
    Node<T> *leftChild;
    Node<T> *rightChild;
    Node<T> *parent;

public:
    // Constructor
    Node(T *data) {
        this->data = data;
        leftChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
    }

    // Getters
    T* getData() const {
        return data;
    }

    Node<T>* getLeftChild() const {
        return leftChild;
    }

    Node<T>* getRightChild() const {
        return rightChild;
    }

    Node<T>* getParent() const {
        return parent;
    }

    // Setters
    void setData(T *data) {
        this->data = data;
    }

    void setLeftChild(Node<T> *leftChild) {
        this->leftChild = leftChild;
    }

    void setRightChild(Node<T> *rightChild) {
        this->rightChild = rightChild;
    }

    void setParent(Node<T> *parent) {
        this->parent = parent;
    }

    // Print
    void print() {
        data->print();
    }
};

// Binary Search Tree Class: Container for Nodes
template<typename T>
class BinarySearchTree {
private:
    Node<T> *root;
    int numberOfElements;
    int height;

public:
    // Constructor
    BinarySearchTree(T *data) {
        Node<T> *newNode = new Node<T>(data);
        root = newNode;
        numberOfElements = 1;
        height = 0;
    }

    // Destructor
    ~BinarySearchTree() {
        Node<T> *temp = root;
        Node<T> *nextNode;
        while (root) {
            nextNode = root->next;
            delete temp;
            temp = nextNode;
            if (temp == root) {
                break;
            }
        }
    }

    // Getters
    Node<T>* getRoot() const {
        return root;
    }

    int getnumberOfElements() const {
        return numberOfElements;
    }

    int getHeight() const {
        return height;
    }

    // Setters
    void setRoot(Node<T> *root) {
        this->root = root;
    }

    void setNumberOfElements(int numberOfElements) {
        this->numberOfElements = numberOfElements;
    }

    void setHeight(int height) {
        this->height = height;
    }

    // Print the BST (pre-order)
    void print() {
        if (!root) { // if empty do nothing
            return;
        }
        Node<T> *temp = root; // start temp at root
        do {
        } while (temp != root); // stop if back to head
    }

    // insert new element
    void insertElement(T *data) {

        balanceBST(); // balance
    }

    // delete new element
    void deleteElement(T *data) {

        balanceBST(); // balance
    }

    // Adelina's O(n) BST balance
    void balanceBST() {

    }

    // this method finds the element in the kth in
    // ascending order of elements in the tree and prints it. It returns nothing.
    // Consider edge cases and account for them.
    void findKthElement(int k) {

    }

    // this method finds the smallest element in the tree and prints it. It returns nothing.
    void findSmallest() {

    }

    // this method finds the biggest element in the tree and prints it. It returns nothing.
    void findBiggest() {

    }

    // this method prints all the elements stored in the BST in ascending order.
    // This method must be written recursively, not iteratively.
    // It returns nothing.
    void sortAscending() {

    }

    // this method prints all the elements stored in the BST in descending order.
    // This method must be written recursively, not iteratively.
    // This method returns nothing.
    void sortDescending() {

    }

    // Check if the BST is empty
    bool isEmpty() {
        return numberOfElements == 0;
    }
};


// Data Class: the data that goes inside the node
class Data {
private:
    int value;

public:
    // Constructor
    Data(int value) {
        this->value = value;
    }

    // Getter
    int getValue() const {
        return value;
    }

    // Setter
    void setValue(int newValue) {
        value = newValue;
    }

    // print the value
    void print() {
        cout << value << ", ";
    }
};

// Main program
int main() {
    int a[] = {10,45,23,67,89,34,12,99};
    Data* newData = new Data(a[0]);
    BinarySearchTree<Data>* newBST = new BinarySearchTree<Data>(newData);
    for(int i=1;i< (sizeof(a)/sizeof(int));i++)
    {
        newData = new Data(a[i]);
        newBST->insertElement(newData);
    }
    newBST->print();
    newBST->findSmallest();
    newBST->findBiggest();
    newData = new Data(10);
    newBST->deleteElement(newData); // delete root
    newBST->print();
    newData = new Data(45);
    newBST->deleteElement(newData); //delete with two children
    newBST->print();
    newData = new Data(12);
    newBST->deleteElement(newData); //delete with one child
    newBST->print();
    newData = new Data(10);
    newBST->deleteElement(newData); // delete a number that doesn't exist. What will you print?
    newBST->print();
    newBST->findKthElement(1); //first element
    newBST->findKthElement(newBST->getnumberOfElements()); //last element
    newBST->findKthElement(3); // some element in between
    newBST->findKthElement(7); // Edge case where item does not exist. What will you print?
    newBST->findSmallest();
    newBST->findBiggest();
    newBST->sortAscending();
    newBST->sortDescending();
    return 0;
};