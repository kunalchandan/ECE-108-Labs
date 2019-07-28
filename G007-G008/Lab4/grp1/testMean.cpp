#include "testMean.h"
#include "../team/shared.h"
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
	bool output = true;
	Mean testing;
	testing.calculated(unsigned int input_size, std::vector<int> input_set);
	
	if(testing.get_mean != testing -> mean){
		output = false;
	}
	if(testing.get_size != testing -> input_size){
		output = false;
	}
	
	return output;
}

int main(){
	bool test1 = testMean();
	stack_input();
	bool test2 = testMean(stack_size, thiccc_stack);
	
	if(test1 && test2){
		std::cout << "Test success: Mean";
	}else{
		std::cout << "Test failed: Mean";
	}
	
	return 0;
}