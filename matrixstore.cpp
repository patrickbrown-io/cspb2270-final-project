#include "matrixstore.h"
#include <iostream>
#include "matrix.h"

// Constructor
MatrixStore::MatrixStore() {
    // Initialization logic (if needed)
    std::cout << "MatrixStore initialized." << std::endl;
}

// Destructor
MatrixStore::~MatrixStore() {
    // Cleanup logic (if needed)
}

// Menu System - this CLI controls the store
// Will be able to do basic crud operations (Create, Read, Update, Delete matricies)
// As well as basic math operations
// Stretch goal: Tic Tac Toe?
void MatrixStore::prompt_user() {
    // Cool splash logo
    std::cout << "**********************************************" << std::endl;
    std::cout << "***** Matrix: Data Structure Exploration *****" << std::endl;
    std::cout << "************** by Patrick Brown **************" << std::endl;
    std::cout << "**********************************************" << std::endl << std::endl;

    std::cout << "What would you like to do?" << std::endl;
    // init variables for looping menu
    std::string input;
    int choice;
    // menu loop, break with Q.
    do {
        // Program menu, will be able to trigger manipulations here
        std::cout << "0) Your Choice Here" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter menu selection (Q to quit): ";
        std::cin >> input;
        std::cout << std::endl;
        // break conditions, will exit the do/while looping
        if (input == "Q" || input == "q") {
            std::cout << "Thank you for using my program!" << std::endl;
            std::cout << "Quitting..." << std::endl;
            break;
        }

        // This is needed to convert input to an int and then turn that into choice, since input is setup to also hand the q's
        choice = (isdigit(input[0]) || (input[0] == '-' && input.size() > 1 && isdigit(input[1]))) ? stoi(input) : -1;
        switch(choice){
            case 0:
                std::cout << "Valid input!" << std::endl;
            break;
            // TO DO -- add math/crud operations here
            default:
            // Handle invalid input
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
    } while (true);
}


// Add a matrix to the store with a given name
void MatrixStore::add_matrix(const std::string& name, const Matrix& matrix) {
    // to do
}

// Get a matrix by its name
Matrix* MatrixStore::get_matrix(const std::string& name) {
    return nullptr;
}

// Remove a matrix by its name
bool MatrixStore::remove_matrix(const std::string& name) {
    return false;
}

// Print all matrices and their names
void MatrixStore::print_store() const {
    // to do
    
}


// TO DO -- Will need to uncomment these, throw compiler errors w/out a return atm

// // Math functions - should prompt the user to select 2 matricies and then do the operation
// Matrix MatrixStore::add_matrices(Matrix &matrixA, Matrix &matrixB){};
// Matrix MatrixStore::subtract_matrices(Matrix &matrixA, Matrix &matrixB){};
// Matrix MatrixStore::multiply_matrices(Matrix &matrixA, Matrix &matrixB){};
// Matrix MatrixStore::divide_matrices(Matrix &matrixA, Matrix &matrixB){};
