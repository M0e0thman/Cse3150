#include <vector>
#include <iostream>

using namespace std;

// matrix multiplication
vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

vector<vector<int>> initialize_matrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        matrix[i][i] = 1; 
        if (i > 0) {
            matrix[i][i-1] = 1; 
        }
        if (i < n-1) {
            matrix[i][i+1] = 3 * (n + 1); 
        }
    }
    return matrix;
}
void normalize_matrix(vector<vector<int>>& matrix) {
    int n = matrix.size(); 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 1 && matrix[i][j] != 0) {
                matrix[i][j] = 0;
            }
        }
    }
}
