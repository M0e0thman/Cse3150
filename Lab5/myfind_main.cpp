#include <iostream>
#include <vector>
#include "myfind.h"

void initAdjacencyMatrices(IntMatrix & Graph_minus_1,
                            IntMatrix & Graph_0,
                            IntMatrix & Graph_1) {
    readMatrixFromFile("Graph_minus_1.txt", Graph_minus_1);
    readMatrixFromFile("Graph_0.txt", Graph_0);
    readMatrixFromFile("Graph_1.txt", Graph_1);
}

void expensiveDigraphExactPaths(IntMatrix & D) {
    int n = D.size();

    for (int g = -1; g <= 1; ++g) {
        if (g == 0) continue;

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (D[i][k] == g && D[k][j] == g) {
                        D[i][j] = g;
                    }
                }
            }
        }
    }
}

int main() {
    IntMatrix Graph_minus_1, Graph_0, Graph_1;

    // Initialize adjacency matrices
    initAdjacencyMatrices(Graph_minus_1, Graph_0, Graph_1);

    // Run Expensive-Digraph-exact-paths algorithm
    expensiveDigraphExactPaths(Graph_minus_1);
    expensiveDigraphExactPaths(Graph_0);
    expensiveDigraphExactPaths(Graph_1);

    // Print the resulting matrices
    std::cout << "------------------ -----OUTPUT-------------" << std::endl;
    // Print matrices if needed
    printMatrix(Graph_minus_1);
    printMatrix(Graph_0);
    printMatrix(Graph_1);
    std::cout << "------------------" << std::endl;

    return 0;
}
