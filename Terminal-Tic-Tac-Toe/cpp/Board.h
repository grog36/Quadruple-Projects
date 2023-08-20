#include <vector>
#include "Coordinate.h"

class Board {
    private:
        std::vector<Coordinate> emptySpaces = {Coordinate(0, 0), Coordinate(1, 0), Coordinate(2, 0),
            Coordinate(0, 1), Coordinate(1, 1), Coordinate(2, 1),
            Coordinate(0, 2), Coordinate(1, 2), Coordinate(2, 2)};
        std::vector<std::vector<char>> grid;
        char player1Marker = 'X';
        char player2Marker = 'O';
        char whoseTurn = 'X';

        std::string boolToString(bool b) {
            return ((b == true) ? "true" : "false");
        }

    public:
        Board(int whoGoesFirst) {
            for (int i = 0; i < 3; i++) {
                std::vector<char> row;
                for (int j = 0; j < 3; j++) {
                    row.push_back(' ');
                }
                grid.push_back(row);
            }
            if (whoGoesFirst == 1) {
                whoseTurn = 'X';
            }
            else if (whoGoesFirst == 2) {
                whoseTurn = 'O';
            }
            else {
                throw std::invalid_argument("whoGoesFirst argument must be 1 or 2");
            }
        }

        Board(Board* oldBoard) {
            emptySpaces = {};
            for (int i = 0; i < 3; i++) {
                std::vector<char> row;
                for (int j = 0; j < 3; j++) {
                    char playerMarker = oldBoard->getGrid()[i][j];
                    if (playerMarker == ' ') {
                        emptySpaces.push_back(Coordinate(i, j));
                    }
                    row.push_back(oldBoard->getGrid()[i][j]);
                }
                grid.push_back(row);
            }
        }
        
        std::vector<Coordinate> getEmptySpaces() {
            return emptySpaces;
        }

        std::vector<std::vector<char>> getGrid() {
            return grid;
        }


        std::string toString() {
            std::string output = "";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    output += "[";
                    output += grid[i][j];
                    output += "] ";
                }
                output += "\n";
            }
            return output;
        }

        char getPlayer1Marker() {
            return player1Marker;
        }
        char getPlayer2Marker() {
            return player2Marker;
        }
        char getWhoseTurn() {
            return whoseTurn;
        }

        bool checkForWin(char playerMarker) {
            //Checks rows and columns
            for (int i = 0; i < 3; i++) {
                if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
                    if (grid[i][0] == playerMarker) {
                        return true;
                    }
                }
                else if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
                    if (grid[0][i] == playerMarker) {
                        return true;
                    }
                }
            }
            //Checks diagonals
            if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) ||
                grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
                    if (grid[1][1] == playerMarker) {
                        return true;
                    } 
            }
            //No win
            return false;
        }

        bool checkForTie() {
            if (checkForWin(player1Marker) == false && checkForWin(player2Marker) == false && emptySpaces.size() == 0) {
                return true;
            }
            return false;
        }

        //TODO
        //Fix segmentation fault
        bool playMove(int rowIndex, int colIndex) {
            if (!(checkForWin(player1Marker) || checkForWin(player2Marker) || checkForTie())) {
                for (int i = 0; i < emptySpaces.size(); i++) {
                    Coordinate c = emptySpaces.at(i);
                    if (c.getRowIndex() == rowIndex && c.getColumnIndex() == colIndex) {
                        grid[rowIndex][colIndex] = whoseTurn;
                        whoseTurn = (whoseTurn == 'X') ? 'O' : 'X';
                        emptySpaces.erase(emptySpaces.begin()+i);
                        return true;
                    }
                }
            }
            return false;
        }

        std::string getStatus() {
            std::string output = toString();
            output = output + "Player1Marker: " + player1Marker;
            output = output + "\nPlayer2Marker: " + player2Marker;
            output = output + "\nWhose Turn: " + whoseTurn;
            output = output + "\nPlayer 1 Win: " + boolToString(checkForWin(player1Marker));
            output = output + "\nPlayer 2 Win: " + boolToString(checkForWin(player2Marker));
            output = output + "\nTie: " + boolToString(checkForTie());
            output = output + "\nRemaining Moves: [";
            for (int i = 0; i < emptySpaces.size(); i++) {
                Coordinate e = emptySpaces.at(i);
                output = output + "{Row:" + std::to_string(e.getRowIndex()) + ",Col:";
                output = output + std::to_string(e.getColumnIndex()) + "}";
                if (i != emptySpaces.size() - 1) {
                    output += ", ";
                }
            }
            output = output + "]\n";
            return output;
        }

};