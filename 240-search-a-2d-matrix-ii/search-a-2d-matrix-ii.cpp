class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size();
        int n = mat[0].size();
        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (mat[r][c] == t) {
                return true;
            } else if (mat[r][c] > t) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};