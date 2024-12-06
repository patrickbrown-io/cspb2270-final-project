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
        std::cout << "0) Create a Matrix" << std::endl;
        std::cout << std::endl;
        std::cout << "1) See all available" << std::endl;
        std::cout << std::endl;
        // Add more
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
        // Useer choices
        switch(choice){
            case 0: {
                std::cout << "Create a Matrix Selected" << std::endl;
                    // Get dimensions from the user
                    int rows, cols;
                    std::cout << "Enter the number of rows: ";
                    std::cin >> rows;
                    std::cout << "Enter the number of columns: ";
                    std::cin >> cols;

                    // Create a matrix!
                    Matrix newMatrix(cols, rows);
                    // Counter for total to enter
                    int totalCount = rows * cols;
                    // Insert values until we hit the counts
                    for (int i = 0; i < rows; ++i)
                    {
                        for (int j = 0; j < cols; ++j)
                        {   // log a count for ease of user input
                            std::cout << "Enter value (" << (totalCount--) << " left): ";
                            int value;
                            std::cin >> value;
                            newMatrix.set_value(j, i, value);
                        }
                        }
                    // Add the matrix to the store with a name
                    std::string matrixName;
                    std::cout << "Enter a name for this matrix: ";
                    // this line is needed to not trigger the menu tree until the return
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    // get the matrix name
                    std::getline(std::cin, matrixName);


                    // Add the matrix to the store
                    add_matrix(matrixName, newMatrix);
                    std::cout << "Matrix created successfully!" << std::endl << std::endl;
                    break;
            }
            case 1: {
                std::cout << "See Available Matrices Selected" << std::endl;
                // Base case empty
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                }
                else
                {
                    // Iterate over the whole store
                    for (size_t i = 0; i < store.size(); ++i) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << "Matrix Name: " << node.name << std::endl;
                        node.matrix.print_matrix(); // Print the contents of the matrix
                        std::cout << std::endl << "--------" << std::endl;
                        std::cout << std::endl;
                    }
                }
                break;
            }
            // TO DO -- add addtl math/crud operations here
            default:
            // Handle invalid input
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
    } while (true);
}


// Add a matrix to the store with a given name
void MatrixStore::add_matrix(std::string& name, Matrix& matrix) {
    // to do
    MatrixNode newMatrix;
    newMatrix.name = name;
    newMatrix.matrix = matrix;

    // Add the new MatrixNode to the store vector
    store.push_back(newMatrix);
    std::cout << name << "' added to the store." << std::endl;
}

// Get a matrix by its name
Matrix* MatrixStore::get_matrix(std::string& name) {
    // TO DO
    return nullptr;
}

// Remove a matrix by its name
bool MatrixStore::remove_matrix(std::string& name) {
    // to do
    return false;
}

// Print all matrices and their names
void MatrixStore::print_store() {
    // handle an empty store
    if (store.empty()) {
        std::cout << "No matrices available." << std::endl;
    } else {
        for (size_t i = 0; i < store.size(); i++) {
            MatrixNode& node = store[i];
            std::cout << "Matrix Name: " << node.name << std::endl;
            node.matrix.print_matrix();
            std::cout << "------------";
            std::cout << std::endl;
        }
    }
}

// TO DO -- Will need to uncomment these, throw compiler errors w/out a return atm

// // Math functions - should prompt the user to select 2 matricies and then do the operation
// Matrix MatrixStore::add_matrices(Matrix &matrixA, Matrix &matrixB){};
// Matrix MatrixStore::subtract_matrices(Matrix &matrixA, Matrix &matrixB){};
// Matrix MatrixStore::multiply_matrices(Matrix &matrixA, Matrix &matrixB){};
// Matrix MatrixStore::divide_matrices(Matrix &matrixA, Matrix &matrixB){};
