#include <iostream>
#include "medianTest.h"
#include "Median.h"
#include "../team/stack_gen.cpp"
#include "../team/shared.h"
#include <string>

using std::string;
using std::cout;
using std::cin;

bool testMedian(){
    bool passed = true;
    string message = "";
    Median test;

    if (test.get_median() != 0){
        message += redColor("\n ERROR:: Failed .get_median() \n");
        passed = false;
    }else{
        message += greenColor("\n Passed .get_median() \n");
    }

    if (test.get_size() != 0){
        message += redColor("\n ERROR:: Failed .get_size() \n");
        passed = false;
    }else{
        message += greenColor("\n Passed .get_size() \n");
    }

    cout << message;
    return passed;
}

bool testMedian(unsigned int input_size, vector<int> data_set){
    bool passed = true;
    float median{0.0};
    string message = "";
    Median test;

    if (input_size % 2 == 1){
        median = data_set[floor(input_size/2)];
    }else{
        median = (data_set[input_size/2 - 1] + data_set[input_size/2])/2.0;
    }

    if (test.get_median() != median){
        message += redColor("\n ERROR:: Failed .get_median() \n");
        passed = false;
    }else{
        message += greenColor("\n Passed .get_median() \n");
    }

    if (test.get_size() != input_size){
        message += redColor("\n ERROR:: Failed .get_size() \n");
        passed = false;
    }else{
        message += greenColor("\n Passed .get_size() \n");
    }

    cout << message;
    return passed;
}