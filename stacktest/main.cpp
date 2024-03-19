#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    std::stack<int> stk;

public:
    void push(int value) {
        stk.push(value);
    }

    int pop() {
        int value = stk.top();
        stk.pop();
        return value;
    }

    int peek() {
        return stk.top();
    }

    bool isEmpty() {
        return stk.empty();
    }

    void countPosNeg() {

        stack<int> temp; // temporary stack

        int posCount = 0; // positive integer counter
        int negCount = 0; // negative integer counter

        // Count positive negative integers and put elements in the temp stack
        while (!isEmpty()) {
            int value = pop(); // get the current top value and remove
            temp.push(value); // put the value in temp

            if (value > 0) { // positive
                posCount++; // increment pos
            } else if (value < 0) { // negative
                negCount++; // increment neg
            }
        }

        // After counting, return elements back to original stack
        while (!temp.empty()) {
            int value = temp.top(); // get the current top value
            push(value); // push value to original stack
            temp.pop(); // remove top value
        }

        // Displays the number of positive and negative integers
        cout << "Positive integers: " << posCount << endl;
        cout << "Negative integers: " << negCount << endl;
    }

    void print() {
        std::stack<int> tempStack;

        // Transfer elements to tempStack and print them
        while (!isEmpty()) {
            int value = pop();
            tempStack.push(value);
            std::cout << value << " ";
        }

        // Transfer elements back to original stack
        while (!tempStack.empty()) {
            int value = tempStack.top();
            tempStack.pop();
            push(value);
        }

        std::cout << std::endl;
    }
};

int main() {
    Stack IntStack;

    // Initialize the stack
    int elements[10] = {2, -4, 5, -6, 1, -3, 7, 8, 0, 9};

    for (int i = 0; i < 10; i++) {
        IntStack.push(elements[i]);
    }

    // Print the stack
    std::cout << "Stack contents: ";
    IntStack.print();

    // Call countPosNeg function
    IntStack.countPosNeg();

    // Print the stack
    std::cout << "Stack contents: ";
    IntStack.print();

    return 0;
}
