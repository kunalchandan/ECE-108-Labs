#include "Mean.h"
#include "testMean.h"
#include <iostream>
#include "../team/shared.h"

// I'm not sure this function needs to exist
bool testMean(){
	bool output = true;
	Mean testing;

	if(testing.get_mean() != 0){
		std::cout << redColor("Test failed: Mean::get_mean()") << std::endl;
		output = false;
	}else {
        std::cout << greenColor("PASSED: .get_mean") << std::endl;
    }

	if(testing.get_size() != 0){
		std::cout << redColor("Test failed: Mean::get_size()") << std::endl;
		output = false;
	}else {
        std::cout << greenColor("PASSED: .get_size") << std::endl;
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
		std::cout << redColor("Our mean, and the mean calculated by the Mean Class do not match") << std::endl;
		output = false;
	}else {
	    std::cout << greenColor("PASSED: .get_mean") << std::endl;
	}
	if(testing.get_size() != input_size){
		std::cout << redColor("Our input size, and the size calculated by the Mean Class do not match") << std::endl;
		output = false;
	}else {
        std::cout << greenColor("PASSED: .get_size") << std::endl;
    }

	return output;
}
