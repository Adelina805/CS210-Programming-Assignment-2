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

    // delete element recursively
    Node<T> *deleteElement(T *data) {
        root = deleteNode(root, data);
        if (root != nullptr) {
            numberOfElements--;
        }
    }
    // recursive function to delete a node
    Node<T> *deleteNode(Node<T> *node, T *data) {
        if (node == nullptr) { // if empty, return null
            return nullptr;
        }
        if (containsValue(node, data) == false) { // if not in tree
            cout << "Number does not exist " << endl;
            return node;
        }
        // search for node
        if (data->getValue() < node->getData()->getValue()) { // if less than, go down left branch, recursive
            node->setLeftChild(deleteNode(node->getLeftChild(), data));
        } else if (data->getValue() > node->getData()->getValue()) { // if greater than, go down right branch, recursive
            node->setRightChild(deleteNode(node->getRightChild(), data));
        } else {
            // Node with two children
            if (node->getLeftChild() != nullptr && node->getRightChild() != nullptr) {
                // cout << "two child ";
                Node<T> *replacement = findReplacement(node->getLeftChild());
                // cout << "replace with " << replacement->getData()->getValue() << " ";
                node->setData(replacement->getData());
                return node;
            }
            // Node with one child
            else if (node->getLeftChild() == nullptr) {
                Node<T> *temp = node->getRightChild();
                delete node;
                // cout << "no left child ";
                return temp;
            }
                // Node with one or no children
            else if (node->getRightChild() == nullptr) {
                Node<T> *temp = node->getLeftChild();
                delete node;
                // cout << "no right child or no child ";
                return temp;
            }
        }
        return node;
    }
    // find the maximum value in the given subtree
    Node<T>* findReplacement(Node<T> *node) const {
        while (node->getRightChild() != nullptr) {
            node = node->getRightChild();
        }
        return node;
    }
    // check if the value is in the binary search tree
    bool containsValue(Node<T>* node, T* data) {
        if (node == nullptr) {
            return false; // Value not found
        }
        if (data->getValue() < node->getData()->getValue()) {
            return containsValue(node->getLeftChild(), data); // Search left subtree
        } else if (data->getValue() > node->getData()->getValue()) {
            return containsValue(node->getRightChild(), data); // Search right subtree
        } else {
            return true; // Value found
        }
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
    void findKthElement(int k) const {
        if (k <= 0 || k > numberOfElements) {
            cout << "Number does not exist" << endl;
            return;
        }
        int count = 0;
        findKthHelper(root, count, k);
    }
    // recursive function for in-order traversal to find kth element
    void findKthHelper(Node<T>* node, int& count, int k) const {
        if (node == nullptr || count >= k) {
            return;
        }
        // Traverse left subtree
        findKthHelper(node->getLeftChild(), count, k);
        count++; // Increment count as current node is visited

        if (count == k) { // If kth element is reached, print it
            node->getData()->print();
            cout << endl;
            return;
        }
        // Traverse right subtree
        findKthHelper(node->getRightChild(), count, k);
    }

    // find the smallest element in the tree and print it
    void findSmallest() {
        Node<T>* smallest = findSmallestHelper(root);
        if (smallest != nullptr) {
            smallest->getData()->print();
            cout << endl;
        } else {
            cout << "empty" << endl;
        }
    }
    // recursive function to find the smallest element
    Node<T>* findSmallestHelper(Node<T>* node) const {
        if (node == nullptr || node->getLeftChild() == nullptr) {
            return node;
        }
        return findSmallestHelper(node->getLeftChild());
    }

    // find the biggest element in the tree and print it
    void findBiggest() {
        Node<T>* biggest = findBiggestHelper(root);
        if (biggest != nullptr) {
            biggest->getData()->print();
            cout << endl;
        } else {
            cout << "empty" << endl;
        }
    }
    // recursive function to find the biggest element
    Node<T>* findBiggestHelper(Node<T>* node) const {
        if (node == nullptr || node->getRightChild() == nullptr) {
            return node;
        }
        return findBiggestHelper(node->getRightChild());
    }

    // print all the elements stored in the BST in ascending order
    void sortAscending() {
        bool first = true;
        sortAHelper(root, first);
        cout << endl;
    }
    // recursive function for ascending sort
    void sortAHelper(Node<T>* node, bool& first) const {
        if (node == nullptr) { // if empty, return
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

    // print all the elements stored in the BST in descending order
    void sortDescending() {
        bool first = true;
        sortDHelper(root, first);
        cout << endl;
    }
    // recursive function for descending sort
    void sortDHelper(Node<T>* node, bool& first) const {
        if (node == nullptr) { // if empty, return
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
    cout << "List: "; // DELETE
    newBST->print();

    cout << "Smallest: "; // DELETE
    newBST->findSmallest();

    cout << "Biggest: "; // DELETE
    newBST->findBiggest();

    cout << "Delete (10): "; // DELETE
    newData = new Data(10);
    newBST->deleteElement(newData); // delete root
    newBST->print();

    cout << "Delete (45): "; // DELETE
    newData = new Data(45);
    newBST->deleteElement(newData); //delete with two children
    newBST->print();

    cout << "Delete (12): "; // DELETE
    newData = new Data(12);
    newBST->deleteElement(newData); //delete with one child
    newBST->print();

    cout << "Delete non existing num: "; // DELETE
    newData = new Data(1000);
    newBST->deleteElement(newData); // delete a number that doesn't exist. What will you print?
    newBST->print();

    cout << "1st: "; // DELETE
    newBST->findKthElement(1); //first element

    cout << "Last: "; // DELETE
    newBST->findKthElement(newBST->getnumberOfElements()); //last element

    cout << "3rd: "; // DELETE
    newBST->findKthElement(3); // some element in between

    cout << "Edge case: "; // DELETE
    newBST->findKthElement(7); // Edge case where item does not exist. What will you print?

    cout << "Smallest: "; // DELETE
    newBST->findSmallest();

    cout << "Biggest: "; // DELETE
    newBST->findBiggest();

    cout << "Ascend: "; // DELETE
    newBST->sortAscending();

    cout << "Descend: "; // DELETE
    newBST->sortDescending();

    return 0;
}