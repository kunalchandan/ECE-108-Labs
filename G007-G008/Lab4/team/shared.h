#include <iostream>
#include <vector>
#include <stdlib.h>



std::vector<int> thiccc_stack(500);
int input_prev{0}, input_curr{0}, stack_size{500};					// input_prev is initialized as 0 so that if the first number is key, do nothing



void stack_input(){
	for(int i = 0; i < stack_size; ++i){
		input_curr = rand() % 111;
		if(input_curr == 9 | input_curr == 18 | input_curr == 27){
		    thiccc_stack[i] = input_curr;
		    thiccc_stack.resize(stack_size += input_prev);
		    input_prev = input_curr;
		}else if(input_curr == 13){
		    thiccc_stack[i] = input_curr;
		    thiccc_stack.resize(stack_size -= input_prev);
		    input_prev = input_curr;
		}else{
		    thiccc_stack[i] = input_curr;
		    input_prev = input_curr;
		}
	}
}