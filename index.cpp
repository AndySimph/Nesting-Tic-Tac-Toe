//Programmer: Andy Simphaly

//Libraries
#include "game.h"

//Game loop function
void game_loop(game & Game, int &turn) {

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

    //Print the board
    Game.print_board();

    return;
};

int main() {

    //Variables
    game Game;
    bool play = true;
    int turn = 1;

    //Print the board
    Game.print_board();

    //Loop while play is true
    while(play) {

        //Call the game loop
        game_loop(Game, turn);

        if (turn == 3) {
            play = false;
        }

        Game.print_board();

    }

    return 0;
};