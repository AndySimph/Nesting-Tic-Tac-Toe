//Programmer: Andy Simphaly

//Libraries
#include "game.h"

void game_loop(game Game) {

    Game.print_board();

    return;
};

int main() {

    //Variables
    game Game;
    bool play = true;
    int i = 0;

    //Loop while play is true
    while(play) {

        //Call the game loop
        game_loop(Game);

        i++;

        if (i == 3) {
            play = false;
        }

    }

    return 0;
};