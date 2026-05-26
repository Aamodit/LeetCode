class Solution {
public:
    vector<vector<char>> b;
    vector<vector<bool>> rb;
    vector<vector<bool>> cb;
    vector<vector<bool>> bb;
    void bt(int r, int c) {
        if (r == 9) {
            return;
        }
        if (c == 9) {
            return bt(r + 1, 0);
        }
        if (b[r][c] == '.') {
            return bt(r, c + 1);
        }
        int d = b[r][c] - '0';
        rb[r][d] = true;
        cb[c][d] = true;
        bb[(r / 3) * 3 + (c / 3)][d] = true;
        return bt(r, c + 1);
    }

    bool ss(int r, int c) {
        if (r == 9) {
            return true;
        }
        if (c == 9) {
            return ss(r + 1, 0);
        }
        if (b[r][c] != '.') {
            return ss(r, c + 1);
        }
        for (char i = '1'; i <= '9'; i++) {
            int d = i - '0';
            if (rb[r][d] || cb[c][d] || bb[(r / 3) * 3 + (c / 3)][d]) {
                continue;
            }
            b[r][c] = i;
            rb[r][d] = true;
            cb[c][d] = true;
            bb[(r / 3) * 3 + (c / 3)][d] = true;
            if (ss(r, c + 1)) {
                return true;
            }
            b[r][c] = '.';
            rb[r][d] = false;
            cb[c][d] = false;
            bb[(r / 3) * 3 + (c / 3)][d] = false;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        b = board;
        rb = vector<vector<bool>>(9, vector<bool>(10, false));
        cb = vector<vector<bool>>(9, vector<bool>(10, false));
        bb = vector<vector<bool>>(9, vector<bool>(10, false));
        bt(0, 0);
        ss(0, 0);
        board = b;
    }
};