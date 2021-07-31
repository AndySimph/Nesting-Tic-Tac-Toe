//Programmer: Andy Simphaly

//Libraries
#include "game.h"

void game_loop(game Game, int &turn) {

    // if ((turn % 2) == 1) {
    //     //player1 turn
    // }



    Game.print_board();

    turn++;

    return;
};

int main() {

    //Variables
    game Game;
    bool play = true;
    int turn = 1;

    //Loop while play is true
    while(play) {

        //Call the game loop
        game_loop(Game, turn);

        if (turn == 4) {
            play = false;
        }

    }

    return 0;
};