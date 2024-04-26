#include <iostream>
#include "matrix.cpp"

// print_matrix function 
void print_matrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n1 = 3;
    std::cout << "Test Case 1:" << std::endl;
    std::cout << "Graph size: " << n1 << std::endl;
    std::cout << "Expected output:" << std::endl;
    std::cout << "Matrix A^2:" << std::endl;
    std::vector<std::vector<int>> A1 = initialize_matrix(n1);
    std::vector<std::vector<int>> A1_squared = matrix_multiply(A1, A1);
    print_matrix(A1_squared);
    std::cout << std::endl;

    int n2 = 4;
    std::cout << "Test Case 2:" << std::endl;
    std::cout << "Graph size: " << n2 << std::endl;
    std::cout << "Expected output:" << std::endl;
    std::cout << "Matrix A^2:" << std::endl;
    std::vector<std::vector<int>> A2 = initialize_matrix(n2);
    std::vector<std::vector<int>> A2_squared = matrix_multiply(A2, A2);
    print_matrix(A2_squared);
    std::cout << std::endl;

    int n3 = 5;
    std::cout << "Test Case 3:" << std::endl;
    std::cout << "Graph size: " << n3 << std::endl;
    std::cout << "Expected output:" << std::endl;
    std::cout << "Matrix A^2:" << std::endl;
    std::vector<std::vector<int>> A3 = initialize_matrix(n3);
    std::vector<std::vector<int>> A3_squared = matrix_multiply(A3, A3);
    print_matrix(A3_squared);
    std::cout << std::endl;

    return 0;
}
