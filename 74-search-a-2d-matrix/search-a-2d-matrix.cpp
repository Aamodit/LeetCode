class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int tr = m.size();
        int tc = m[0].size();

        int l = 0, r = tc * tr - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cr = mid / tc;
            int cc = mid % tc;
            if (t == m[cr][cc]) {
                return true;
            } else if (t > m[cr][cc]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};