//Function file for the game class

//Libraries
#include "game.h"

//Constructor
game::game() {

    //Initialize the board
    for (int i = 0; i <= 8; i++) {
        _board[i] = ' ';
    }

    //Initialize the player color
    _player1._color = 'w';
    _player2._color = 'b';

};
        
//Destructor      
game::~game() {

};

//Funtion to print the board
void game::print_board() {

    //Print player1 available pieces
    _player1.print_val();

    //Print a bar
    for (int j = 0; j < 13; j++) {
        std::cout << "-";
    }
    std::cout << std::endl << "| ";

    //Loop through each element of the board
    for (int i = 0; i <= 8; i++) {
        //Print bars and the element
        std::cout << _board[i];

        //Check if it is the element position is a multiple of 3
        if (((i+1)%3) == 0) {
            std::cout << " | " << std::endl;
            
            //Print a bar dividing each horizontal line
            for (int j = 0; j < 13; j++) {
                std::cout << "-";
            }
            if (i != 8) {
                std::cout << std::endl << "| ";
            }

        } else {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;

    //Print player2 available pieces
    _player2.print_val();

    return;
};