#include <iostream>
#include "well_balanced.h"

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    generateWellBalancedList(n);

    return 0;
}
