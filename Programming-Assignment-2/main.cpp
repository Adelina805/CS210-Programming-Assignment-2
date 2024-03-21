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

    // Constructor
    Node(T *data) {
        this->data = data;
        leftChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
    }

    // Print
    void print() {
        data->print();
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
};

// Binary Search Tree Class: Container for Nodes
template<typename T>
class BinarySearchTree {
public:
    Node<T> *head;
    Node<T> *tail;
    int length;

    // Constructor
    BST(T *data) {
        Node<T> *newNode = new Node<T>(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
        length = 1;
    }

    // Destructor
    ~BST() {
        Node<T> *temp = head;
        Node<T> *nextNode;
        while (head) {
            nextNode = head->next;
            delete temp;
            temp = nextNode;
            if (temp == head) {
                break;
            }
        }
    }

    // Print the list
    void printList() {
        int number = 1; // number
        if (!head) { // if empty do nothing
            return;
        }
        Node<T> *temp = head; // start temp at head
        do {
            cout << number << ". "; // print number.
            temp->print(); // call node's print
            temp = temp->next; // go to next node
            number++; // increment number
        } while (temp != head); // stop if back to head
    }

    // Insert new process node at the end of list
    void insertProcess(T *data) {
        Node<T> *newNode = new Node<T>(data); // create new node
        newNode->prev = tail; // set newNodes prev to tail
        newNode->next = head; // set newNodes next to head
        tail->next = newNode; // set the tails next to newNode
        head->prev = newNode; // set the heads prev to newNode
        tail = newNode; // make tail equal newNode
        length++; // increment length
    }

    // Delete the process node at the given index
    void deleteProcess(Node<T> *node) {
        // if processNode is nullptr or not in the list, return
        if (!node || node->next == nullptr || node->prev == nullptr) {
            return;
        }
        // if deleting the head
        if (node == head) {
            head = head->next;
        }
        // update the next and prev pointers
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // if deleting the tail, update tail
        if (node == tail) {
            tail = node->prev;
        }
        delete node; // delete the node
        length--; // decrement length
    }

    // Check if the list is empty
    bool isEmpty() {
        return length == 0;
    }
};


// Process Class: the data that goes inside the node
class Process {
public:
    string processName;
    int totalTime;

    // Constructor
    Process(const string &processName, int totalTime) {
        this->processName = processName;
        this->totalTime = totalTime;
    }

    // Traverse and update the totalTime of each process node in the list
    void updateRunTime(CircularDLL<Process> &list, int quan) {
        Node<Process> *temp = list.head; // temporary node starting at head

        while (temp != nullptr) {
            temp->data->totalTime -= quan; // subtract quan from totalTime
            temp = temp->next; // go to the next node

            if (temp == list.head) { // if back to head, break the loop
                break;
            }
        }
    }

    // Traverse and delete any processes with totalTime less than or equal to zero
    void traverseAndDelete(CircularDLL<Process> &list) {
        Node<Process> *current = list.head; // start at the head of the list
        vector<Node<Process> *> nodesToDelete; // temporary list that stores nodes to be deleted

        while (current != nullptr) {
            Node<Process> *temp = current; // save the current node
            current = current->next; // go to the next node before potentially deleting

            if (temp->data->totalTime <= 0) {
                nodesToDelete.push_back(temp); // store node to be deleted in the temporary list
            }
            if (current == list.head) { // if back to the head, break the loop
                break;
            }
        }
        // delete the nodes stored after traversal is complete
        for (Node<Process> *node: nodesToDelete) {
            list.deleteProcess(node);
        }
    }

    // print name of process and the time left
    void print() {
        cout << "Process " << processName << " " << totalTime << "seconds" << endl;
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
    NewData = new Data(10);
    newBST->deleteElement(newData); // delete root
    newBST->print();
    NewData = new Data(45);
    newBST->deleteElement(newData); //delete with two children
    newBST->print();
    NewData = new Data(12);
    newBST->deleteElement(newData); //delete with one child
    newBST->print();
    NewData = new Data(10);
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