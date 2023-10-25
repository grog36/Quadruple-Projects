public class Coordinate {
    private int columnIndex;
    private int rowIndex;

    Coordinate(int rowIn, int colIn) {
        if (rowIn >= 0 && rowIn < 3 && colIn >= 0 && colIn < 3) {
            columnIndex = colIn;
            rowIndex = rowIn;
        }
    }
    public int getColumnIndex() {
        return columnIndex;
    }
    public int getRowIndex() {
        return rowIndex;
    }
    
    public String toString() {
        String output = "{Row: " + String.valueOf(rowIndex);
        output += ",Col: " + String.valueOf(columnIndex) + "}";
        return output;
    }
}