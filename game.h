//Header file for the game class

//Libraries
#include <iostream>
#include <vector>

#include "player.h"

#pragma once

//Game class
class game {

    public:
        //Constructor and Destructor
        game();
        ~game();

        //Function to print the board;
        void print_board();
        void player_move();

        //Variables
        char _board[9];     //For board

        player _player1;    //For players
        player _player2;

    private:

};