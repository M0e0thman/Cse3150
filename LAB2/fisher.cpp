#include <iostream>
#include <cstdlib>
#include "fisher.h"
#include <time.h>
using namespace std;

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fisher_yates(int array[], const int length){
    srand(time(NULL));
    for(int i = 0; i < length; i++){
        int random_location = rand() % (length - i) + i;  // Corrected line
        swap(&array[i], &array[random_location]);
    }
}


int prefix_sum(int array[], int last){
    int sum = 0;
    for(int i =0; i < last; i++ ){
        sum += array[i];
    }
    return sum;
}
bool non_negative_prefix_sum(int array[], int length){
    bool is_non_negative = true;
    if (length == 1 && array[0] < 0) return is_non_negative = false;
    for(int i = 0 ; i < length ; i++){
      int sum = prefix_sum(array, i);
      if(sum < 0) {
        return is_non_negative = false;
      }
    }
    return is_non_negative;
}


bool non_positive_prefix_sum(int array[], int length){
  bool is_not_positive = true;
  if (length == 1 && array[0] > 0) return is_not_positive = false;
  for (int i = 0 ; i < length ; i++){
    int sum = prefix_sum(array, i);
    if (sum > 0){
      return is_not_positive = false;
    }
  }
  return is_not_positive;
}


void make_array(int array[], int length) {
    for (int i = 0; i < length/2; i++) {
        array[i] = 1;
    }
}

int simulation(const int n_tests,const  int n, int & non_pos, int & non_neg){
        int length = 2*n;
        int array[length];
        make_array(array, length);
        int total_non_positive = 0, total_non_negative = 0;
        for(int i = 0; i < n_tests; i++){
                fisher_yates(array, length);
                if(non_positive_prefix_sum(array, length)){
                        total_non_positive++;
                }
                if(non_negative_prefix_sum(array, length)){
                        total_non_negative++;
                }
        }
	non_pos = total_non_positive;
     non_neg = total_non_negative;

        return 0;
}
