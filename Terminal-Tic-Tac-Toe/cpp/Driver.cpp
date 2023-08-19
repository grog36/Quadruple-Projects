#include "Game.h"

//TODO
//Fix segmentation fault
int main() {
    //Initializes the test game
    Game game = Game(2);
    Board* testBoard = game.getBoard();

    //Plays move to set a board up
    testBoard->playMove(0, 0); //TopLeft
    testBoard->playMove(0, 2); //TopRight
    testBoard->playMove(2, 2); //BottomRight
    testBoard->playMove(1, 1); //Center
    testBoard->playMove(2, 0); //BottomLeft
    testBoard->playMove(1, 0); //MiddleLeft
    std::cout << testBoard->getStatus() << std::endl;




    Coordinate bestMove = game.findBestMove();
    testBoard->playMove(bestMove.getRowIndex(), bestMove.getColumnIndex());
    std::cout << testBoard->getStatus() << std::endl;
}
