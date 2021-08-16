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
        _board[i] = temp_char;
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

    //If statement to decide which player turn it is
    if (player == 'w') {
        //Get player input
        std::cout << player << ":  Give move: (1a-2)" << std::endl;
        std::cin >> user_input;

        //Parse the user input
        parse_input(user_input, parsed_input);
        
        //Output the parsed string
        for (int i = 0; i < parsed_input.size(); i++) {
            std::cout << parsed_input[i] << " ";
        }
        std::cout << std::endl;

        std::cout << parsed_input[0][0];
        std::cout << std::stoi(parsed_input[1]) << std::endl << std::endl;
        _board[std::stoi(parsed_input[1])] = (parsed_input[0][0]);

    } else {
        std::cout << player << std::endl;
    }

    return;
}

//Function to parse the user input
void game::parse_input(std::string user_input, std::vector<std::string> &parsed_input) {
    
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
        std::cout << _board[i];

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
    std::cout << std::endl;

    //Print player2 available pieces
    _player2.print_val();
    std::cout << std::endl;

    return;
};