//Function file for the game class

//Libraries
#include "game.h"

//Constructor
game::game() {

    char temp_char;

    //Initialize the board
    for (int i = 0; i <= 8; i++) {
        //Place a marker within each box
        temp_char = '0' + i;
        _board[i]._char = temp_char;
    }

    //Initialize each player color and entities
    _player1._color = 'w';
    _player1.create_entities();

    _player2._color = 'b';
    _player2.create_entities();

    //Init the colors
    _players[0]._color = 'w';
    _players[1]._color = 'b';

    //Loop through each of the players and create the entities
    for (int i = 0; i < 2; i++) {
        _players[i].create_entities();
    }

};
        
//Destructor      
game::~game() {

};

//Function for a player move
void game::player_move(char player) {

    //Variables
    std::string user_input;
    std::vector<std::string> parsed_input;

    //Get player input
    std::cout << player << ":  Give move: (1-2), (piece value-location)" << std::endl;
    std::cin >> user_input;

    //Parse the user input
    parse_input(user_input, parsed_input);
    
    //If statement to decide which player turn it is
    if (player == 'w') {

        move(0, user_input, parsed_input, 'w');

        // //Check if the spot is between 0-8
        // if ((std::stoi(parsed_input[1]) < 9) && (std::stoi(parsed_input[1]) >= 0)) {
        //     //Check if the entity has been used and exists
        //     int i = 0;
        //     bool used = false;

        //     //Loop to check if one of the piece is available
        //     while (!used) {
        //         //Check the piece is correct
        //         if ((_player1._pieces[i]._val == ((parsed_input[0][0]) - '0')) && (!_player1._pieces[i]._used)) {
        //             //Check if the spot on the board is available
        //             if (_board[std::stoi(parsed_input[1])]._used == false) {
        //                 //Place the piece
        //                 place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), 'w');
                        
        //                 //Set the piece to used
        //                 _player1._pieces[i]._used = true;
        //                 _board[std::stoi(parsed_input[1])]._used = true;
        //                 used = true;

        //             //Check if the board position value is lower than the piece
        //             } else if (_board[std::stoi(parsed_input[1])]._val < int(parsed_input[0][0] - '0')) {
        //                 //Place the piece
        //                 place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), 'w');
        //                 //Set the piece to used
        //                 _player1._pieces[i]._used = true;
        //                 used = true;

        //             } else {
        //                 //Get new input
        //                 std::cout << "Invalid location: choose again" << std::endl;
        //                 std::cin >> user_input;
        //                 std::cout << user_input << std::endl;

        //                 //Parse the new user input
        //                 parse_input(user_input, parsed_input);
        
        //                 //Reset counter
        //                 i = -1;
        //             }

        //         } 

        //         //Increment the piece
        //         i++;

        //         if (i > _player1._pieces.size()) {
        //             //Get new input
        //             std::cout << "Invalid piece: choose again" << std::endl;
        //             std::cin >> user_input;
        //             std::cout << user_input << std::endl;

        //             //Parse the new user input
        //             parse_input(user_input, parsed_input);

        //             //Reset counter
        //             i = 0;
        //         }
                
        //     }

        // } else {
        //     //Output error
        //     std::cout << "Error" << std::endl;
        // }

    } else {

        move(1, user_input, parsed_input, 'b');

    //     //Check if the spot is between 0-8
    //     if ((std::stoi(parsed_input[1]) < 9) && (std::stoi(parsed_input[1]) >= 0)) {
    //         //Check if the entity has been used and exists
    //         int i = 0;
    //         bool used = false;

    //         //Loop to check if one of the piece is available
    //         while (!used) {
    //             //Check the piece is correct
    //             if ((_player2._pieces[i]._val == ((parsed_input[0][0]) - '0')) && (!_player2._pieces[i]._used)) {
    //                 //Check if the spot on the board is available
    //                 if (_board[std::stoi(parsed_input[1])]._used == false) {
    //                     //Place the piece
    //                     place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), 'b');

    //                     //Set the piece to used
    //                     _player2._pieces[i]._used = true;
    //                     _board[std::stoi(parsed_input[1])]._used = true;
    //                     used = true;

    //                 //Check if the board position value is lower than the piece
    //                 } else if (_board[std::stoi(parsed_input[1])]._val < int(parsed_input[0][0] - '0')) {
    //                     //Place the piece
    //                     place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), 'b');

    //                     //Set the piece to used
    //                     _player2._pieces[i]._used = true;
    //                     used = true;

    //                 } else {
    //                     //Get new input
    //                     std::cout << "Invalid location: choose again" << std::endl;
    //                     std::cin >> user_input;
    //                     std::cout << user_input << std::endl; 

    //                     //Parse the new user input
    //                     parse_input(user_input, parsed_input);
        
    //                     //Reset counter
    //                     i = -1;
    //                 }

    //             }

    //             //Increment the piece
    //             i++;

    //             //Check if the we have loop through all the pieces
    //             if (i > _player2._pieces.size()) {
    //                 //Get new input
    //                 std::cout << "Invalid piece: choose again" << std::endl;
    //                 std::cin >> user_input;
    //                 std::cout << user_input << std::endl;

    //                 //Parse the new user input
    //                 parse_input(user_input, parsed_input);
    
    //                 //Reset counter
    //                 i = 0;
    //             }
    //         }

    //     } else {
    //         //Output error
    //         std::cout << "Error" << std::endl;
    //     }
    }

    return;
}

//Function to parse the user input
void game::parse_input(std::string user_input, std::vector<std::string> &parsed_input) {
    //Clear the existing vector
    parsed_input.clear();
    
    //Delimiter to parse the string
    std::string delimiter = "-";

    //Position of where to parse
    size_t pos = 0;

    //Check if delimiter exist
    if (user_input.find(delimiter) == std::string::npos) {
        //Loop until correct input
        while (user_input.find(delimiter) == std::string::npos) {
            //Output and input
            std::cout << "Invalid Input, try again:";
            std::cin >> user_input;
        } 
    } 

    //Loop to find the delimiter
    while ((pos = user_input.find(delimiter)) != std::string::npos) {
        //Push back the initial part of the parsed string
        parsed_input.push_back(user_input.substr(0, pos));
        
        //Erase the initial part of the parsed string
        user_input.erase(0, pos + delimiter.length());
    }
    
    //Push the final part of the parsed string
    parsed_input.push_back(user_input);

    return;
};

//Function to place a piece
void game::place_piece(int loc, int val, char color) {

    //Check color of player
    if (color == 'w') {
        //Switch case to choose what char to place
        switch (val) {
            case 1:
                _board[loc]._char = 'R';
                break;

            case 2:
                _board[loc]._char = 'Q';
                break;

            case 3:
                _board[loc]._char = 'K';
                break;
        
        }

    } else {
        //Switch case to choose what char to place
        switch (val) {
            case 1:
                _board[loc]._char = 'r';
                break;

            case 2:
                _board[loc]._char = 'q';
                break;

            case 3:
                _board[loc]._char = 'k';
                break;
        
        }

    }

    //Set value and color
    _board[loc]._val = val;
    _board[loc]._color = color;

    return;
};

//Function to check win conditions
bool game::check_win(char color) {
    //Locations to check;
    int loc [5] = {1, 3, 4, 5, 7};

    //Bool for win
    bool win = false;

    //Loop through each
    for (int i = 0; i < 4; i++) {
        //Switch case for each of the numbers to check
        switch (loc[i]) {
            //*|*|*
            //----- 
            // | |
            //-----
            // | | 
            case 1:
                if (_board[loc[i]]._color == color) {
                    if ((_board[loc[i] - 1]._color == color) && (_board[loc[i] + 1]._color == color)) {
                        win = true;
                    } 
                }
                break;

            //*| | 
            //----- 
            //*| |
            //-----
            //*| | 
            case 3:
                if (_board[loc[i]]._color == color) {
                    if ((_board[loc[i] - 3]._color == color) && (_board[loc[i] + 3]._color == color)) {
                        win = true;
                    }
                }
                break;

            //*|*|*
            //----- 
            //*|*|*
            //-----
            //*|*|* 
            case 4:
                if (_board[loc[i]]._color == color) {
                    //Loop through each possible win and check
                    for (int j = 1; j < 5; j++) {
                        if ((_board[loc[i] - j]._color == color) && (_board[loc[i] + j]._color == color)) {
                            win = true;
                            break;
                        }
                    }
                }
                break;

            // | |*
            //----- 
            // | |*
            //-----
            // | |* 
            case 5:
                if (_board[loc[i]]._color == color) {
                    if ((_board[loc[i] - 3]._color == color) && (_board[loc[i] + 3]._color == color)) {
                        win = true;
                    }
                }
                break;

            // | | 
            //----- 
            // | |
            //-----
            //*|*|*
            case 7:
                if (_board[loc[i]]._color == color) {
                    if ((_board[loc[i] - 1]._color == color) && (_board[loc[i] + 1]._color == color)) {
                        win = true;
                    }
                }
                break;

        }

        //Break the loop if a win occurs
        if (win) {
            break;
        }
    }

    return win;
};

//Funtion to print the board
void game::print_board() {

    //Print player1 available pieces
    _players[0].print_val();

    //Print a bar
    for (int j = 0; j < 13; j++) {
        std::cout << "-";
    }
    std::cout << std::endl << "| ";

    //Loop through each element of the board
    for (int i = 0; i <= 8; i++) {
        //Print bars and the element
        std::cout << _board[i]._char;

        //Check if it is the element position is a multiple of 3
        if (((i+1)%3) == 0) {
            std::cout << " | " << std::endl;
            
            //Print a bar dividing each horizontal line
            for (int j = 0; j < 13; j++) {
                std::cout << "-";
            }
            if (i != 8) {
                std::cout << std::endl << "| ";
            }

        } else {
            std::cout << " | ";
        }
    }
    std::cout << std::endl << std::endl;

    //Print player2 available pieces
    _players[1].print_val();
    std::cout << std::endl;


    //Print the other variables of the board
    //Print a bar
    for (int j = 0; j < 13; j++) {
        std::cout << "-";
    }
    std::cout << std::endl << "| ";

    //Loop through each element of the board
    for (int i = 0; i <= 8; i++) {
        //Print bars and the element
        std::cout << _board[i]._color;

        //Check if it is the element position is a multiple of 3
        if (((i+1)%3) == 0) {
            std::cout << " | " << std::endl;
            
            //Print a bar dividing each horizontal line
            for (int j = 0; j < 13; j++) {
                std::cout << "-";
            }
            if (i != 8) {
                std::cout << std::endl << "| ";
            }

        } else {
            std::cout << " | ";
        }
    }
    std::cout << std::endl << std::endl;

    //Print a bar
    for (int j = 0; j < 13; j++) {
        std::cout << "-";
    }
    std::cout << std::endl << "| ";

    //Loop through each element of the board
    for (int i = 0; i <= 8; i++) {
        //Print bars and the element
        std::cout << _board[i]._val;

        //Check if it is the element position is a multiple of 3
        if (((i+1)%3) == 0) {
            std::cout << " | " << std::endl;
            
            //Print a bar dividing each horizontal line
            for (int j = 0; j < 13; j++) {
                std::cout << "-";
            }
            if (i != 8) {
                std::cout << std::endl << "| ";
            }

        } else {
            std::cout << " | ";
        }
    }
    std::cout << std::endl << std::endl;

    //Print a bar
    for (int j = 0; j < 13; j++) {
        std::cout << "-";
    }
    std::cout << std::endl << "| ";

    //Loop through each element of the board
    for (int i = 0; i <= 8; i++) {
        //Print bars and the element
        if (_board[i]._used) {
            std::cout << "T";
        } else {
            std::cout << "F";
        }

        //Check if it is the element position is a multiple of 3
        if (((i+1)%3) == 0) {
            std::cout << " | " << std::endl;
            
            //Print a bar dividing each horizontal line
            for (int j = 0; j < 13; j++) {
                std::cout << "-";
            }
            if (i != 8) {
                std::cout << std::endl << "| ";
            }

        } else {
            std::cout << " | ";
        }
    }
    std::cout << std::endl << std::endl;

    return;
};

//Area to test new player array
void game::move(int num, std::string &user_input, std::vector<std::string> &parsed_input, char col) {

    //Check if the spot is between 0-8
    if ((std::stoi(parsed_input[1]) < 9) && (std::stoi(parsed_input[1]) >= 0)) {
        //Check if the entity has been used and exists
        int i = 0;
        bool used = false;

        //Loop to check if one of the piece is available
        while (!used) {
            //Check the piece is correct
            if ((_players[num]._pieces[i]._val == ((parsed_input[0][0]) - '0')) && (!_players[num]._pieces[i]._used)) {
                //Check if the spot on the board is available
                if (_board[std::stoi(parsed_input[1])]._used == false) {
                    //Place the piece
                    place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), col);
                    
                    //Set the piece to used
                    _players[num]._pieces[i]._used = true;
                    _board[std::stoi(parsed_input[1])]._used = true;
                    used = true;

                //Check if the board position value is lower than the piece
                } else if (_board[std::stoi(parsed_input[1])]._val < int(parsed_input[0][0] - '0')) {
                    //Place the piece
                    place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), col);
                    //Set the piece to used
                    _players[num]._pieces[i]._used = true; 
                    used = true;

                } else {
                    //Get new input
                    std::cout << "Invalid location: choose again" << std::endl;
                    std::cin >> user_input;
                    std::cout << user_input << std::endl;

                    //Parse the new user input
                    parse_input(user_input, parsed_input);
    
                    //Reset counter
                    i = -1;
                }

            } 

            //Increment the piece
            i++;

            if (i > _players[num]._pieces.size()) {
                //Get new input
                std::cout << "Invalid piece: choose again" << std::endl;
                std::cin >> user_input;
                std::cout << user_input << std::endl;

                //Parse the new user input
                parse_input(user_input, parsed_input);

                //Reset counter
                i = 0;
            }
            
        }

    } else {
        //Output error
        std::cout << "Error" << std::endl;
    }


    return;
}