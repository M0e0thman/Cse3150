#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "well_balanced.h"

TEST_CASE("Test well-balanced list generation") {
    SUBCASE("Test with small n") {
        CHECK_NOTHROW(generateWellBalancedList(1));
        CHECK_NOTHROW(generateWellBalancedList(2));
        CHECK_NOTHROW(generateWellBalancedList(3));
    }

    SUBCASE("Test with larger n") {
        CHECK_NOTHROW(generateWellBalancedList(5));
        CHECK_NOTHROW(generateWellBalancedList(10));
        CHECK_NOTHROW(generateWellBalancedList(20));
    }

    /*
    SUBCASE("Test with invalid n (negative)") {
        CHECK_THROWS_AS(generateWellBalancedList(-1), std::vector<int>);
    }
    */

    // Add more test cases as needed...
}
