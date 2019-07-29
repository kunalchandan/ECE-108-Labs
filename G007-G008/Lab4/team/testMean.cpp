#include "testMean.h"
#include "Mean.h"
#include "stack_gen.cpp"
#include <iostream>

int main();

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

bool testMean(unsigned int input_size, std::vector<int> input_set){

	float input_mean{};
	float sum{0};
	for(int i = 0; i < input_size; ++i){
		sum += input_set[i];
	}
	input_mean = sum / input_size;

	bool output = true;
	Mean testing;
	testing.calculated(input_size, input_set);

	if(testing.get_mean() != input_mean){
		output = false;
	}
	if(testing.get_size() != input_size){
		output = false;
	}

	return output;
}

int main(){
	auto big_data = dataset();
	bool test1 = testMean();
	bool test2 = testMean(stack_size, big_data);

	if(test1 && test2){
		std::cout << "Test success: Mean";
	}else{
		std::cout << "Test failed: Mean";
	}

	return 0;
}
