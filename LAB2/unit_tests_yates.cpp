#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "scrambler.h"

int nums_0[] = {};
int nums_1[] = {-5};
int nums_2[] = {35};
int nums_3[] = {2,-3,3,2};
int nums_4[] = {1,1,-1,1};
int nums_5[] = {-1,-1,-1,-1,1,1};

TEST_CASE("Test week1/2 functions") {
  SUBCASE("non-negative prefix sums") {
    CHECK(non_negative_prefix_sum(nums_0, 0) == true);
    CHECK(non_negative_prefix_sum(nums_2, 1) == true);
    CHECK(non_negative_prefix_sum(nums_4, 4) == true);
    CHECK(non_positive_prefix_sum(nums_0, 0) == true);
    CHECK(non_positive_prefix_sum(nums_2, 1) == false);
    CHECK(non_positive_prefix_sum(nums_4, 4) == false);
  }

  SUBCASE("non-positive prefix sums") {
    CHECK(non_positive_prefix_sum(nums_1, 1) == true);
    CHECK(non_positive_prefix_sum(nums_3, 4) == false);
    CHECK(non_positive_prefix_sum(nums_5, 6) == true);
    CHECK(non_negative_prefix_sum(nums_1, 1) == false);
    CHECK(non_negative_prefix_sum(nums_3, 4) == false);
    CHECK(non_negative_prefix_sum(nums_5, 6) == false);
  }
}
