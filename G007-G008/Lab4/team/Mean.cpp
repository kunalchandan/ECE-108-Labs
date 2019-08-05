#include "Mean.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;



Mean::Mean() {
	this -> mean = 0.0;
	this -> input_size = 0;
	
}

Mean::~Mean() {
}

float Mean::get_mean() {
	return this -> mean;
	
}

unsigned int Mean::get_size() {
	return this -> input_size;
	
}

float Mean::evaluate(vector<int> input_set) {
	
	this -> input_size = input_set.size();
	
	int sum {};
	for(int i = 0; i < input_size; i++){
		sum += input_set[i];
		
	}
	//finds sum of all values in the vector 
	
	this -> mean = float(sum) / input_size;

	
	return this -> mean;
}

