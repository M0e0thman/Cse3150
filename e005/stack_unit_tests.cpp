#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack_1.h"

TEST_CASE("Stack Operations") {
    SUBCASE("Stack Copying") {
        const int my_stack_size = 6;
        stack<int> s = get_stack(my_stack_size);
        stack<int> t = s;
        CHECK(s == t);

        s.push(99);
        CHECK_FALSE(s == t);
    }

    SUBCASE("File Input and Sum Check") {
        const int my_stack_size = 6;
        stack<int> fileIntStack;
        pushElementsFromFile(fileIntStack, "input.txt");
        CHECK_NOTHROW(popAndCheckSum(fileIntStack));
        CHECK(fileIntStack.empty());
    }

    SUBCASE("Factorial Function") {
        SUBCASE("Factorial of 5") {
            CHECK(fact(5) == 120);
        }

        SUBCASE("Factorial of 10") {
            CHECK(fact(10) == 3628800);
        }
    }
}
