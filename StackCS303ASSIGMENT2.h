#pragma once
#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stack; // Vector to store stack elements

public:
    // Check if the stack is empty
    bool empty() const {
        return stack.empty();
    }

    // Push an element onto the stack
    void push(int value) {
        stack.push_back(value);
    }

    // Pop an element from the stack
    void pop() {
        if (empty()) {
            std::cout << "Stack is empty. Cannot pop.\n";
        }
        else {
            stack.pop_back();
        }
    }

    // Get the top element of the stack
    int top() const {
        if (empty()) {
            std::cout << "Stack is empty. No top element.\n";
            return -1;  // Returning -1 to indicate an error
        }
        return stack.back();
    }

    // Calculate the average of the stack elements
    double average() const {
        if (empty()) {
            std::cout << "Stack is empty. Cannot calculate average.\n";
            return -1;  // Returning -1 to indicate an error
        }
        double sum = 0;
        for (int value : stack) {
            sum += value;
        }
        return sum / stack.size();
    }

    // Size of the stack (number of elements)
    size_t size() const {
        return stack.size();
    }
};