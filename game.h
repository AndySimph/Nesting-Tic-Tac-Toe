//Header file for the game class

//Libraries
#include <iostream>
#include <vector>
#include <string>

#include "player.h"
#include "board_ent.h"

#pragma once

//Game class
class game {

    public:
        //Constructor and Destructor
        game();
        ~game();

        //Functions
        void player_move(char player);
        void parse_input(std::string user_input, std::vector<std::string> &parsed_input);
        void place_piece(int loc, int val, char color);
        void move_logic(int num, std::string &user_input, std::vector<std::string> &parsed_input, char col);
        bool check_win(char color);
        void print_board(); 

        //Variables
        board_ent _board[9];   //For board
        player _players[2];    //For players

    private:

};