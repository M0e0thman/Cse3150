#ifndef STACK_1_H
#define STACK_1_H
#include <stack>

using namespace std;

struct node {
    string name;
    int number;
};

int fact(int n); // Declaration for the fact function

stack<int> get_stack(const int n);
stack<node> get_stack_node(const int n);

// New function declarations
void pushElementsFromFile(stack<int>& myStack, const string& fileName);
void pushElementsFromFile(stack<node>& myStack, const string& fileName);
void popAndCheckSum(stack<int>& myStack);
void popAndCheckSum(stack<node>& myStack);

#endif // STACK_1_H
