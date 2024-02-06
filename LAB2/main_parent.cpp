#include <iostream>

#include "fisher.h"

using namespace std;

int main(){
	int non_positive = 0;
	int non_negative = 0;

	int runs =0;
	int vec_size = 0;
	cout << "Enter number of runs: "<< endl;
	cin >> runs;

	cout << "Enter size " << endl;
	cin >> vec_size;
	simulation (runs, vec_size, non_positive, non_negative);
	cout<<  "non positive: " << non_positive << endl;
	cout<< "non negative: " << non_negative << endl; 
	cout << "non-positive=: " << (double)non_positive/runs << endl;
	cout << "non-negative=: " << (double)non_negative/runs << endl;
	return 0;
}
