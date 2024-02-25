#include <iostream>
class Stack {
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return (topIndex == -1);
    }

    bool isFull() {
        return (topIndex == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack overflow, cannot push " << value << std::endl;
            return;
        }
        topIndex++;
        data[topIndex] = value;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow, cannot pop" << std::endl;
            return;
        }
        topIndex--;
    }

    int top() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1; // Return a default value
        }
        return data[topIndex];
    }
};