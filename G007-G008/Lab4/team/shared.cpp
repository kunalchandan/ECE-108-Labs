#include "shared.h"
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