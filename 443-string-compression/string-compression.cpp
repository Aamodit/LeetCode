class Solution {
public:
    int compress(vector<char>& c) {
        int n = c.size();
        string s;
        s.push_back(c[0]);
        for (int i = 1; i < n; i++) {
            if (c[i] == c[i - 1]) {
                int count = 1;
                while (i < n && c[i] == c[i - 1]) {
                    count++;
                    i++;
                }
                string t = to_string(count);
                for (char u : t) {
                    s.push_back(u);
                }
                if (i >= n) {
                    break;
                }
                s.push_back(c[i]);
                continue;
            } else {
                s.push_back(c[i]);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            c[i] = s[i];
        }
        return s.length();
    }
};