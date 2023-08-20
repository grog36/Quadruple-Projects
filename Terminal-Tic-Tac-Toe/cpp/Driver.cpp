#include "Game.h"

//TODO
//Fix segmentation fault
int main() {
    //Asks the user a few questions to determine how the game is to be played
    int playerCount;
    std::cout << "How many players (1 or 2): ";
    std::cin >> playerCount;
    Board board = Board(1);
    if (playerCount == 1) {
        std::string goFirst;
        std::cout << "Would you like to go first ('yes' or 'no'): ";
        std::cin >> goFirst;
        if (goFirst == "no") {
            board = Board(2);
        }
        else if (goFirst != "yes") {
            throw std::invalid_argument("Answer must be 'yes' or 'no'");
        }
    }
    else if (playerCount == 2) {
        int whoGoesFirst;
        std::cout << "Which player would like to go first (1 or 2): ";
        std::cin >> whoGoesFirst;
        board = Board(whoGoesFirst);
    }
    else {
        throw std::invalid_argument("Number of players argument must be 1 or 2");
    }

    //Sets up the game and starts it
    Game game = Game(board, playerCount);
    game.start();
}