#include "Mean.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::ceil;
using std::floor;

Mean::Mean() {
	this ->mean = 0;
	this->input_size - 0;
	cout << "Mean Class instantiated" << endl;
	
}

Mean::~Mean() {
	cout << "Mean class deleted" << endl;
	
}

float Mean::get_mean() {
	return this-> mean;
	
}

unsigned int Mean::get_size() {
	return this->input_size;
	
}

float Mean::calculated(unsigned int input_size, vector<int> input_set) {
	
	this->input_size = input_size;
	
	int sum {};
	for(int i = 1; i <= input_size; i++){
		sum += input_set[i];
		
	}
	this->mean = sum / input_size;
	cout << this->mean << endl;
	
	return this->mean;
}

