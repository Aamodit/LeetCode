#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid;
    int rows;

    // Helper: parse "A1" into (row, col)
    pair<int, int> parseCell(const string &cell) {
        char colChar = cell[0];
        int col = colChar - 'A'; 
        int row = stoi(cell.substr(1)) - 1; 
        return {row, col};
    }

    // Helper: get value from cell or integer string
    int getCellOrNumber(const string &token) {
        if (isalpha(token[0])) {
            auto [row, col] = parseCell(token);
            return grid[row][col];
        } else {
            return stoi(token);
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        // formula like "=A1+5"
        formula = formula.substr(1); // remove '='
        size_t plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        int val1 = getCellOrNumber(left);
        int val2 = getCellOrNumber(right);

        return val1 + val2;
    }
};