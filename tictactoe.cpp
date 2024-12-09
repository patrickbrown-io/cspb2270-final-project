#include "tictactoe.h"

// init 3x3 board with - as placeholders

TicTacToe::TicTacToe() : data(3, std::vector<char>(3, '-')) {}


// Same as matrix
void TicTacToe::print_board(){
    for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        std::cout << data[i][j] << " ";
    }
    std::cout << std::endl;
}
}