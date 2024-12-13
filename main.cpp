#include "matrix.h"
#include "matrixstore.h"
#include <iostream>

using namespace std;

int main() {
    // Create the inital 'database' of matrices for manipulation
    MatrixStore* newStore = new MatrixStore();
    cout << &newStore << endl;
    newStore->prompt_user(); // kicks off CLI
    delete newStore; // remove database, free mem
    return 0;
}

// Compile notes:
// To compile you have to run ALL the files, not just main.
// g++ -o main main.cpp Matrix.cpp MatrixStore.cpp tictactoe.cpp 
// ^^ will init as main