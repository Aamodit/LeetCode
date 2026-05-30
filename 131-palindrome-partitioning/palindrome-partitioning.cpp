class Solution {
public:
    vector<vector<string>> ans;

    vector<string> path;

    bool isPalindrome(string& s, int l, int r) {

        while (l < r) {

            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void solve(int start, string& s) {

        // entire string partitioned
        if (start == s.size()) {

            ans.push_back(path);

            return;
        }

        // generate all substrings
        // starting from 'start'
        for (int end = start; end < s.size(); end++) {

            // palindrome substring
            if (isPalindrome(s, start, end)) {

                string sub = s.substr(start, end - start + 1);

                path.push_back(sub);

                // recurse for remaining string
                solve(end + 1, s);

                // backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        solve(0, s);

        return ans;
    }
};