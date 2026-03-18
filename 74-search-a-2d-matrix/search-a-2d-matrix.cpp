class Solution {
public:
    int findR(vector<vector<int>>& m, int t) {
        int l = 0, r = m.size() - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (t >= m[mid][0] && t <= m[mid][m[mid].size() - 1]) {
                return mid;
            } else if (t < m[mid][m[mid].size() - 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& m, int t) {

        int row = findR(m, t);

        if (row == -1) {
            return false;
        }
        int l = 0, r = m[row].size() - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (m[row][mid] == t) {
                return true;
            } else if (m[row][mid] > t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};