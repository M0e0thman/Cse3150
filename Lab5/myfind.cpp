#include <iostream>
#include <iomanip>  // For setw
#include "myfind.h"

bool myfind(const std::vector<int>& x, int v) {
    int small = 0, large = x.size() - 1;

    while (small <= large) {
        int mid = (small + large) / 2;
        if (v == x[mid]) return true;
        else if (v < x[mid]) large = mid - 1;
        else small = mid + 1;
    }

    return false;
}

#include <fstream>

void readMatrixFromFile(const std::string& filename, IntMatrix& matrix) {
    std::ifstream infile(filename);

    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    int rows, cols;
    infile >> rows >> cols;

    matrix.resize(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            infile >> matrix[i][j];
        }
    }

    infile.close();
}

void printMatrix(const IntMatrix& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << std::setw(2) << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------" << std::endl;
}
