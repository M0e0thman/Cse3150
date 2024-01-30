#include <iostream>
#include <vector>

bool non_neg_prefix_sum(const std::vector<int>& arr) {
    int prefix_sum = 0;
    for (int num : arr) {
        prefix_sum += num;
        if (prefix_sum < 0) {
            return false;
        }
    }
    return true;
}

bool non_pos_prefix_sum(const std::vector<int>& arr) {
    int prefix_sum = 0;
    for (int num : arr) {
        prefix_sum += num;
        if (prefix_sum > 0) {
            return false;
        }
    }
    return true;
}

void runTests() {
    // Test Case 1: Non-negative prefix sums
    std::vector<int> lst1 = {1, -1, 1, -1};
    if (non_neg_prefix_sum(lst1)) {
        std::cout << "Test Case 1 Passed: Non-negative prefix sums" << std::endl;
    } else {
        std::cout << "Test Case 1 Failed: Non-negative prefix sums" << std::endl;
    }

    // Test Case 2: Non-negative prefix sums (negative case)
    std::vector<int> lst2 = {1, -1, -1, 1};
    if (!non_neg_prefix_sum(lst2)) {
        std::cout << "Test Case 2 Passed: Non-negative prefix sums (negative case)" << std::endl;
    } else {
        std::cout << "Test Case 2 Failed: Non-negative prefix sums (negative case)" << std::endl;
    }

    // Test Case 3: Non-positive prefix sums
    std::vector<int> lst3 = {1, -1, -1, 1};
    if (non_pos_prefix_sum(lst3)) {
        std::cout << "Test Case 3 Passed: Non-positive prefix sums" << std::endl;
    } else {
        std::cout << "Test Case 3 Failed: Non-positive prefix sums" << std::endl;
    }

    // Test Case 4: Non-positive prefix sums (negative case)
    std::vector<int> lst4 = {1, -1, 1, -1};
    if (!non_pos_prefix_sum(lst4)) {
        std::cout << "Test Case 4 Passed: Non-positive prefix sums (negative case)" << std::endl;
    } else {
        std::cout << "Test Case 4 Failed: Non-positive prefix sums (negative case)" << std::endl;
    }

    std::vector<int> lst5 = {};
    if (non_neg_prefix_sum(lst5) && non_pos_prefix_sum(lst5)) {
        std::cout << "Test Case 5 Passed: Empty Array" << std::endl;
    } else {
        std::cout << "Test Case 5 Failed: Empty Array" << std::endl;
}
std::vector<int> lst6 = {1, 1, 1, 1};
if (non_neg_prefix_sum(lst6) && !non_pos_prefix_sum(lst6)) {
    std::cout << "Test Case 6 Passed: All Positive Elements" << std::endl;
} else {
    std::cout << "Test Case 6 Failed: All Positive Elements" << std::endl;
}
std::vector<int> lst7 = {-1, -1, -1, -1};
if (!non_neg_prefix_sum(lst7) && non_pos_prefix_sum(lst7)) {
    std::cout << "Test Case 7 Passed: All Negative Elements" << std::endl;
} else {
    std::cout << "Test Case 7 Failed: All Negative Elements" << std::endl;
}
}

int main() {
    runTests();

    return 0;
}
