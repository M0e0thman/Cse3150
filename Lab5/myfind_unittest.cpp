#include <iostream>
#include <cassert>

#include "myfind.h"

void runTests() {
    IntMatrix Graph_m1, Graph_0, Graph_1;

    // Test Matrix Initialization and Algorithm Correctness
    initAdjacencyMatrices(Graph_m1, Graph_0, Graph_1);

    expensiveDigraphExactPaths(Graph_m1);
    expensiveDigraphExactPaths(Graph_0);
    expensiveDigraphExactPaths(Graph_1);

    // Assertions
    assert(Graph_m1[0][1] == -1);
    assert(Graph_0[2][3] == 0);
    assert(Graph_1[4][5] == 1);

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    runTests();

    return 0;
}
