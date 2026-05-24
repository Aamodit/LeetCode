class Solution {
public:
    vector<vector<string>> ans;
    vector<string> b;

    bool isSafe(int r, int c, int n) {
        // check vertical & horizontal
        for (int i = 0; i < n; i++) {
            if (b[r][i] == 'Q' || b[i][c] == 'Q') {
                return false;
            }
            if (r - i >= 0 && c - i >= 0) {
                if (b[r - i][c - i] == 'Q') {
                    return false;
                }
            }
            if (r + i < n && c + i < n) {
                if (b[r + i][c + i] == 'Q') {
                    return false;
                }
            }
            if (r - i >= 0 && c + i < n) {
                if (b[r - i][c + i] == 'Q') {
                    return false;
                }
            }
            if (r + i < n && c - i >= 0) {
                if (b[r + i][c - i] == 'Q') {
                    return false;
                }
            }
        }
        return true;
    }

    void sQ(int r, int n) {
        if (r == n) {
            ans.push_back(b);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (isSafe(r, c, n)) {
                b[r][c] = 'Q';
                sQ(r + 1, n);
                b[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // initialize board with .
        b = vector<string>(n, string(n, '.'));
        sQ(0, n);
        return ans;
    }
};