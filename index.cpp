//Programmer: Andy Simphaly

//Libraries
#include "game.h"

//Game loop function
void game_loop(game Game, int &turn) {

    //Print the board
    Game.print_board();

    //Do player move
    if ((turn % 2) == 1) {
        //player1 turn
        Game.player_move(Game._player1._color);

    } else {
        //player2 turn
        Game.player_move(Game._player2._color);

    }

    //Increment turn
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

        if (turn == 2) {
            play = false;
        }

    }

    return 0;
};