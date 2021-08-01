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

        //Functions
        void player_move();
        void print_board();

        //Variables
        char _board[9];     //For board

        player _player1;    //For players
        player _player2;

    private:

};