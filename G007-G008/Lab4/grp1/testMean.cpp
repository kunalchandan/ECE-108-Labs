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
	Mean testing;
	testing.calculated(unsigned int input_size, std::vector<int> input_set);
	//not sure if this is how we're supposed to implement the function, going to confirm later today -- Leo
}

int main(){
	bool test1 = testMean();
	bool test2 = testMean(unsigned int input_size,vector<int> input_set);
	
	if(test1 && test2){
		std::cout << "Test success: Mean";
	}else{
		std::cout << "Test failed: Mean"
	}
	
	return 0;
}