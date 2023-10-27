#include <iostream>
#include <string>

class Coordinate {
    private:
        int columnIndex;
        int rowIndex;
    
    public:
        Coordinate(int rowIn, int colIn) {
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
            std::string output = "{Row: ";
            output += std::to_string(rowIndex);
            output += ",Col: ";
            output += std::to_string(columnIndex);
            output += "}";
            return output;
        }
};