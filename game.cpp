//Function file for the game class

//Libraries
#include "game.h"

//Constructor
game::game() {

    for (int i = 0; i <= 8; i++) {
        _board[i] = ' ';
    }

};
        
//Destructor      
game::~game() {

};

//Funtion to print the board
void game::print_board() {

    //Loop through each element of the board
    for (int i = 0; i <= 8; i++) {
        //Print bars and the element
        std::cout << "| ";
        std::cout << _board[i];

        //Check if it is the element position is a multiple of 3
        if (((i+1)%3) == 0) {
            std::cout << " | " << std::endl;
            
            //Print a bar dividing each horizontal line
            for (int j = 0; j < 18; j++) {
                std::cout << "-";
            }
            std::cout << std::endl;

        } else {
            std::cout << " | ";
        }
    }

    return;
};