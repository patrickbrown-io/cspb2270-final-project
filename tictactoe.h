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
         */
        void print_board();
        char get_value(int row, int col);
        bool set_value(int row, int col, char player);
        bool check_winner();
        void choose_move(); // to do -- we can try to make this better, computer can't block moves atm.
        void inc_player_score();
        void inc_comp_score();
        int get_player_score();
        int get_comp_score();
        void set_player_score();
        void set_comp_score();
        bool is_valid_move(int row, int col);
        void clear_board();

    private:
        std::vector<std::vector<char> > data; // valid chars = { x , o , - )
        int playerScore;
        int computerScore;
};

#endif