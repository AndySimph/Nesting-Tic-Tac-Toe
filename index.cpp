//Programmer: Andy Simphaly

//Libraries
#include "game.h"

//Game loop function
void game_loop(game & Game, int &turn) {

    //Do player move
    if ((turn % 2) == 1) {
        //player1 turn
        Game.player_move(Game._players[0]._color);

    } else {
        //player2 turn
        Game.player_move(Game._players[1]._color);

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
    char winner;

    //Print the board
    Game.print_board();

    //Loop while play is true
    while(play) {

        //Call the game loop
        game_loop(Game, turn);

        if (turn == 12) {
            play = false;
        }

        //Check if a win occurs
        if (Game.check_win('w')) {
            //Set winner and stop playing
            winner = 'w';
            play = false;

        } else if (Game.check_win('b')) {
            //Set winner and stop playing
            winner = 'b';
            play = false;
        }
    }

    if (winner == 'w') {
        std::cout << "Winner is player 1!" << std::endl;
    } else {
        std::cout << "Winner is player 2!" << std::endl;
    }

    return 0;
};