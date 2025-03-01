#include "testMedian.h"
#include "Median.h"
#include "../team/shared.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::vector;

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
        message += redColor("\n ERROR:: Failed .get_size() \n\n");
        passed = false;
    }else{
        message += greenColor("\n Passed .get_size() \n\n");
    }

    cout << message;
    return passed;
}

bool testMedian(vector<int> data_set){
    int input_size = data_set.size();
    bool passed = true;
    float median{0.0};
    string message = "";
    Median test;
    test.evaluate(data_set);

    sort(data_set.begin(), data_set.end());

    if (input_size % 2 == 1){
        median = data_set[int(input_size/2)];
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
        message += redColor("\n ERROR:: Failed .get_size() \n\n");
        passed = false;
    }else{
        message += greenColor("\n Passed .get_size() \n\n");
    }

    cout << message;
    return passed;
}
