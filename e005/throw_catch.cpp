#include <iostream>
#include "stack_1.h"

// Assuming QueueElement is a struct or class
struct QueueElement {
    // Members and methods of QueueElement
    int value;  // For example
};

int fact(int n) {
    if (n <= 1)
        return 1;
    else {
        int rc = fact(n - 1);
        if (rc < 0) throw std::string("Overflow");
        return rc * n;
    }
}

int main() {
    try {
        // Stack operations
        stack<int> intStack;
        pushElementsFromFile(intStack, "input.txt");
        popAndCheckSum(intStack);

        // Queue operations
        queue<QueueElement> myQueue;
        pushElementsFromFile(myQueue, "input.txt");
        dequeueAndCheckSum(myQueue);

        // Factorial calculation
        int ten_fact = fact(10);
        std::cout << "Result is: " << ten_fact << std::endl;

        int x = fact(20);
        std::cout << "Result is: " << x << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
