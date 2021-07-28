//Function file for the game class

//Libraries
#include "game.h"

//Constructor
game::game() {

    for (int i = 0; i <= 8; i++) {
        _board[i] = '.';
    }

};
        
//Destructor      
game::~game() {

};


void game::print_board() {

    
    for (int i = 0; i <= 8; i++) {
        std::cout << "| ";
        std::cout << _board[i];
        if (((i+1)%3) == 0) {
            std::cout << " | " << std::endl;
            
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