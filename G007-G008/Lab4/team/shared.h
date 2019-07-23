#include <iostream>

int main();

void stack_input(){
    int input_prev{0}, input_curr{0}, stack_size{500};
    for(int i = 0; i < stack_size; ++i){
        std::cin >> input_curr;
        if (input_curr == 9 | input_curr == 18 | input_curr == 27){
            stack_size += input_prev;
        }else if(input_curr == 13){
            stack_size -= input_prev;
        }
    }
    // what happens if the first number is 9/18/27/13
    // also what happens if we almost the end like the last 2 numbers and you get a 13 and the previous number is like 100
    
    return 0;
}