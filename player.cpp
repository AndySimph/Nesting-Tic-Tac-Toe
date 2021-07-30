//Function file for the player class

//Libraries
#include "player.h"

//Constructor
player::player() {

    int j = 0;
    for (int i = 0; i < 6; i++) {
        if ((i % 2) == 0) {
            j++;
        }
        _value.push_back( std::make_pair(j, false) );
    }

};
        
//Destructor      
player::~player() {

};

void player::print_val() {

    //Print each 
    for(int i = 0; i < _value.size(); i++) {
        std::cout << _value[i].first << " ";
    if (_value[i].second == false) {
        std::cout << "false";
    } else {
        std::cout << "true";
    }
    std::cout << std::endl;
    }

    std::cout << _color << std::endl;

    return;
};