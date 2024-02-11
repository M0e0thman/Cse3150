#include <iostream>
#include <fstream>
#include <stack>
#include "stack_1.h"

using namespace std;

int main() {
    stack<int> intStack;
    stack<node> nodeStack;

    // Read integers
    pushElementsFromFile(intStack, "input.txt");

    try {
        // Pop integers 
        popAndCheckSum(intStack);
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    // Read nodes 
    pushElementsFromFile(nodeStack, "input.txt");

    try {
        popAndCheckSum(nodeStack);
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
