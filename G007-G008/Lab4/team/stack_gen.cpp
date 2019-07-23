#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <vector>


std::vector<int> dataset() {
    int stack = 500;
    int rand;
    // Random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> full_send;
    for (int x = 0; x < stack; x++) {
        // Generate Random number each step
        std::uniform_int_distribution<> random(0, 110);
        rand = random(gen);
        if ((rand % 9 == 0) && (rand <= 27)) {
            stack += full_send.back();
            full_send.push_back(rand);
        } else if (rand == 13) {
            // Remove number of elements equal to last number
            int rm = full_send.back();
            for (int i = 0; i < rm; i++) {
                full_send.pop_back();
            }
            // Append most recently generated number
            full_send.push_back(rand);
        }
    }
    return full_send;
}

int main(int argc, char *argv[]) {
    std::vector<int> sample_data = dataset();
    return 0;
}