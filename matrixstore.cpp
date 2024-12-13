#include "matrixstore.h"
#include <iostream>
#include "matrix.h"
#include "tictactoe.h"
#include <ctime> // this is just used for randomizing the 'coin flip' to determine who goes first in tictactoe


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
// Tic Tac Toe?
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
        std::cout << "2) Remove a Matrix" << std::endl;
        std::cout << std::endl;
        std::cout << "3) Update a Matrix" << std::endl;
        std::cout << std::endl;
        std::cout << "4) Add Two Matricies" << std::endl;
        std::cout << std::endl;
        std::cout << "5) Subtract Two Matricies" << std::endl;
        std::cout << std::endl;
        std::cout << "6) Multiply Two Matricies" << std::endl;
        std::cout << std::endl;
        std::cout << "7) Invert a Matrix" << std::endl;
        std::cout << std::endl;
        std::cout << "8) Sort a Matrix (low -> high)" << std::endl;
        std::cout << std::endl;
        std::cout << "9) Play Tic Tac Toe" << std::endl;
        std::cout << std::endl;
        std::cout << "10) Generate Demo Matricies" << std::endl;
        std::cout << std::endl;
        std::cout << "11) Does this Matrix Contain?" << std::endl;
        std::cout << std::endl;
        std::cout << "12) Get Coordinates of a Value in a Matrix" << std::endl;
        std::cout << std::endl;
        std::cout << "13) Transpose a Matrix (Swap rows and columns)" << std::endl;
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
        bool isNumeric = !input.empty();
        // iterate over the input and convert to char
        for (std::string::size_type i = 0; i < input.size(); ++i) {
            char ch = input[i];
            if (!std::isdigit(static_cast<unsigned char>(ch))) {
                isNumeric = false;
                break;
            }
        }
        // Convert to int, or -1
        int choice = isNumeric ? std::stoi(input) : -1;

        // invalid inputs
        if (std::cin.fail()) {
            std::cin.clear();  // clear error
            while (std::cin.get() != '\n');  // ignore a bad input until the next newline is hit
        }

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
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < cols; j++)
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
                    for (int i = 0; i < store.size(); i++) {
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
            // Decided to make this case a bit more manual, type in the explict name versus quick select, so that you can't destory hard work intentioanlly.
            case 2: {
                std::cout << "Remove a Matrix Selected" << std::endl;
                // empty case
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                    // input name of the matrix they want to destroy
                    std::string matrixName;
                    std::cout << "Enter the name of the matrix to remove: ";
                    // this line is needed to clear input buffer
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, matrixName); // Get the matrix name

                    // remove it, or provide failure message
                    if (remove_matrix(matrixName)) {
                        std::cout << "Matrix \"" << matrixName << "\" removed successfully." << std::endl;
                    } else {
                        std::cout << "Matrix \"" << matrixName << "\" not found." << std::endl;
                    }
                }
                break;
            }
            case 3: {
                std::cout << "Update a Matrix Selected" << std::endl;
                // empty case
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }

                // Get the chosen matrix
                Matrix& selectedMatrix = store[selectedIndex].matrix;

                // USe the private members to choose accurate coordinates
                int rows = selectedMatrix.get_height();
                int cols = selectedMatrix.get_width();
                std::cout << "Matrix \"" << store[selectedIndex].name << "\" selected. Dimensions: " 
                        << rows << "x" << cols << std::endl;

                // Prompt user for coordinates
                int row, col;
                std::cout << "Enter the row to update (0 - " << rows - 1 << "): ";
                std::cin >> row;
                std::cout << "Enter the column to update (0 - " << cols - 1 << "): ";
                std::cin >> col;

                // If coordinates aren't valid, cancel the update, send back to menu
                if (row < 0 || row >= rows || col < 0 || col >= cols) {
                    std::cout << "Invalid coordinates. Returning to menu." << std::endl;
                    break;
                }

                // Valid coordinates, prompt for  New value
                int newValue;
                std::cout << "Enter the new value for position (" << row << ", " << col << "): ";
                std::cin >> newValue;

                // Update the matrix, show user and return
                selectedMatrix.set_value(col, row, newValue);
                std::cout << "Matrix updated successfully!" << std::endl;
                /// show
                std::cout << "Updated Matrix:" << std::endl;
                selectedMatrix.print_matrix();
                std::cout << "Returning to main menu..." << std::endl << std::endl;
            }
                break;
            }
            case 4: {
                std::cout << "Add Matricies Selected" << std::endl;
                // empty store
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                // show users the available matricies
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }
                // First matrix
                Matrix& selectedMatrix = store[selectedIndex].matrix;

                // show users the available matricies
                    std::cout << "Please enter another matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndexTwo;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndexTwo;

                // Validate selection
                if (selectedIndexTwo < 0 || selectedIndexTwo >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }
                // Second Matrix
                Matrix& selectedMatrixTwo = store[selectedIndexTwo].matrix;

                // IF they're add-able, do it, else reject and send back to menu
                if((selectedMatrix.get_height() == selectedMatrixTwo.get_height()) && (selectedMatrix.get_width() == selectedMatrixTwo.get_width())){
                    // Add
                    Matrix summedMatrix = add_matrices(selectedMatrix, selectedMatrixTwo);
                    // Create a new matrix
                    add_matrix(("Sum of " + store[selectedIndex].name + " + " + store[selectedIndexTwo].name), summedMatrix);
                    // print it for the user
                    std::cout << "Addition complete!" << std::endl;
                    summedMatrix.print_matrix();
                    std::cout << "----------------" << std::endl;
                } else {
                    // Show the user the mismatch
                    std::cout << "Cannot add two matrices with inequal width or heights!" << std::endl;
                    std::cout << "Matrix 1 Height: " << selectedMatrix.get_height() <<  "|| Selected Matrix 2 Height: " << selectedMatrixTwo.get_height() << std::endl;
                    std::cout << "Matrix 1 Width: " << selectedMatrix.get_width() << "|| Selected Matrix 2 Width: " << selectedMatrixTwo.get_width() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    std::cout << "-----------------------------" << std::endl;
                }
                }
                break;
            }
            case 5: {
                std::cout << "Subtract Matricies Selected" << std::endl;
                // empty store
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                // show users the available matricies
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }
                // First matrix
                Matrix& selectedMatrix = store[selectedIndex].matrix;

                // show users the available matricies
                    std::cout << "Please enter another matrix to subtract from the first (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndexTwo;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndexTwo;

                // Validate selection
                if (selectedIndexTwo < 0 || selectedIndexTwo >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }
                // Second Matrix
                Matrix& selectedMatrixTwo = store[selectedIndexTwo].matrix;

                // IF they're add-able, do it, else reject and send back to menu
                if((selectedMatrix.get_height() == selectedMatrixTwo.get_height()) && (selectedMatrix.get_width() == selectedMatrixTwo.get_width())){
                    // Add
                    Matrix subtrMatrix = subtract_matrices(selectedMatrix, selectedMatrixTwo);
                    // Create a new matrix
                    add_matrix(("Difference of " + store[selectedIndex].name + " - " + store[selectedIndexTwo].name), subtrMatrix);
                    // print it for the user
                    std::cout << "Subtraction complete!" << std::endl;
                    subtrMatrix.print_matrix();
                    std::cout << "----------------" << std::endl;
                } else {
                    // Show the user the mismatch
                    std::cout << "Cannot subtract two matrices with inequal width or heights!" << std::endl;
                    std::cout << "Matrix 1 Height: " << selectedMatrix.get_height() <<  "|| Selected Matrix 2 Height: " << selectedMatrixTwo.get_height() << std::endl;
                    std::cout << "Matrix 1 Width: " << selectedMatrix.get_width() << "|| Selected Matrix 2 Width: " << selectedMatrixTwo.get_width() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    std::cout << "-----------------------------" << std::endl;
                }
                }
                break;
            }
            case 6: {
                std::cout << "Multiply Matricies Selected" << std::endl;
                // empty store
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                // show users the available matricies
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }
                // First matrix
                Matrix& selectedMatrix = store[selectedIndex].matrix;

                // show users the available matricies
                    std::cout << "Please enter another matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndexTwo;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndexTwo;

                // Validate selection
                if (selectedIndexTwo < 0 || selectedIndexTwo >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }
                // Second Matrix
                Matrix& selectedMatrixTwo = store[selectedIndexTwo].matrix;

                // IF they're add-able, do it, else reject and send back to menu
                if(selectedMatrix.get_height() == selectedMatrixTwo.get_width()){
                    // Add
                    Matrix multMatrix = multiply_matrices(selectedMatrix, selectedMatrixTwo);
                    // Create a new matrix
                    add_matrix(("Product of " + store[selectedIndex].name + " - " + store[selectedIndexTwo].name), multMatrix);
                    // print it for the user
                    std::cout << "Product complete!" << std::endl;
                    multMatrix.print_matrix();
                    std::cout << "----------------" << std::endl;
                } else {
                    // Show the user the mismatch
                    std::cout << "Cannot multiply two matrices with inequal width or heights!" << std::endl;
                    std::cout << "Matrix 1 Height: " << selectedMatrix.get_height() <<  "|| Selected Matrix 2 Width: " << selectedMatrixTwo.get_height() << std::endl;
                    std::cout << "Returning to menu..." << std::endl;
                    std::cout << "-----------------------------" << std::endl;
                }
                }
                break;
            }
            // No such thing as division, invert
            case 7: {
                std::cout << "Invert a Matrix Selected" << std::endl;
                // empty case
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }

                // Get the chosen matrix
                Matrix& selectedMatrix = store[selectedIndex].matrix;
                Matrix inverted = invert_matrix(selectedMatrix);
                this->add_matrix("Inverted " + store[selectedIndex].name, inverted);

                /// show
                std::cout << "Inverted Matrix:" << std::endl;
                inverted.print_matrix();
                std::cout << "Returning to main menu..." << std::endl << std::endl;
            }
                break;
            }
            // SORT! Select row-wise or column-wise (0, 1)
            case 8: {
                std::cout << "Sort a matrix" << std::endl;
                // empty case
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }
                // Chose a sort
                int selectedSort;
                std::cout << "Enter your sort (0 for col, 1 for row); ";
                std::cin >> selectedSort;
                // used for the confirm message
                std::string selectedSortString = selectedSort == 0 ? "column" : "row";

                // Validate selection
                if (selectedSort > 1) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                } else {
                    // Get the chosen matrix
                    Matrix& selectedMatrix = store[selectedIndex].matrix;
                    Matrix sortedMatrix = this->sort_matrix(selectedMatrix, selectedSort);

                    // Sort
                    this->add_matrix("Sorted by " + selectedSortString + store[selectedIndex].name, sortedMatrix);
                    /// show
                    std::cout << "Inverted Matrix:" << std::endl;
                    sortedMatrix.print_matrix();
                    std::cout << "Returning to main menu..." << std::endl << std::endl;
                }


            }
                break;
            }
            case 9: {
                std::cout << "Let's play tic tac toe!" << std::endl;
                std::cout << "You will be X's...." << std::endl;
                // init scores to 0
                TicTacToe board;
                board.set_comp_score(); // cpu
                board.set_player_score(); // player 
                
                bool playAgain = true;
                // Start game loop, maintains the game state
                while (playAgain) {
                    board.clear_board();
                    board.print_board(); // blank board

                    // Decide who goes first: 0 for player, 1 for computer
                    std::srand(std::time(0)); // Seed random number generator
                    int currentPlayer = std::rand() % 2; // Randomly choose starting player
                    std::cout << (currentPlayer == 0 ? "You go first!" : "Computer goes first!") << std::endl;

                    bool gameOver = false; // init flag to keep the game loop goin

                    // Per-Game loop
                    while (!gameOver) {
                        // Player's turn
                        if (currentPlayer == 0) {
                            int position;
                            bool validMove = false;
                            while (!validMove) {
                                // prompt for a position input
                                std::cout << "Choose a position (1-9): ";
                                std::cin >> position;

                                // Fixes invalid input if not a number, could break the % operator
                                if (std::cin.fail()) {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    // reprompt for correct input, try again
                                    std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
                                    continue;
                                }

                                // This just simplifies the coordinates so you don't have to type two numbers, spots like a phone:
                                // 1 2 3
                                // 3 4 5
                                // 7 8 9                                
                                int row = (position - 1) / 3;
                                int col = (position - 1) % 3;
                                // if the move is valid, set it and flag true
                                if (position >= 1 && position <= 9 && board.is_valid_move(row, col)) {
                                    board.set_value(row, col, 'x');
                                    validMove = true;
                                } else {
                                    // reject and force reprompt
                                    std::cout << "Invalid move. Try again." << std::endl;
                                }
                            }
                        } else {
                            // Computer's turn, = 1
                            std::cout << "Computer's turn..." << std::endl;
                            board.choose_move(); // Computer does its move
                        }

                        // Print the board after each turn
                        board.print_board();

                        // Check for a winner
                        if (board.check_winner()) {
                            if (currentPlayer == 0) {
                                std::cout << "Congratulations, you win!" << std::endl;
                                board.inc_player_score();
                            } else {
                                std::cout << "Computer wins! Better luck next time!" << std::endl;
                                board.inc_comp_score();
                            }
                            gameOver = true;
                        } else {
                            // Check for a draw
                            bool draw = true;
                            for (int row = 0; row < 3; ++row) {
                                for (int col = 0; col < 3; ++col) {
                                    if (board.is_valid_move(row, col)) {
                                        draw = false;
                                        break;
                                    }
                                }
                                if (!draw) break;
                            }
                            // draw flag triggered!
                            if (draw) {
                                std::cout << "It's a draw!" << std::endl;
                                gameOver = true;
                            }
                        }

                        // Switch turns
                        currentPlayer = 1 - currentPlayer;
                    }

                    // print scores
                    std::cout << "=====SCORES=====" << std::endl;
                    std::cout << "You: " << board.get_player_score() << std::endl;
                    std::cout << "Computer: " << board.get_comp_score() << std::endl;
                    std::cout << "================" << std::endl;

                    // Play again?
                    char response;
                    std::cout << "Play again? (y/n): ";
                    std::cin >> response;
                    playAgain = (response == 'y' || response == 'Y');
                }

                std::cout << "Thanks for playing!" << std::endl;

                break;
            }
            // Used for quick testing, should have some good numbers for math operations
            case 10: {
                std::cout << "Create Demo Matrices" << std::endl;
                // create 4 sample matrixices
                Matrix newMatrixOne(3, 3);
                Matrix newMatrixTwo(3, 3);
                Matrix newMatrixThree(4, 4);
                Matrix newMatrixFour(4, 4);

                // Add some values to all 4 matrices
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        newMatrixOne.set_value(j, i, 2 * (1+j) * (1+i));
                        newMatrixTwo.set_value(j, i, 3 * (j+1) * (1+i));
                    }
                }

                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 4; j++){
                        newMatrixThree.set_value(j, i, 10 * (j+1) * (i+1) );
                        newMatrixFour.set_value(j, i, 5 * (j + 1) * (1 + i));
                    }
                }

                // add to store
                add_matrix("Test Matrix 1", newMatrixOne);
                add_matrix("Test Matrix 2", newMatrixTwo);
                add_matrix("Test Matrix 3", newMatrixThree);
                add_matrix("Test Matrix 4", newMatrixFour);
                break;
            }
            case 11: {
                std::cout << "Does this Matrix Contain a Value? selected" << std::endl;
                // empty case
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }

                // Get the chosen matrix
                Matrix& selectedMatrix = store[selectedIndex].matrix;

                int searchValue;
                std::cout << "Enter the value to search for: ";
                std::cin >> searchValue;

                std::string doesContain = selectedMatrix.search(searchValue) ? " DOES contain " : " does not contain ";
                std::cout << store[selectedIndex].name << doesContain << " " << searchValue << std::endl;
                }
                break;
            }

            case 12: {
                std::cout << "Get Value Coordinates" << std::endl;
                // empty case
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }

                // Get the chosen matrix
                Matrix& selectedMatrix = store[selectedIndex].matrix;

                int searchValue;
                std::cout << "Enter the value to search for: ";
                std::cin >> searchValue;

                // Check if the value is in the matrix, if not show user
                if(!selectedMatrix.search(searchValue)){
                    std::cout << searchValue << " is not an entry in " << store[selectedIndex].name << std::endl;
                } else {
                    // return the coordinates
                    std::pair<int, int> coodinates = store[selectedIndex].matrix.get_coordinates(searchValue);
                    std::cout << "(" << coodinates.first << " , " << coodinates.second << ")" << std::endl;
                }
                }
                break;
            }
            case 13: {
                std::cout << "Transpose a Matrix" << std::endl;
                // empty case
                if (store.empty()) {
                    std::cout << "No matrices available." << std::endl
                              << std::endl;
                } else {
                    std::cout << "Please enter a matrix (0 - " << store.size() << "):" << std::endl;
                    for (int i = 0; i < store.size(); i++) {
                        // For each node -- log name, and print matrix
                        MatrixNode& node = store[i];
                        std::cout << i << ") " << node.name << std::endl;
                    }
                    std::cout << "------------------- " << std::endl;
                // Get user input for matrix selection
                int selectedIndex;
                std::cout << "Enter your choice: ";
                std::cin >> selectedIndex;

                // Validate selection
                if (selectedIndex < 0 || selectedIndex >= store.size()) {
                    std::cout << "Invalid selection. Returning to menu." << std::endl;
                    break;
                }

                // Get the chosen matrix
                Matrix& selectedMatrix = store[selectedIndex].matrix;
                // Create the transposed
                Matrix transposedMatrix = transpose_matrix(selectedMatrix);
                // add to strore
                add_matrix("Transpose of " + store[selectedIndex].name, transposedMatrix);
                std::cout << "Matrix transposed!" << std::endl;
                /// show
                std::cout << "Transposed Matrix:" << std::endl;
                transposedMatrix.print_matrix();

                std::cout << "Returning to main menu..." << std::endl << std::endl;
            }
                break;
            }
            default:
            // Handle invalid input
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
    } while (true);
}


// Add a matrix to the store with a given name
void MatrixStore::add_matrix(const std::string& name, Matrix& matrix) {
    MatrixNode newMatrix;
    newMatrix.name = name;
    newMatrix.matrix = matrix;

    // Add the new MatrixNode to the store vector
    store.push_back(newMatrix);
    std::cout << name << "' added to the store." << std::endl;
}

// TO DO -- looks right but isnt implemented anywhere yet
// Get a matrix by its name. NEED TO TEST.
// Can use for update or sort?
Matrix* MatrixStore::get_matrix(std::string& name) {
    // iterate over the store and return the pointer
    for (int i = 0; i < store.size(); i++){
        MatrixNode &node = store[i];
        if(node.name == name){
            return &node.matrix;
        }
    }
        return nullptr;
}

// Remove a matrix by its name
bool MatrixStore::remove_matrix(std::string& name) {
    // iterate through the store
    for (int i = 0; i < store.size(); i++) {
        // Check if the current node matches the name
        if (store[i].name == name) {
            store.erase(store.begin() + i);
            // if we find it, return true
            return true;
        }
    }
    // Matrix not found
    return false;
}

// Print all matrices and their names
void MatrixStore::print_store() {
    // handle an empty store
    if (store.empty()) {
        std::cout << "No matrices available." << std::endl;
    } else {
        for (int i = 0; i < store.size(); i++) {
            MatrixNode& node = store[i];
            std::cout << "Matrix Name: " << node.name << std::endl;
            node.matrix.print_matrix();
            std::cout << "------------";
            std::cout << std::endl;
        }
    }
}
// // Math functions - should prompt the user to select 2 matricies and then do the operation
Matrix MatrixStore::add_matrices(Matrix &matrixA, Matrix &matrixB){
    Matrix newSums(matrixA.get_width(), matrixA.get_height()); // init a new matrix
    if((matrixA.get_height() == matrixB.get_height()) && (matrixB.get_width() == matrixA.get_width())){
        for (int i = 0; i < newSums.get_width(); i++)
        {
            for (int j = 0; j < newSums.get_height(); j++){
                newSums.set_value(j, i, matrixA.get_value(j,i) + matrixB.get_value(j,i));
            }
        }
        }
    return newSums;
};
Matrix MatrixStore::subtract_matrices(Matrix &matrixA, Matrix &matrixB){
    Matrix subMatrix(matrixA.get_width(), matrixA.get_height()); // init a new matrix
    if((matrixA.get_height() == matrixB.get_height()) && (matrixB.get_width() == matrixA.get_width())){
        for (int i = 0; i < subMatrix.get_width(); i++)
        {
            for (int j = 0; j < subMatrix.get_height(); j++){
                subMatrix.set_value(j, i, matrixA.get_value(j,i) - matrixB.get_value(j,i));
            }
        }
    }
    return subMatrix;
};
// You can only multiply if A height = B width! Else, reject

/*
1 2 3
4 5 6

and 

7    8
9   10
11  12


would be...
(1, 2, 3) • (7, 9, 11) = 1×7 + 2×9 + 3×11 = 58
// final matrix
58  x
x   x


 */

// TO DO: swap the two values if the shared dimension is the reverse
Matrix MatrixStore::multiply_matrices(Matrix &matrixA, Matrix &matrixB){
    // TO DO:: Figure this out
    // if (matrixA.get_width() != matrixB.get_height() && matrixB.get_width() == matrixA.get_height()){
        
    // }
    // init combined matrix
    Matrix multMatrix(matrixA.get_height(), matrixB.get_width());
    // get commons
    int common = matrixA.get_width(); // this is our shared dimension!
    if (matrixA.get_width() == matrixB.get_height())
    {
        for (int i = 0; i < matrixA.get_height(); i++) {
        for (int j = 0; j < matrixB.get_width(); j++) {
            int sum = 0;
            for (int k = 0; k < common; k++) {
                sum += matrixA.get_value(k, i) * matrixB.get_value(j, k);
            }
            multMatrix.set_value(j, i, sum);
        }
    }
    }
    return multMatrix;
};
Matrix MatrixStore::invert_matrix(Matrix &matrix){
    int height = matrix.get_height();
    int width = matrix.get_width();
    // init new inverted matrix
    Matrix inverted = Matrix(height, width);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j) {
            inverted.set_value(i, j, matrix.get_value(i, j) * (-1));
        }
    }
    return inverted;
}
Matrix MatrixStore::sort_matrix(Matrix &matrix, int sort){
    // row 0
    // col 1
    int height = matrix.get_height();
    int width = matrix.get_width();
    // Init sorted
    Matrix sorted = Matrix(height, width);
    // valid sort
    if(sort <= 1){
        if(sort == 0){
            // column sort
            for (int row = 0; row < height; row++) {
                std::vector<int> data;

                // get data
                for (int col = 0; col < width; col++) {
                    data.push_back(matrix.get_value(row, col));
                }

                // Use bubblesort!
                bubblesort(data);

                // write the data back into the new matrix
                for (int col = 0; col < width; col++) {
                    sorted.set_value(row, col, data[col]);
                }
            }
        } else {
            // row sort
            for (int col = 0; col < width; col++) {
                std::vector<int> data;

                // collect the column data
                for (int row = 0; row < height; row++) {
                    data.push_back(matrix.get_value(row, col));
                }

                // Use bubblesort
                bubblesort(data);

                // Then write back into new matrix
                for (int row = 0; row < height; row++) {
                    sorted.set_value(row, col, data[row]);
                }
            }
        }
    // invalid sort
    } else {
        std::cout << "Chose a sort that isn't specified" << std::endl;
    }

    return sorted;
}
Matrix MatrixStore::transpose_matrix(Matrix &matrix){
    int height = matrix.get_height();
    int width = matrix.get_width();
    // Init transposed, swap height and width
    Matrix transposed = Matrix(height, width);
    // Iterate over original, set values of  the transpose 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            transposed.set_value(i, j, matrix.get_value(j, i));
        }
    }
    return transposed;
}
// Bubblesort from past homework works for this!
void MatrixStore::bubblesort(std::vector<int>& data) {
  int dataLength = data.size();

  for (int i = 0; i < dataLength - 1; i++) {
    bool unsorted = false; // flag var

    for (int j = 0; j < dataLength - 1 - i; j++) {
      int first = data[j];
      int second = data[j + 1];
    // swap
      if (first > second) {
        data[j] = second;
        data[j + 1] = first;
        unsorted = true;
      }
    }

    // sorted!
    if (!unsorted) {
      break;
    }
  }
}