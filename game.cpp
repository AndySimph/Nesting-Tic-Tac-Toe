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
    std::cout << player << ":  Give move: (1a-2)" << std::endl;
    std::cin >> user_input;

    //Parse the user input
    parse_input(user_input, parsed_input);
    

    //If statement to decide which player turn it is
    if (player == 'w') {
    
        //Output the parsed string
        // for (int i = 0; i < parsed_input.size(); i++) {
        //     std::cout << parsed_input[i] << " ";
        // }
        // std::cout << std::endl;

        std::cout << parsed_input[0][0] << " ";
        std::cout << std::stoi(parsed_input[1]) << std::endl << std::endl;

        //Check if the spot is between 0-8
        if ((std::stoi(parsed_input[1]) < 9) && (std::stoi(parsed_input[1]) >= 0)) {
            //Check if the entity has been used and exists
            int i = 0;
            bool used = false;

            //Loop to check if one of the piece is available
            while (!used) {
                //Check the piece is correct
                if ((_player1._pieces[i]._val == ((parsed_input[0][0]) - '0')) && (!_player1._pieces[i]._used)) {
                    //Set the piece to used
                    _player1._pieces[i]._used = true;

                    //Check if the spot on the board is available
                    if (_board[std::stoi(parsed_input[1])]._used == false) {
                        // _board[std::stoi(parsed_input[1])]._char = (parsed_input[0][0]);
                        // _board[std::stoi(parsed_input[1])]._char = 'w';
                        // _board[std::stoi(parsed_input[1])]._val = int(parsed_input[0][0] - '0');
                        place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), 'w');
                        _board[std::stoi(parsed_input[1])]._used = true;
                        // _board[std::stoi(parsed_input[1])]._color = 'w';
                        used = true;

                        std::cout << '\n' << _board[std::stoi(parsed_input[1])]._val << std::endl;

                    } else {
                        std::cout << "1" << std::endl;
                        used = true;
                    }

                } 

                //Increment the piece
                i++;

                if (i > _player1._pieces.size()) {
                    std::cout << "Invalid piece: choose again" << std::endl;
                    std::cin >> user_input;
                    std::cout << user_input << std::endl;

                    //Parse the new user input
                    parse_input(user_input, parsed_input);
    
                    std::cout << parsed_input[0][0] << " ";
                    std::cout << std::stoi(parsed_input[1]) << std::endl << std::endl;
                    i = 0;
                }
                
            }

        } else {
            //Output error
            std::cout << "Error" << std::endl;
        }

    } else {
        std::cout << parsed_input[0][0] << " ";
        std::cout << std::stoi(parsed_input[1]) << std::endl << std::endl;

        //Check if the spot is between 0-8
        if ((std::stoi(parsed_input[1]) < 9) && (std::stoi(parsed_input[1]) >= 0)) {
            
            //Check if the entity has been used and exists
            int i = 0;
            bool used = false;

            //Loop to check if one of the piece is available
            while (!used) {
                //Check the piece is correct
                if ((_player2._pieces[i]._val == ((parsed_input[0][0]) - '0')) && (!_player2._pieces[i]._used)) {
                    //Set the piece to used
                    _player2._pieces[i]._used = true;

                    //Check if the spot on the board is available
                    if (_board[std::stoi(parsed_input[1])]._used == false) {
                        // _board[std::stoi(parsed_input[1])]._char = (parsed_input[0][0]);
                        // _board[std::stoi(parsed_input[1])]._char = 'b';
                        // _board[std::stoi(parsed_input[1])]._val = int(parsed_input[0][0] - '0');
                        place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), 'b');
                        _board[std::stoi(parsed_input[1])]._used = true;
                        // _board[std::stoi(parsed_input[1])]._color = 'b';
                        used = true;

                    //Check if the board position value is lower than the piece
                    } else if (_board[std::stoi(parsed_input[1])]._val < int(parsed_input[0][0] - '0')) {
                        // _board[std::stoi(parsed_input[1])]._char = 'b';
                        // _board[std::stoi(parsed_input[1])]._val = int(parsed_input[0][0] - '0');
                        // _board[std::stoi(parsed_input[1])]._color = 'b';
                        place_piece(std::stoi(parsed_input[1]), int(parsed_input[0][0] - '0'), 'b');
                        used = true;

                    } else {
                        std::cout << "3" << std::endl;
                        used = true;
                    }

                }

                //Increment the piece
                i++;

                //Check if the we have loop through all the pieces
                if (i > _player2._pieces.size()) {
                    std::cout << "Invalid piece: choose again" << std::endl;
                    std::cin >> user_input;
                    std::cout << user_input << std::endl;

                    //Parse the new user input
                    parse_input(user_input, parsed_input);
    
                    std::cout << parsed_input[0][0] << " ";
                    std::cout << std::stoi(parsed_input[1]) << std::endl << std::endl;
                    i = 0;
                }
            }

        } else {
            //Output error
            std::cout << "Error" << std::endl;
        }
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

void game::place_piece(int loc, int val, char color) {

    _board[loc]._char = color;
    _board[loc]._val = val;
    _board[loc]._color = color;

    return;
};

//Funtion to print the board
void game::print_board() {

    //Print player1 available pieces
    _player1.print_val();

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
    _player2.print_val();
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

