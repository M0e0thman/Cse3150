// main.cpp
#include <iostream>
#include "linked_list.h"

using namespace std;

void run_linked_list_unit_test();  // Declaration

int main() {
    struct node* linked_list_one_elt = build_new_linked_list(1);
    print_linked_list(linked_list_one_elt, 1);

    struct node* linked_list_five_elt = build_new_linked_list(5);
    print_linked_list(linked_list_five_elt, 5);

    print_linked_list_by_jumpers(linked_list_five_elt, 5);

    delete_linked_list(linked_list_one_elt, 1);
    delete_linked_list(linked_list_five_elt, 5);

    run_linked_list_unit_test();  // Corrected function name

    return 0;
}
