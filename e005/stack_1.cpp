#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include "stack_1.h"

int fact(int n) {
    if (n <= 1)
        return 1;
    else {
        int rc = fact(n - 1);
        if (rc < 0) throw std::string("Overflow");
        return rc * n;
    }
}

stack<int> get_stack(const int n) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    return s;
}

stack<node> get_stack_node(const int n) {
    stack<node> s;

    string names[] = {"S. Ulam", "Alan Turing", "C. Babbage", "Grace Hopper", "Ada Lovelace"};

    for (int i = 0; i < n; i++) {
        if (i >= sizeof(names)) {
            node my_node;
            my_node.name = "Plato";
            my_node.number = i;

            s.push(my_node);
        } else {
            node my_node;
            my_node.name = names[i];
            my_node.number = i;

            s.push(my_node);
        }
    }

    return s;
}

// New function implementations
void pushElementsFromFile(stack<int>& myStack, const string& fileName) {
    ifstream input_file(fileName);
    if (!input_file.is_open()) {
        throw std::runtime_error("Unable to open file: " + fileName);
    }

    int value;
    while (input_file >> value) {
        myStack.push(value);
    }

    input_file.close();
}

void pushElementsFromFile(stack<node>& myStack, const string& fileName) {
    ifstream input_file(fileName);
    if (!input_file.is_open()) {
        throw std::runtime_error("Unable to open file: " + fileName);
    }

    node my_node;
    while (input_file >> my_node.name >> my_node.number) {
        myStack.push(my_node);
    }

    input_file.close();
}

void popAndCheckSum(stack<int>& myStack) {
    int sum = 0;
    while (!myStack.empty()) {
        sum += myStack.top();
        myStack.pop();
    }

    if (sum < 0) {
        throw std::runtime_error("Negative sum detected");
    }
}

void popAndCheckSum(stack<node>& myStack) {
    int sum = 0;
    while (!myStack.empty()) {
        sum += myStack.top().number;
        myStack.pop();
    }

    if (sum < 0) {
        throw std::runtime_error("Negative sum detected");
    }
}
