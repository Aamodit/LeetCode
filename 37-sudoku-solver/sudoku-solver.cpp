class Solution {
public:
    vector<vector<char>> b;

    bool isSafe(int r, int c, char d) {
        for (int i = 0; i < 9; i++) {
            if (b[r][i] == d || b[i][c] == d) {
                return false;
            }
        }

        int sr = (r / 3) * 3, sc = (c / 3) * 3;
        for (int i = sr; i <= sr + 2; i++) {
            for (int j = sc; j <= sc + 2; j++) {
                if (b[i][j] == d) {
                    return false;
                }
            }
        }
        return true;
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
            if (isSafe(r, c, i)) {
                b[r][c] = i;
                if (ss(r, c + 1)) {
                    return true;
                }
                b[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        b = board;
        ss(0, 0);
        board = b;
    }
};