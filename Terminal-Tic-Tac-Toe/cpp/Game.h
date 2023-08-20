#include "Board.h"

class Game {
    private:
        Board board = Board(1);
        int playerCount;

        //Asks for user input to play a move
        void requestCoordinate() {
            std::cout << board.toString() << std::endl;
            std::cout << "Player - '" << board.getWhoseTurn() << "'s turn." << std::endl;
            std::cout << "\nPlease enter the row you would like to place a marker (0-2): ";
            int rowNum = 3;
            std::cin >> rowNum;
            if (rowNum < 0 || rowNum > 2) {
                throw std::invalid_argument("Row# argument must be 0, 1, or 2");
            }
            std::cout << "\nPlease enter the column you like to place a marker (0-2): ";
            int colNum = 0;
            if (colNum < 0 || colNum > 2) {
                throw std::invalid_argument("Col# argument must be 0, 1, or 2");
            }
            std::cin >> colNum;
            bool validMove = board.playMove(rowNum, colNum);
            if (!validMove) {
                std::cout << "\n\n\nNot a valid move. Please try again.\n\n\n";
                requestCoordinate();
            }
            
        }
    
    public:
        Game(int numOfPlayers, int whoGoesFirst) {
            if (numOfPlayers == 1 || numOfPlayers == 2) {
                playerCount = numOfPlayers;
                board = Board(whoGoesFirst);
            }
            else {
                throw std::invalid_argument("Number of players argument must be 1 or 2");
            }
        }
        Game(Board defaultBoard, int numOfPlayers) {
            if (numOfPlayers == 1 || numOfPlayers == 2) {
                playerCount = numOfPlayers;
                board = defaultBoard;
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


        //Finds the best move for a given position (not useful yet)
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

        void start() {
            if (playerCount == 1) {
                //Lets the user play against the bot.
                std::cout << "Starting a game against the bot." << std::endl;
            }
            else if (playerCount == 2) {
                //Lets the user play against someone else via command-line.
                std::cout << "Starting a game against another player." << std::endl;
                for (int i = 0; i < 9; i++) {
                    requestCoordinate();
                    if (board.checkForWin(board.getPlayer1Marker())) {
                        std::cout << "Player 1 Wins! (" << board.getPlayer1Marker() << ")\n";
                        break;
                    }
                    else if (board.checkForWin(board.getPlayer2Marker())) {
                        std::cout << "Player 2 Wins! (" << board.getPlayer2Marker() << ")\n";
                        break;
                    }
                    else if (board.checkForTie()) {
                        std::cout << "Tie game! Nobody wins :(\n";
                        break;
                    }
                }
            }
        }
};