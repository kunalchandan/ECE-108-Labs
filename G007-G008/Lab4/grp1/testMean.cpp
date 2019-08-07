#include "Mean.cpp"
#include "testMean.h"
#include <iostream>

// I'm not sure this function needs to exist
bool testMean(){
	bool output = true;
	Mean testing;

	if(testing.get_mean() != 0){
		std::cout << "Test failed: Mean::get_mean()" << std::endl;
		output = false;
	}

	if(testing.get_size() != 0){
		std::cout << "Test failed: Mean::get_size()" << std::endl;
		output = false;
	}

	return output;
}

bool testMean(std::vector<int> input_set){
	float input_size = input_set.size();

	bool output = true;

	// Calculate Mean once here
	float input_mean = 0;
	float sum = 0;
	for(int i = 0; i < input_size; ++i){
		sum += input_set[i];
	}
	input_mean = sum / input_size;

	// Get Mean calculated by Mean class
	Mean testing;
	testing.evaluate(input_set);

	// Compare calculated and retrieved values
	if(testing.get_mean() != input_mean){
		std::cout << "Our mean, and the mean calculated by the Mean Class do not match" << std::endl;
		output = false;
	}
	if(testing.get_size() != input_size){
		std::cout << "Our input size, and the size calculated by the Mean Class do not match" << std::endl;
		output = false;
	}

	return output;
}

/*
int main(){
	auto big_data = dataset();
	bool test1 = testMean();
	int stack_size = 10;
	bool test2 = testMean(stack_size, big_data);

	if(test1 && test2){
		std::cout << "Test success: Mean";
	}else{
		std::cout << "Test failed: Mean";
	}

	return 0;
}
*/
