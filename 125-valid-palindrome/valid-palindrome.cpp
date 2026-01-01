class Solution {
public:
    bool isPalindrome(string s) {
        string ans;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                ans.push_back(s[i] + 32);
            } else if ((s[i] >= 'a' && s[i] <= 'z') ||
                       (s[i] >= '0' && s[i] <= '9')) {
                ans.push_back(s[i]);
            }
        }

        int m = ans.length();
        for (int i = 0; i < m / 2; i++) {
            if (ans[i] != ans[m - 1 - i])
                return false;
        }
        return true;
    }
};
