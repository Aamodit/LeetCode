class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (s.length() == 0) {
            return true;
        }
        int i = 0, j = 0;
        for (i = 0; i < m; i++) {
            if (s[j] == t[i]) {
                j++;
            }
            if (j == n) {
                return true;
            }
        }
        // cout << "n : " << n << endl;
        // cout << "j : " << j << endl;
        return false;
    }
};