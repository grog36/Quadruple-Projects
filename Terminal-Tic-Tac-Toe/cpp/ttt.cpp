#include <iostream>
#include <string>

class Coordinate {
    private:
        int columnIndex;
        int rowIndex;
    
    public:
        Coordinate(int colIn, int rowIn) {
            columnIndex = colIn;
            rowIndex = rowIn;
        }
        int getColumnIndex() {
            return columnIndex;
        }
        int getRowIndex() {
            return rowIndex;
        }
        std::string toString() {
            std::string output = "Col: ";
            output += std::to_string(columnIndex);
            output += "\tRow: ";
            output += std::to_string(rowIndex);
            return output;
        }
};

class Grid {
    public:
        char topLeft;
        char topMiddle;
        char topRight;
        char middleLeft;
        char center;
        char middleRight;
        char bottomLeft;
        char bottomMiddle;
        char bottomRight;

        Grid() {
            topLeft = ' ';
            topMiddle = ' ';
            topRight = ' ';
            middleLeft = ' ';
            center = ' ';
            middleRight = ' ';
            bottomLeft = ' ';
            bottomMiddle = ' ';
            bottomRight = ' ';
        }
        Grid(Grid& otherGrid) {
            topLeft = otherGrid.topLeft;
            topMiddle = otherGrid.topMiddle;
            topRight = otherGrid.topRight;
            middleLeft = otherGrid.middleLeft;
            center = otherGrid.center;
            middleRight = otherGrid.middleRight;
            bottomLeft = otherGrid.bottomLeft;
            bottomMiddle = otherGrid.bottomMiddle;
            bottomRight = otherGrid.bottomRight;
        }
};

class Board {
    private:
        Grid grid;
        Coordinate emptySpaces[9] = {Coordinate(0, 0), Coordinate(1, 0), Coordinate(2, 0),
            Coordinate(0, 1), Coordinate(1, 1), Coordinate(2, 1),
            Coordinate(0, 2), Coordinate(1, 2), Coordinate(2, 2)};
        char player1Marker = 'X';
        char player2Marker = 'O';
        char whoseTurn = 'X';

    public:
        Board() {
            grid = Grid();
        }

        Board(Board& otherBoard) {
            grid = Grid(otherBoard.getGrid());
            emptySpaces = otherBoard.getEmptySpaces();
        }
        
        Coordinate* getEmptySpaces() {
            return emptySpaces;
        }

        Grid getGrid() {
            return grid;
        }


        std::string toString() {
            std::string output = "";
            return output;
        }
};

int main() {
    Coordinate test = Coordinate(1, 2);
    std::cout << test.toString() << std::endl;
    Grid vim = Grid();
    vim.topMiddle = 'Z';
    std::cout << vim.topMiddle << std::endl;
    return 0;
}