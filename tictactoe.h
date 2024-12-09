#ifndef TICTACTOE_H__
#define TICTACTOE_H__

#include <vector>
#include <iostream>

class TicTacToe{
    public:
        // constructor
        TicTacToe();
        // destructor
        ~TicTacToe(){};

        // TO DO -- make the game, functions, computer.
        // Steps:
        /**
         * Print current score, if score
         * 1st actor, check score, second actor, check score
         * If winner, add to that players scoreboard, display prompt to play again
         * If board is full, mark tie.
         * Loser goes first. If tie, player goes
         */
        void print_board();
        char get_value(int row, int col);
        bool set_value(int row, int col, char player);
        bool check_winner();

    private:
        std::vector<std::vector<char> > data; // valid chars = { x , o , - )
};



#endif