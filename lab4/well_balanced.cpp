#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include "well_balanced.h"

void prefix_sum(std::vector<int>& arr) {
    int sum = 0;
    for (int& element : arr) {
        sum += element;
        element = sum;
    }
}

void generateWellBalancedList(int n) {
    std::vector<int> list(2 * n + 1, -1);
    for (int i = 0; i < n; ++i) {
        list[i] = 1;
    }

    std::srand(std::time(0));
    for (int i = 2 * n; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(list[i], list[j]);
    }

    prefix_sum(list);

    std::cout << "Original list: ";
    for (int i = 0; i < 2 * n + 1; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    int minDepth = list[2 * n];
    int valleyIndex = 2 * n;
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (list[i] < minDepth) {
            minDepth = list[i];
            valleyIndex = i;
        }
    }

    std::cout << "Prefix sums: ";
    for (int i = 0; i < 2 * n + 1; ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> balancedList(2 * n);
    for (int i = valleyIndex + 1; i < 2 * n + 1; ++i) {
        balancedList[i - valleyIndex - 1] = list[i];
    }
    for (int i = 0; i < valleyIndex; ++i) {
        balancedList[i + (2 * n - valleyIndex - 1)] = -list[i]; // Adjusted this line
    }

    std::cout << "Balanced list: ";
    for (int i = 0; i < 2 * n; ++i) {
        std::cout << balancedList[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 2 * n; ++i) {
        std::cout << (balancedList[i] == 1 ? "(" : ")");
    }
    std::cout << std::endl;
}
