#ifndef __SCRAMBLER_H
#define __SCRAMBLER_H


int prefix_sum(int array[], int last); 
bool non_negative_prefix_sum(int array[], int length);
bool non_positive_prefix_sum(int array[], int length);
void swap (int *a, int *b);
void fisher_yates(int array[], const int length);
void make_array(int array[], int length);
int simulation(int n, int num_tests, int & non_pos, int & non_neg);

#endif
