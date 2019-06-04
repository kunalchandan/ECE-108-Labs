#include <iostream>
#include <stdio.h>
#include <string>

void print_header(std::string input){
    std::cout << std::endl;
    for(int x = 0; x < (input.length()+1); x+=2){
        std::cout << input[x] << " | ";
    }
    std::cout << input << std::endl;
    for(int x = 0; x < input.length()*3; x++){
        std::cout << "-";
    }
    std::cout << std::endl;
}

void print_table(std::string input){
    int num_vars = ((int)input.length()+1)/2;
    int opp_cmd = (input[1] == '+')? 1:0;

    bool* set = new bool[num_vars];
    // Iterate through all numbers from 0 to 2^variables
    for(int x = 0; x < 1 << num_vars; x++){
        // Mask and get bool value of each number
        for(int k = 0; k < num_vars; k++){
            int mask = 1 << k;
            int masked = (x & mask) >> k;
            set[k] = (bool)masked;

            std::cout << masked << " | ";
        }
        // Apply operation command to each variable
        bool final = set[0];
        for(int k = 1; k < num_vars; k++){
            if(opp_cmd == 0){
                final = final and set[k];
            } else if(opp_cmd == 1){
                final = final or set[k];
            }
        }
        std::cout << final << std::endl;
    }
}

int main(int argc, char *argv[]) {
    std::string input;

    if(argc >= 2){
        input = argv[1];
    }else if(argc == 1){
        std::cout << "No input was given" << std::endl;
    }

    print_header(input);

    print_table(input);

    return 0;
}
