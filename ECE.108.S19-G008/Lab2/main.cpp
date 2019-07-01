#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::cerr;
using std::ifstream;

int IX(int x, int y, int xLen){
    return (x*xLen) + y;
}

int* read_expression(const string fileName){
    ifstream dimacs;
    int num_vars;
    int num_clauses;
    char this_char;
    dimacs.open(fileName);
    if (!dimacs) {
        cerr << "Unable to open the file" << endl;
        exit(1);
    }

    dimacs >> num_vars >> num_clauses;
    cout << "Variables: " << num_vars << " Clauses: " << num_clauses << endl;
    //don't cares are stored as 0, true = 1, false = -1
    int* expr = new int [num_clauses*num_vars]{0};
    cout << "Reading Expression..." << endl;

    char prev_char = '1';
    int col = 0;
    while (dimacs >> this_char) {
        if (this_char == '0'){
            cout << endl;
            col ++;

        }else if (this_char == ' '){
            continue;
        }else if(this_char == '-'){
            prev_char = '-';

        }else{
            int var =  this_char - '0';
            if (prev_char == '-'){
                var = var * -1;
            }
            int index = abs(var) - 1;
            expr[IX(col, index, num_clauses)] = ((var > 0) ? 1: -1);
            cout << ((var > 0)? "1": "-1");
            prev_char = this_char;
        }
    }
    cout << endl;
    dimacs.close();
    return expr;
}

std::vector<std::vector<int>>* read_tests(){
    auto *tests = new std::vector<std::vector<int>>();
    auto *line = new std::vector<int>();
    int c_num;
    string input;
    std::getline(cin, input);
    std::istringstream iss(input);

    while(iss >> c_num){
        if(c_num == 0){
            tests->push_back(*line);
            line->clear();
        }else{
            line->push_back(c_num);
        }
    }
    return tests;
}

int main(int argc, char *argv[]) {
    ifstream dimacs;
    int numVars;
    int numClauses;
    string fileName = argv[1];

    dimacs.open(fileName);
    if (!dimacs) {
        cerr << "Unable to open the file " << fileName << endl;
        exit(1);
    }

    dimacs >> numVars >> numClauses;
    dimacs.close();

    cout << "Variables: " << numVars << " Clauses: " << numClauses << endl;

    // Size = [numClauses*numVars]
    int* all = read_expression(fileName);

    // Size = [numTests*numVars]
    std::vector<std::vector<int>> tests = *read_tests();
    int numTests = (int)(tests.size());

    for(int t = 0; t < numTests; t++){

        // Clone the expression array
        int* clone = new int[numClauses*numVars]{};
        std::copy(all, all+(numClauses*numVars), clone);

        // Invert any not-ed values
        for(int x = 0; x < numVars; x++){
            if(tests.at(t).at(x) <= -1){
                for(int j = 0; j < numClauses; j++){
                    // Convert True to False and vice-versa
                    clone[IX(j, x, numVars)] *= -1;
                }
            }
        }

        // Calculate truth value for each OR expression
        int* evals = new int[numClauses]{};
        for(int x = 0; x < numClauses; x++){

            int accumulate = clone[IX(x, 0, numVars)];
            for(int y = 0; y < numVars; y++){

                int clone_curr = clone[IX(x, y, numVars)];

                if (accumulate == 0){
                    accumulate += clone_curr;
                }else if(accumulate <= -1){
                    if (clone_curr == -1){
                        accumulate = -1;
                    }else if (clone_curr == 0){
                        accumulate = accumulate;
                    } else { // clone_curr == 1
                        accumulate = 1;
                    }
                }else{ // accumulate == 1
                    accumulate = 1;
                }
            }
            evals[x] = accumulate;
        }

        // Calculate truth value for final AND expression
        int final = evals[0];
        for(int x = 0; x < numClauses; x++){

            int curr = evals[x];

            if (final == 0){
                final += curr;
            }else if(final <= -1){
                final = -1;
            }else{ // final >= 1
                if (curr == -1){
                    final = -1;
                }else if (curr == 0){
                    final = final;
                } else { // curr == 1
                    final = 1;
                }
            }
        }
        cout << "Expression Value for Test " << t+1 << ": " << final << endl;
    }

    return 0;
}