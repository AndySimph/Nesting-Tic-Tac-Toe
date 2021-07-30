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

        void print_val();

        //Vector of pairs to check
        std::vector<std::pair<int, bool> > _value;

        char color;

    private:

};