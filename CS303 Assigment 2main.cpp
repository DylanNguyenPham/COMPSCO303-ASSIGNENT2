// CS303 Assigment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Singlelink.h"
#include "Stack.h"
int main() {
    Single_Linked_List<int> list;
    Stack stack;

    cout << "Initial list (empty):\n";
    print_list(list);

    cout << "\nAfter push_front(10):\n";
    list.push_front(10);
    print_list(list);

    cout << "\nAfter push_front(20):\n";
    list.push_front(20);
    print_list(list);

    cout << "\nAfter push_back(30):\n";
    list.push_back(30);
    print_list(list);

    cout << "\nAfter push_back(40):\n";
    list.push_back(40);
    print_list(list);

    cout << "\nAfter inserting 25 at index 2:\n";
    list.insert(2, 25);
    print_list(list);

    cout << "\nAfter removing index 2 (25 should be gone):\n";
    list.remove(2);
    print_list(list);

    cout << "\nAfter pop_front():\n";
    list.pop_front();
    print_list(list);

    cout << "\nAfter pop_back():\n";
    list.pop_back();
    print_list(list);

    cout << "\nIs the list empty? " << (list.empty() ? "Yes" : "No") << "\n";

    cout << "\nAfter removing all elements:\n";
    list.pop_front();
    list.pop_front();
    print_list(list);
    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << "\n" << "\n";


    // 1) Create a stack object
    cout << "Stack created.\n";

    // 2) Check if the stack is empty
    cout << "Is the stack empty? " << (stack.empty() ? "Yes" : "No") << "\n";

    // 3) Insert some integer values onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    std::cout << "Inserted values 10, 20, 30, 40 into the stack(40 is top, 10 is bottom).\n";

    // 4) Remove an element from the stack
    stack.pop();
    cout << "Removed top element from the stack.\n";

    // 5) Find the top of the stack
    int topValue = stack.top();
    if (topValue != -1) {
        cout << "Top of the stack: " << topValue << "\n";
    }

    // 6) Find the average value of the stack elements
    double avgValue = stack.average();
    if (avgValue != -1) {
        cout << "Average value of the stack: " << avgValue << "\n";
    }

    return 0;

}

