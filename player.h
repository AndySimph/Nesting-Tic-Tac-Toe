//Header file for the player class

//Libraries
#include <iostream>
#include <vector>

#include "entity.h"

#pragma once

//Player class
class player {

    public:
        //Constructor and Destructor
        player();
        ~player();

        void create_entities();
        void print_val();

        //Vector of entities
        std::vector<entity> _pieces;

        //Variables
        char _color;

    private:

};