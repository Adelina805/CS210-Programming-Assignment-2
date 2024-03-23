#include <iostream>
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

    // Destructor
    ~Node() {
        delete data;
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
    void setData(T *newData) {
        this->data = newData;
    }

    void setLeftChild(Node<T> *newLeftChild) {
        this->leftChild = newLeftChild;
    }

    void setRightChild(Node<T> *newRightChild) {
        this->rightChild = newRightChild;
    }

    void setParent(Node<T> *newParent) {
        this->parent = newParent;
    }

    // Print
    void print() {
        if (data != nullptr) {
            data->print();
        }
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
        deleteBST(root);
    }

    // Getters
    Node<T> *getRoot() const {
        return root;
    }

    int getnumberOfElements() const {
        return numberOfElements;
    }

    int getHeight() const {
        return height;
    }

    // Setters
    void setRoot(Node<T> *newRoot) {
        root = newRoot;
    }

    void setNumberOfElements(int num) {
        numberOfElements = num;
    }

    void setHeight(int newHeight) {
        height = newHeight;
    }

    // insert element recursively
    void insertElement(T *data) {
        root = insertElementBST(root, data);
        numberOfElements++;
    }

    Node<T> *insertElementBST(Node<T> *node, T *data) {
        if (node == nullptr) { // if empty, return node
            return new Node<T>(data);
        }
        if (data->getValue() < node->getData()->getValue()) { // if smaller than parent, left child
            node->setLeftChild(insertElementBST(node->getLeftChild(), data));
        }
        else if (data->getValue() > node->getData()->getValue()) { // if larger than parent, right child
            node->setRightChild(insertElementBST(node->getRightChild(), data));
        }
        return node;
    }

    // delete element
    void deleteElement(T *data) {

    }

    // print entire BST recursively
    void print() const {
        bool first = true;
        printBST(root, first);
        cout << endl;
    }
    // pre-order print
    void printBST(Node<T> *node, bool& first) const {
        if (node == nullptr) {
            return; // if null node
        }
        if (!first) {
            cout << ", "; // print comma if not the last element
        }
        node->getData()->print(); // print node value
        first = false;
        printBST(node->getLeftChild(), first); // print left
        printBST(node->getRightChild(), first); // print right
    }

    // find the element in the kth in ascending order of elements in the tree and print it
    void findKthElement(int k) {

    }

    // find the smallest element in the tree and print it
    void findSmallest() {

    }

    // find the biggest element in the tree and print it
    void findBiggest() {

    }

    // print all the elements stored in the BST in ascending order
    void sortAscending() {
        bool first = true;
        sortAHelper(root, first);
        cout << endl;
    }

    // print all the elements stored in the BST in descending order
    void sortDescending() {
        bool first = true;
        sortDHelper(root, first);
        cout << endl;
    }

    // recursive function for ascending sort
    void sortAHelper(Node<T>* node, bool& first) const {
        if (node == nullptr) {
            return;
        }
        sortAHelper(node->getLeftChild(), first); // print left
        if (!first) {
            cout << ", "; // print comma if not the last element
        }
        node->getData()->print(); // print node value
        first = false;
        sortAHelper(node->getRightChild(), first); // print right
    }

    // recursive function for descending sort
    void sortDHelper(Node<T>* node, bool& first) const {
        if (node == nullptr) {
            return;
        }
        sortDHelper(node->getRightChild(), first); // print right
        if (!first) {
            cout << ", "; // print comma if not the last element
        }
        node->getData()->print(); // print node value
        first = false;
        sortDHelper(node->getLeftChild(), first); // print left
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
    void print() const {
        cout << value;
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
}