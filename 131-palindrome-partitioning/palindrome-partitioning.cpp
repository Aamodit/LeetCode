class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool isP(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    void solve(string s) {
        if (s.size() <= 0) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            string s1 = s.substr(0, i + 1);
            if (isP(s1)) {
                path.push_back(s1);
                solve(s.substr(i + 1));
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        solve(s);
        return ans;
    }
};