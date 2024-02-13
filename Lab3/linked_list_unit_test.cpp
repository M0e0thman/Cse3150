// linked_list_unit_test.cpp
#include <iostream>
#include "linked_list.h"

using namespace std;

void run_linked_list_unit_test() {
    cout << "Test 1: Building a linked list with 3 elements" << endl;
    struct node* linked_list_three_elt = build_new_linked_list(3);
    print_linked_list(linked_list_three_elt, 3);
    cout << "---------------------------------------------" << endl;

    cout << "Test 2: Getting data item values from the linked list" << endl;
    int value_at_node_2 = get_linked_list_data_item_value(linked_list_three_elt, 2, 3);
    cout << "Value at node 2: " << value_at_node_2 << endl;
    cout << "---------------------------------------------" << endl;

    cout << "Test 3: Performing double jumpers on the linked list" << endl;
    double_jumpers(linked_list_three_elt, 3);
    cout << "---------------------------------------------" << endl;

    // Clean up
    delete_linked_list(linked_list_three_elt, 3);
}
