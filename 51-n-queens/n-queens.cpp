class Solution {
public:
    vector<vector<string>> ans;

    vector<string> board;

    vector<bool> col;
    vector<bool> urd; // r+c
    vector<bool> uld; // r-c+n-1

    void solve(int r, int n) {

        // all queens placed
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            // unsafe position
            if (col[c] || urd[r + c] || uld[r - c + n - 1]) {
                continue;
            }

            // place queen
            board[r][c] = 'Q';

            // mark attacks
            col[c] = true;
            urd[r + c] = true;
            uld[r - c + n - 1] = true;

            // next row
            solve(r + 1, n);

            // backtrack
            board[r][c] = '.';

            // unmark attacks
            col[c] = false;
            urd[r + c] = false;
            uld[r - c + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        // initialize empty board
        board = vector<string>(n, string(n, '.'));

        // initialize attack trackers
        col = vector<bool>(n, false);

        urd = vector<bool>(2 * n - 1, false);

        uld = vector<bool>(2 * n - 1, false);

        solve(0, n);

        return ans;
    }
};