#include "shared.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <vector>
using std::string;

// Color Text Functions
//
string blueColor(string message) {
    return "\033[1;34m" + message + "\033[0m";
}

string greenColor(string message) {
    return "\033[1;32m" + message + "\033[0m";
}

string redColor(string message) {
    return "\033[1;31m" + message + "\033[0m";
}

string swapColor(string message) {
    return "\033[7;39m" + message + "\033[0m";
}


std::vector<int> dataset() {
    int stack = 500;
    int rand;
    // Random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(0, 110);
    std::vector<int> full_send;
    for (int x = 0; (x < stack) && (x < 4917); x++) {
        // Generate Random number each step
        rand = random(gen);
        if ((rand % 9 == 0) && (rand <= 18)) {
            stack += full_send.back();
            full_send.push_back(rand);
        } else if (rand == 13) {
            // Remove number of elements equal to last number
            int rm = full_send.back();
            for (int i = 0; i < rm; i++) {
                full_send.pop_back();
            }
            stack -= rm;
            // Append most recently generated number
            full_send.push_back(rand);
        }
        else{
            full_send.push_back(rand);
        }
    }
    return full_send;
}
