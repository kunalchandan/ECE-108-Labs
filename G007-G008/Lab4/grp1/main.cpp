#include "Mean.h"
#include "testMean.h"
#include <iostream>
#include "../team/shared.h"

int main(){
        auto big_data = dataset();
        bool test1 = testMean();
        int stack_size = 10;
        bool test2 = testMean(big_data);

        std::cout << blueColor("Testing Mean function") << std::endl;

        if(test1 && test2){
                std::cout << greenColor("Test success: Mean") << std::endl;
        }else{
                std::cout << redColor("Test failed: Mean") << std::endl;
        }

        return 0;
}
