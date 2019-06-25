#include <iostream>
#include <fstream>
#include <stdio.h>
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

int main(int argc, char *argv[]) {
    ifstream dimacs;
    int numVars;
    int numClauses;
    char thisChar;
    string fileName = argv[1];

    dimacs.open(fileName);
    if (!dimacs) {
        cerr << "Unable to open the file" << endl;
        exit(1);
    }

    dimacs >> numVars >> numClauses;
    cout << "Variables: " << numVars << " Clauses: " << numClauses << endl;
    cout << "Reading Expression..." << endl;

    int* all = new int[numClauses*numVars]{};
    int numTests = 0;
    int* tests = new int[numTests*numVars]{};
    for(int t = 0; t < numTests; t++){

        // Clone the expression array
        int* clone = new int[numClauses*numVars]{};
        std::copy(all, all+(numClauses*numVars), clone);

        // Invert any not-ed values
        for(int x = 0; x < numVars; x++){
            if(tests[IX(t, x, numVars)] == -1){
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
        cout << final << endl;
    }

    return 0;
}