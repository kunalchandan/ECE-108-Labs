#include <iostream>
#include <vector>
#include <stdlib.h>



std::vector<int> thiccc_stack(500);
int input_prev{0}, input_curr{0}, stack_size{500};					// input_prev is initialized as 0 so that if the first number is key, do nothing



void stack_input(){
	for(int i = 0; i < stack_size; ++i){
		input_curr = rand() % 111;
		if(input_curr == 9 | input_curr == 18 | input_curr == 27){	// if the input is 9, 18, or 27
		    thiccc_stack[i] = input_curr;							// add the number to the back of the stack
		    thiccc_stack.resize(stack_size += input_prev);			// and increase the stack size by the previous input
		    input_prev = input_curr;								// cache the current input as previous input for the next input
		}else if(input_curr == 13){									// if the input is 27
		    thiccc_stack[i] = input_curr;							// add the number to the back of the stack
		    thiccc_stack.resize(stack_size -= input_prev);			// and decrease the stack size by the previous input
			// note that if i exceeds stack_size, the for loop will immediately end and all contents unfit for the stack will be truncated
		    input_prev = input_curr;								// cache the current input as previous input for the next input
		}else{														// if the input is not important
		    thiccc_stack[i] = input_curr;							// add the number to the back of the stack
		    input_prev = input_curr;								// cache the current input as previous input for the next input
		}
	}
}