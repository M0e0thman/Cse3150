#include "linked_list.h"
#include <iostream>

using namespace std;

struct node* build_new_linked_list(int total_new_elements) {
    if (total_new_elements == 0) {
        return nullptr;
    } else {
        struct node* root = new node;
        root->data = -1;
        struct node* linked_list = root;

        for (int i = 0; i < total_new_elements; i++) {
            linked_list->next = new node;
            linked_list->jumper = linked_list->next;  // Connect jumper 
            linked_list->data = i + 1;
            linked_list = linked_list->next;
        }
        linked_list->jumper = linked_list; 

        return root;
    }
}

int get_linked_list_data_item_value(struct node* start, int node_number, int total_elements) {
    if (node_number > total_elements) {
        return -1;
    } else {
        struct node* linked_list = start;

        for (int i = 0; i < node_number - 1; i++) {
            linked_list = linked_list->next;
        }

        return linked_list->data;
    }
}

void print_linked_list(struct node* start, int total_elements) {
    struct node* linked_list = start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

bool update_data_in_linked_list(struct node* start, int node_to_update, int update_val, int total_elements) {
    return true;
}

void print_linked_list_by_jumpers(struct node* first, int number_of_nodes) {
    struct node* linked_list = first;

    for (int i = 0; i < number_of_nodes; i++) {
        if (linked_list->jumper == linked_list) {
            break;
        }
        cout << linked_list->data << endl;
        linked_list = linked_list->jumper;
    }
}

void double_jumpers(struct node* first, int number_of_nodes) {
    struct node* linked_list = first;

    for (int i = 0; i < number_of_nodes; i++) {
        if (linked_list->jumper == linked_list) {
            break;
        }
        cout << linked_list->data << endl;
        linked_list = linked_list->jumper;
        linked_list = linked_list->jumper;
    }
}

int delete_linked_list(struct node* first, int number_of_nodes) {
    return 0;
}
