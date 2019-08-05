#include "Median.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::ceil;
using std::floor;

Median::Median() {
    this->median = 0.0;
    this->input_size = 0;
    cout << "Median Class instantiated" << endl;
}

Median::~Median() {
    cout << "median class deleted" << endl;
}

float Median::get_median() {
    return this->median;
}

unsigned int Median::get_size() {
    return this->input_size;
}

float Median::evaluate(vector<int> data_set) {
    this->input_size = data_set.size();
    sort(data_set.begin(), data_set.end());
    //if the size is odd then just take the middle term, otherwise, take the mean of the middle two terms.
    if (input_size % 2 == 1){
        this->median = data_set[floor(input_size/2)];
    }else{
        this->median = (data_set[input_size/2 - 1] + data_set[input_size/2])/2.0;
    }
    return this->median;
}
