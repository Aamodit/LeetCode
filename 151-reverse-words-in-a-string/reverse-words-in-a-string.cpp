class Solution {
public:
    string reverseWords(string s) {
        string t;
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        while (i < n) {
            if (s[i] != ' ') {
                t.push_back(s[i]);
            } else {
                t.push_back(' ');
                while (i < n && s[i] == ' ') {
                    i++;
                }
                continue;
            }
            i++;
        }
        
        int m = t.size();
        if(m==0)
        {
            return t;
        }
        if (t[m - 1] == ' ') {
            t.pop_back();
        }
        m = t.size();
        reverse(t.begin(),t.end());
        int st = 0;
        for (int i = 0; i < m; i++) {
            if (t[i] == ' ') {
                reverse(t.begin() + st, t.begin() + i);
                st = i + 1;
            }
        }
        reverse(t.begin()+st,t.end());
        return t;
    }
};