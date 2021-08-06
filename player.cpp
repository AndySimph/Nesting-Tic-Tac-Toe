//Function file for the player class

//Libraries
#include "player.h"

//Constructor
player::player() {

};
        
//Destructor      
player::~player() {

};

//Function to create the entities
void player::create_entities() {

    //Initialize the pieces
    int j = 0;
    for (int i = 0; i < 6; i++) {

        //Temporary entity
        entity temp_ent;

        //Increment every two pieces
        if ((i % 2) == 0) {
            j++;
        }

        //Assign the color and value
        temp_ent._color = _color;
        temp_ent._val = j;

        //Push the entity piece into the vector
        _pieces.push_back(temp_ent);
    }

    return;
};

//Function to print the entity values
void player::print_val() {

    //Print team
    std::cout << _color << ": ";

    //Print for each entity piece
    for(int i = 0; i < _pieces.size(); i++) { 

        //Print the value of each available piece
        if (_pieces[i]._used == false) {
            std::cout <<  _pieces[i]._val;

            //Give uniqueness between each piece of the same size
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