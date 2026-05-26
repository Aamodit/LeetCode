class Solution {
public:

    vector<vector<char>> b;

    // row[r][d]
    // is digit d present in row r?
    vector<vector<bool>> rb;

    // col[c][d]
    // is digit d present in column c?
    vector<vector<bool>> cb;

    // box[b][d]
    // is digit d present in box b?
    vector<vector<bool>> bb;

    // preprocessing
    void preprocess() {

        for(int r = 0; r < 9; r++) {

            for(int c = 0; c < 9; c++) {

                if(b[r][c] == '.')
                    continue;

                int d = b[r][c] - '0';

                int box = (r/3)*3 + (c/3);

                rb[r][d] = true;
                cb[c][d] = true;
                bb[box][d] = true;
            }
        }
    }

    bool solve(int r, int c) {

        // board solved
        if(r == 9)
            return true;

        // move to next row
        if(c == 9)
            return solve(r + 1, 0);

        // already filled cell
        if(b[r][c] != '.')
            return solve(r, c + 1);

        int box = (r/3)*3 + (c/3);

        // try digits 1-9
        for(char ch = '1'; ch <= '9'; ch++) {

            int d = ch - '0';

            // unsafe
            if(rb[r][d] || cb[c][d] || bb[box][d])
                continue;

            // place digit
            b[r][c] = ch;

            rb[r][d] = true;
            cb[c][d] = true;
            bb[box][d] = true;

            // recurse
            if(solve(r, c + 1))
                return true;

            // backtrack
            b[r][c] = '.';

            rb[r][d] = false;
            cb[c][d] = false;
            bb[box][d] = false;
        }

        // no digit works
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        b = board;

        rb = vector<vector<bool>>(9, vector<bool>(10, false));

        cb = vector<vector<bool>>(9, vector<bool>(10, false));

        bb = vector<vector<bool>>(9, vector<bool>(10, false));

        preprocess();

        solve(0, 0);

        board = b;
    }
};