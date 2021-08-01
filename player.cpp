//Function file for the player class

//Libraries
#include "player.h"

//Constructor
player::player() {

    //Initialize the pieces
    int j = 0;
    for (int i = 0; i < 6; i++) {
        if ((i % 2) == 0) {
            j++;
        }
        _piece.push_back( std::make_pair(j, false) );
    }

};
        
//Destructor      
player::~player() {

};

void player::print_val() {

    //Print team
    std::cout << _color << ": ";

    //Print each available piece
    for(int i = 0; i < _piece.size(); i++) {
        if (_piece[i].second == false) {
            std::cout << _piece[i].first;
            if ((i%2) == 0) {
                std::cout << "a";
            } else {
                std::cout << "b";
            }
            std::cout << "  ";
        } 
    }
    std::cout << std::endl;

    return;
};