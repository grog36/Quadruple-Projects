#include "Board.h"

class Game {
    private:
        Board board = Board(1);
        int playerCount;

        //Asks for user input to play a move
        void requestCoordinate() {
            std::cout << board.toString() << "\n";
            std::cout << "Player - '" << board.getWhoseTurn() << "'s turn.\n";
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
        Coordinate findBestMove(Board boardToCheck) {
            std::vector<Coordinate> preventsLosses;
            //If the game is not already over
            if (!(boardToCheck.checkForWin(boardToCheck.getPlayer1Marker()) || boardToCheck.checkForWin(boardToCheck.getPlayer2Marker()) || boardToCheck.checkForTie())) {
                //Iterates through the list of possible moves
                for (int i = 0; i < boardToCheck.getEmptySpaces().size(); i++) {
                    //Checks to see if it can cause a win
                    Board tempBoard = Board(boardToCheck);
                    Coordinate c = boardToCheck.getEmptySpaces().at(i);
                    tempBoard.playMove(c.getRowIndex(), c.getColumnIndex());
                    if (tempBoard.checkForWin(boardToCheck.getWhoseTurn())) {
                        return Coordinate(c.getRowIndex(), c.getColumnIndex());
                    }
                    //Checks to see if it prevents a loss
                    for (int j = 0; j < tempBoard.getEmptySpaces().size(); j++) {
                        Board tempTempBoard = Board(tempBoard);
                        Coordinate d = tempBoard.getEmptySpaces().at(j);
                        tempTempBoard.playMove(d.getRowIndex(), d.getColumnIndex());
                        if (tempTempBoard.checkForWin(tempBoard.getWhoseTurn())) {
                            preventsLosses.push_back(d);
                        }
                    }
                }
                //Checks the loss prevention list and displays the first solution if applicable
                if (preventsLosses.size() > 0) {
                    return preventsLosses.at(0);
                }
            }
            //If all else fails, there is no best move
            return Coordinate(100, 100);
        }

        void start() {
            if (playerCount == 1) {
                //Lets the user play against the bot.
                std::cout << "Starting a game against the bot.\n";
                for (int i = 0; i < 9; i++) {
                    if (board.getWhoseTurn() == 'X') {
                        requestCoordinate();
                    }
                    else if (board.getWhoseTurn() == 'O') {
                        Coordinate bestPossibleMove = findBestMove(board);
                        if (bestPossibleMove.getColumnIndex() == 100 && bestPossibleMove.getRowIndex() == 100) {
                            Coordinate moveToPlay = board.getEmptySpaces().at(0);
                            board.playMove(moveToPlay.getRowIndex(), moveToPlay.getColumnIndex());
                        }
                        else {
                            board.playMove(bestPossibleMove.getRowIndex(), bestPossibleMove.getColumnIndex());
                        }
                    }

                    //Check for end of game
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
            else if (playerCount == 2) {
                //Lets the user play against someone else via command-line.
                std::cout << "Starting a game against another player.\n";
                for (int i = 0; i < 9; i++) {

                    //Prints the best move
                    std::cout << findBestMove(board).toString() + "\n";

                    //Actually does the requesting
                    requestCoordinate();

                    //Check for end of game
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