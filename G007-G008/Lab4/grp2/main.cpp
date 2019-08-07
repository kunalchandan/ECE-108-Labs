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

int main(){
    auto big_data = dataset();
    bool test = testMedian(big_data);

    std::cout << blueColor("Testing Median function") << std::endl;

    if(test){
        std::cout << greenColor("Test success: Median") << std::endl;
    }else{
        std::cout << redColor("Test failed: Median") << std::endl;
    }

    return 0;
}

