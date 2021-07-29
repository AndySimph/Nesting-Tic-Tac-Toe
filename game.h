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

        //Variables
        char _board[9];

    private:

};