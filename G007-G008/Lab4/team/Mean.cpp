#include "Mean.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;



Mean::Mean() {
	this -> mean = 0;
	this -> input_size = 0;
	cout << "Mean Class instantiated" << endl;
	
}

Mean::~Mean() {
	cout << "Mean class deleted" << endl;
	
}

float Mean::get_mean() {
	return this -> mean;
	
}

unsigned int Mean::get_size() {
	return this -> input_size;
	
}

float Mean::calculated(vector<int> input_set) {
	
	this -> input_size = input_set.size();
	
	int sum {};
	for(int i = 1; i <= input_size; i++){
		sum += input_set[i];
		
	}
	//finds sum of all values in the vector 
	
	this -> mean = sum / input_size;
	
	cout << this -> mean << endl;
	
	return this -> mean;
}

