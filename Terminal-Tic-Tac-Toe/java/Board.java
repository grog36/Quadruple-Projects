import java.util.ArrayList;

public class Board {
    private ArrayList<Coordinate> emptySpaces = new ArrayList<Coordinate>();
    private char[][] grid = new char[3][3];
    private char player1Marker = 'X';
    private char player2Marker = 'O';
    private char whoseTurn = 'X';

    Board(int whoGoesFirst) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                this.grid[i][j] = ' ';
                this.emptySpaces.add(new Coordinate(i, j));
            }
        }
        if (whoGoesFirst == 1) {
            this.whoseTurn = 'X';
        }
        else if (whoGoesFirst == 2) {
            this.whoseTurn = 'O';
        }
        else {
            throw new IllegalArgumentException();
        }
    }

    Board(Board oldBoard) {
        this.emptySpaces = new ArrayList<Coordinate>();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char playerMarker = oldBoard.getGrid()[i][j];
                this.grid[i][j] = playerMarker;
                if(playerMarker == ' ') {
                    this.emptySpaces.add(new Coordinate(i, j));
                }
            }
        }
    }

    public ArrayList<Coordinate> getEmptySpaces() {
        return this.emptySpaces;
    }
    public char[][] getGrid() {
        return this.grid;
    }

    public String toString() {
        String output = "";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                output += "[" + this.grid[i][j] + "] ";
            }
            output += "\n";
        }
        return output;
    }

    public char getPlayer1Marker() {
        return this.player1Marker;
    }
    public char getPlayer2Marker() {
        return this.player2Marker;
    }
    public char getWhoseTurn() {
        return this.whoseTurn;
    }

    public boolean checkForWin(char playerMarker) {
        //Checks rows and columns
        for (int i = 0; i < 3; i++) {
            if (this.grid[i][0] == this.grid[i][1] && this.grid[i][1] == this.grid[i][2]) {
                if (this.grid[i][0] == playerMarker) {
                    return true;
                }
            }
            else if (this.grid[0][i] == this.grid[1][i] && this.grid[1][i] == this.grid[2][i]) {
                if (this.grid[0][i] == playerMarker) {
                    return true;
                }
            }
        }
        //Checks diagonals
        if ((this.grid[0][0] == this.grid[1][1] && this.grid[1][1] == this.grid[2][2]) ||
            this.grid[0][2] == this.grid[1][1] && this.grid[1][1] == this.grid[2][0]) {
                if (this.grid[1][1] == playerMarker) {
                    return true;
                }
        }
        //No win
        return false;
    }

    public boolean checkForTie() {
        if ((this.checkForWin(this.player1Marker) || this.checkForWin(this.player2Marker)) || this.emptySpaces.size() != 0) {
            return false;
        }
        return true;
    }

    public boolean playMove(int rowIndex, int colIndex) {
        if (!(this.checkForWin(this.player1Marker) || this.checkForWin(this.player2Marker) || this.checkForTie())) {
            for (Coordinate c : this.emptySpaces) {
                if (c.getRowIndex() == rowIndex && c.getColumnIndex() == colIndex) {
                    this.grid[rowIndex][colIndex] = this.whoseTurn;
                    this.whoseTurn = (this.whoseTurn == 'X') ? 'O' : 'X';
                    this.emptySpaces.remove(c);
                    return true;
                }
            }
        }
        return false;
    }

    public String getStatus() {
        String output = this.toString();
        output += "Player1Marker: " + this.player1Marker;
        output += "\nPlayer2Marker: " + this.player2Marker;
        output += "\nWhose Turn: " + this.whoseTurn;
        output += "\nPlayer 1 Win: " + String.valueOf(this.checkForWin(this.player1Marker));
        output += "\nPlayer 2 Win: " + String.valueOf(this.checkForWin(this.player2Marker));
        output += "\nTie: " + String.valueOf(this.checkForTie());
        output += "\nRemaining Moves: [";
        for (int i = 0; i < this.emptySpaces.size(); i++) {
            output += this.emptySpaces.get(i).toString();
            if (i < this.emptySpaces.size() - 1) {
                output += ", ";
            }
        }
        output += "]\n";
        return output;
    }
}