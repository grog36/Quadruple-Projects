#include "Board.h"

class Game {
    private:
        Board board;
        int playerCount;
    
    public:
        Game(int numOfPlayers) {
            if (numOfPlayers == 1 || numOfPlayers == 2) {
                playerCount = numOfPlayers;
                board = Board();
            }
            else {
                throw std::invalid_argument("Number of players argument must be 1 or 2");
            }
        }

        int getPlayerCount() {
            return playerCount;
        }

        Board* getBoard() {
            return &board;
        }


        //TODO:
        //Fix segmentation fault

        Coordinate findBestMove() {
            //If the game is not already over
            if (!(board.checkForWin(board.getPlayer1Marker()) || board.checkForWin(board.getPlayer2Marker()) || board.checkForTie())) {
                for (int i = 0; i < board.getEmptySpaces().size(); i++) {
                    Board tempBoard = Board(board);
                    Coordinate c = board.getEmptySpaces().at(i);
                    tempBoard.playMove(c.getRowIndex(), c.getColumnIndex());
                    if (tempBoard.checkForWin(board.getWhoseTurn())) {
                        return Coordinate(c.getRowIndex(), c.getColumnIndex());
                    }
                }
            }
            return Coordinate(100, 100);
        }
};