#include <iostream>
#include <stdio.h>
#include <vector>
using std::vector;
using std::size_t;

// Function declarations
bool *read_digraph(int num);
bool *trans_closure(int vars, bool *matrix);
void print_graph(int num, const bool *digraph);
void prune_graph(int num, bool *digraph);
void ordered_pairs(int vars, bool *matrix);

// By Kunal Chandan:
// Function for allowing a dynamically allocated 2D array to be indexed easily
int IX(int x, int y, int x_len){
    return (x*x_len) + y;
}

// Main: main function of program: joint effort Nicholas and Kunal
int main(int argc, char *argv[]) {
    // Read dimension
    int num;
    std::cin >> num;

    // Read in directed graph
    bool* digraph = read_digraph(num);
    //std::cout << "Read in adjacency matrix" << std::endl;
    //print_graph(num, digraph);

    // Prune digraph: Create Reflexive Matrix
    //std::cout << "Transitive closure" << std::endl;
    digraph = trans_closure(num, digraph);
    //print_graph(num, digraph);

    //std::cout << "Pruned graph" << std::endl;
    prune_graph(num, digraph);
    //print_graph(num, digraph);
    ordered_pairs(num, digraph);
    std::cout << "End of program" << std::endl << std::endl;

    // Find transitive relationships using DFS and searched table

    return 0;
}

// By Kunal Chandan
// Prune the graph, remove any relations that are aRb but not bRa
void prune_graph(int num, bool *digraph) {
    for (int x = 0; x < num; x++) {
        for (int y = 0; y < num; y++) {
            bool both = digraph[IX(x, y, num)] && digraph[IX(y, x, num)];
            if (!both) {
                digraph[IX(x, y, num)] = false;
                digraph[IX(y, x, num)] = false;
            }
        }
    }
}

// By Kunal Chandan
void print_graph(int num, const bool *digraph) {
    // Print Header
    std::cout << "  ";
    for (int x = 0; x < num; x++) {
        std::cout << x + 1 << " ";
    }

    // Print graph
    for (int x = 0; x < num; x++) {
        std::cout << std::endl;
        std::cout << x + 1 << " ";
        for (int y = 0; y < num; y++) {
            std::cout << digraph[IX(x, y, num)] << " ";
        }

    }
    std::cout << std:: endl;
}
// By Kunal Chandan
bool *read_digraph(int num) {
    // Read the digraph from standard input and place into a trust array of size num*num variables
    bool *digraph = new bool[num * num]{false};
    for (int x = 0; x < num; x++) {
        int relate;
        while (std::cin >> relate) {
            if (relate == 0){
                break;
            }
            //std::cout << relate << std::endl;
            digraph[IX(x, relate - 1, num)] = true;
        }
    }
    // Incorporates reflexive property
//    for (int x = 0; x < num; x++) {
//        for (int y = 0; y < num; y++) {
//            digraph[IX(x, y, num)] = true;
//        }
//    }
    return digraph;
}

// By: Nicholas Paquin, the commented out code is mine, it works but is obviously less efficient than that in the video
// which is what I ended up using instead. The function loops through the array and by looking at other array indexes
// determines whether there is transivity within it
bool *trans_closure(int vars, bool *matrix){
    // vector<int> next;
    int prev_row = 0;
    for (int epoch = 0; epoch < vars; ++epoch){
        //runs through adjacency matrix
        for (int i = 0; i < vars; ++i){
            for (int x = 0; x < vars; ++x){
                matrix[IX(i, x, vars)] = matrix[IX(i, x, vars)] || (matrix[IX(i, epoch, vars)] && matrix[IX(epoch, x, vars)]);
//                if (matrix[IX(i, x, vars)]){
//                    for (int y = 0; y < vars; ++y){
//                        if (matrix[IX(x, y, vars)]){
//                            matrix[IX(i, y, vars)] = true;
//                        }
//                    }
//                }
            }
        }
    }
    return matrix;
}

// By Nicholas Paquin Function loops through matrix and prints ordered pairs.
// if a number is covered in a row then it is appended to an array so that it won't be repeated
void ordered_pairs(int vars, bool *matrix){
    vector<int> seen;
    bool checked;
    for (size_t i = 0; i < vars; ++i){
        checked = false;
        for (int m : seen){
            if (i == m){
                checked = true;
                break;
            }
        }
        if (!checked) {
            std::cout << "{";
            for (size_t j = 0; j < vars; ++j) {
                if (matrix[IX(i, j, vars)]) {
                    seen.push_back(j);
                    if(i != j) {
                        std::cout << ", ";
                    }
                    std::cout << j + 1;
                }
            }
            std::cout << "}" << std::endl;
        }
    }
}
