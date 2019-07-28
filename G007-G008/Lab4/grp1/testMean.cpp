#include "testMean.h"
#include "../team/shared.h"
#include <iostream>

int main();

bool testMean(){
	bool output = true;
	Mean testing;
	
	if(testing.get_mean != 0){
		output = false;
	}
	
	if(testing.get_size != 0){
		output = false;
	}
	
	return output;
}

bool testMean(unsigned int input_size, std::vector<int> input_set){
	bool output = true;
	
	// not sure if this is how we're supposed to implement the function, going to confirm later today -- Leo
	Mean testing;
	testing.calculated(unsigned int input_size, std::vector<int> input_set);
	
	// this may be the correct way idk -- Leo
	Mean testing(unsigned int input_size, std::vector<int> input_set);
	GIT COMMIT
	// are we supposed to test it against known stacks or randomized stacks? Just one stack or multiple? -- Leo
	if(testing.get_mean != WHATEVER_THE_MEAN_IS_REEEEEEEEEEEEEEEEEEEEEEEEEE){
		output = false;
	}
	if(testing.get_size != stack_size){
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