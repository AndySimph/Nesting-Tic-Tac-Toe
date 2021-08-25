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
        void print_board(); 
        //Variables
        char _board[9];     //For board
        board_ent _board2[9];

        player _player1;    //For players
        player _player2;

    private:

};