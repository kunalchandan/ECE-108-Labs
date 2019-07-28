#include <iostream>
#include <vector>
#include <stdlib.h>

std::vector<int> thiccc_stack(500);
int input_prev{0}, input_curr{0}, stack_size{500};

void stack_input(){
	srand(time(NULL));
	for(int i = 0; i < stack_size; ++i){
		input_curr = rand() % 111;
		if(input_curr == 9 || input_curr == 18 || input_curr == 27){	
			// if the input is 9, 18, or 27 then increase stack size by prev input
		    thiccc_stack[i] = input_curr;
		    thiccc_stack.resize(stack_size + input_prev);
			stack_size += input_prev;
		    input_prev = input_curr;
		}else if(input_curr == 13){
			// if the input is 13 then decrease stack size by prev input
			// note that if i exceeds stack_size, the for loop will immediately end and all contents unfit for the stack will be truncated
		    thiccc_stack[i] = input_curr;
			if(stack_size - input_prev < 0){
			// if the stack size decreases below zero, set straight to 0
				thiccc_stack.resize(0);
				stack_size = 0;
			}else{
				thiccc_stack.resize(stack_size - input_prev);
				stack_size -= input_prev;
			}
		    input_prev = input_curr;
		}else{
			// if the input is not important then input to stack as is
		    thiccc_stack[i] = input_curr;
		    input_prev = input_curr;
		}
	}
}