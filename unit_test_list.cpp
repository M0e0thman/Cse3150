#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "linked_list.h"
using namespace std;

struct node * linked_list_1 = build_linked_list(0);
const int TEST_DELETE = 10;
struct node * linked_list_2 = build_linked_list(TEST_DELETE);
const int TEST_SMALL = 3;
struct node * linked_list_3 = build_linked_list(TEST_SMALL);


TEST_CASE("lisst build and delete"){
        CHECK(linked_list_2 != NULL);
        CHECK(linked_list_3 != NULL);

}
TEST_CASE("SUM OF ELEMENTS IN LIST"){
 	CHECK(sum_values_in_linked_list(linked_list_2,TEST_DELETE) == 45);
	CHECK(sum_values_in_linked_list(linked_list_3,TEST_SMALL) == 3);
}
TEST_CASE("Elements to Delete"){
        CHECK(delete_linked_list(linked_list_2,TEST_DELETE) == TEST_DELETE);
        CHECK(delete_linked_list(linked_list_3,TEST_SMALL) == TEST_SMALL);
	CHECK(delete_linked_list(linked_list_1, 0) == 0 );
}