#include <iostream>
#include <stdio.h>

bool *read_digraph(int num);

void print_graph(int num, const bool *digraph);

void prune_graph(int num, bool *digraph);

int IX(int x, int y, int x_len){
    return (x*x_len) + y;
}

int main(int argc, char *argv[]) {
    // Read dimension
    int num;
    std::cin >> num;

    // Read in directed graph
    bool* digraph = read_digraph(num);
    print_graph(num, digraph);

    // Prune digraph: Create Reflexive Matrix
    prune_graph(num, digraph);
    print_graph(num, digraph);

    // Find transitive relationships using DFS and searched table

    return 0;
}

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

void print_graph(int num, const bool *digraph) {// Print Header
    std::cout << "  ";
    for (int x = 0; x < num; x++) {
        std::cout << x + 1 << " ";
    }

    // Print graph
    for (int x = 0; x < num; x++) {
        std::cout << x + 1 << " ";
        for (int y = 0; y < num; y++) {
            std::cout << digraph[IX(x, y, num)] << " ";
        }
        std::cout << std::endl;
    }
}

bool *read_digraph(int num) {
    bool *digraph = new bool[num * num]{};
    for (int x = 0; x < num; x++) {
        int relate;
        while (std::cin >> relate) {
            digraph[IX(x, relate - 1, num)] = true;
        }
    }
    // Incorporates reflexive property
    for (int x = 0; x < num; x++) {
        for (int y = 0; y < num; y++) {
            digraph[IX(x, y, num)] = true;
        }
    }
    return digraph;
}
