#include "tictactoe.h"

// init 3x3 board with - as placeholders

/***
 * // Like a phone, pick a slot!
 * 
 *    - - -           1 2 3
 *    - - -   ===>    4 5 6
 *    - - -           7 8 9
 * 
 */

TicTacToe::TicTacToe() : data(3, std::vector<char>(3, '-')) {}


// Same as matrix
void TicTacToe::print_board(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << data[i][j] << " ";
        }
    std::cout << std::endl;
    }
}
// used to reset the board
void TicTacToe::clear_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = '-';
        }
    }
}
// setter, if valid
bool TicTacToe::set_value(int row, int col, char player){
    // valid
    if(is_valid_move(row, col)){
        data[row][col] = player;
         return true;
         // invalid
    } else {
        return false;
    }
}
// gets the value, used to check for winner
char TicTacToe::get_value(int row, int col){
    // only get it if its valid
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return data[row][col];
    }
    else {
        return '-';
    }
}

void TicTacToe::choose_move(){
    // on its turn, find an empty space if the board is not full. if there is already an o somewhere, pick another spot that can lead to a win (next to or diagnoal)
    // if first move, go in the middle, else find an empty spot
    // we could expand this decision to check if they can win to chose a winning move, if the player is going to win to make a block

    // if can do middle, do it.
    if(is_valid_move(1,1)){
        set_value(1, 1, 'o');
    } else {
    // find the next empty spot
        // Check if self is about to win, chose correctly
        // Check if player is about to win, block
        // ELSE go in a random spot
    // Check rows for a win
        // Check rows for a win
        // x x -, x - x, - x x
        // OR o o -, o - o, - o o
        // Check rows for potential wins or blocks
    for (int row = 0; row < 3; row++) {
        int cpuCount = 0, playerCount = 0, emptyCol = -1; // count the chars in a row
        for (int col = 0; col < 3; col++) {
            if (data[row][col] == 'o'){
                cpuCount++; 
            } 
            else if (data[row][col] == 'x') {
                playerCount++;
            }
            else {
                emptyCol = col;
            }
        }
        // if a row can win, place and win
        if (cpuCount == 2 && emptyCol != -1) {
            set_value(row, emptyCol, 'o');
            return;
        }
        // if player is about to win, block them!
        if (playerCount == 2 && emptyCol != -1) {
            set_value(row, emptyCol, 'o');
            return;
        }
    }

    // column checks -> same as row, if 2 player or cpu ACT
    for (int col = 0; col < 3; col++) {
        int cpuCount = 0, playerCount = 0, emptyRow = -1;
        for (int row = 0; row < 3; row++) {
            if (data[row][col] == 'o') cpuCount++;
            else if (data[row][col] == 'x') playerCount++;
            else emptyRow = row;
        }
        // If the CPU can win, complete the column, 2os and a blank
        if (cpuCount == 2 && emptyRow != -1) {
            set_value(emptyRow, col, 'o');
            return;
        }
        // If the player is about to win, block the column (2xs and a blank)
        if (playerCount == 2 && emptyRow != -1) {
            set_value(emptyRow, col, 'o');
            return;
        }
    }

    // First available spot fallback in case it all falls apart
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            // we find an open valid spot
            if (is_valid_move(row, col)) {
                set_value(row, col, 'o'); // act on it, doesn't matter
                return;
            }
        }
    }
    }
}

// checks that its within range, and is a blank
bool TicTacToe::is_valid_move(int row, int col) {
    // coordinates are correct?
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false;
    }
    // If empty, okay, else not okay
    if (data[row][col] == '-') {
        return true;
    }
    // not okay
    return false;
}

// Checks rows, cols, and then diagnoal coordinates for 3 matches
bool TicTacToe::check_winner() {
    // Check rows for a win
    for (int row = 0; row < 3; row++) {
        if (data[row][0] != '-' && data[row][0] == data[row][1] && data[row][1] == data[row][2]) {
            return true;
        }
    }

    // Check columns for winning
    for (int col = 0; col < 3; col++) {
        if (data[0][col] != '-' && data[0][col] == data[1][col] && data[1][col] == data[2][col]) {
            return true;
        }
    }

    // Diagonals!
    // Top-left to bottom-right diagonal win
    if (data[0][0] != '-' && data[0][0] == data[1][1] && data[1][1] == data[2][2]) {
        return true; 
    }
     // Top-right to bottom-left diagonal win
    if (data[0][2] != '-' && data[0][2] == data[1][1] && data[1][1] == data[2][0]) {
        return true;
    }

    return false; // No winner yet!
}

// Score setters and getters
void TicTacToe::inc_player_score(){
    playerScore++;
}
void TicTacToe::inc_comp_score(){
    computerScore++;
}
int TicTacToe::get_player_score(){
    return playerScore;
}
int TicTacToe::get_comp_score(){
    return computerScore;
}
// Set default state @ start of the game
void TicTacToe::set_player_score(){
    playerScore = 0;
}
void TicTacToe::set_comp_score(){
    computerScore = 0;
}