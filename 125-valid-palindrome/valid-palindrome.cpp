class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        int n = s.length();
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 65 && s[i] <= 90) {
                ans.push_back(s[i] + 32);
                m++;
            }
            if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {

                ans.push_back(s[i]);
                m++;
            }
        }
        for (int i = 0; i < m; i++) {
            cout << ans[i];
        }
        for (int i = 0; i < m / 2; i++) {
            if (ans[i] != ans[m - 1 - i])
                return false;
        }
        return true;
    }
};