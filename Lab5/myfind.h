#ifndef _MY_FIND_H_
#define _MY_FIND_H_

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> IntMatrix;

bool myfind(const std::vector<int>& x, int v);

void readMatrixFromFile(const std::string& filename, IntMatrix & matrix);

// Declaration for printMatrix
void printMatrix(const IntMatrix& matrix);

#endif

