class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int trans[7][7];
        memset(trans, 0, sizeof(trans));
        
        for (const string& p : allowed) {
            int l = p[0] - 'A', r = p[1] - 'A', t = p[2] - 'A';
            trans[l][r] |= (1 << t);
        }
        
        return dfs(bottom, "", trans);
    }
    
private:
    unordered_map<string, bool> memo;
    
    bool dfs(const string& curr, string next, const int trans[7][7]) {
        if (curr.size() == 1) return true;
        
        if (next.size() == curr.size() - 1) {
            return dfs(next, "", trans);
        }
        
        string key = curr + "#" + next;
        if (memo.count(key)) return memo[key];
        
        int pos = next.size();
        int l = curr[pos] - 'A', r = curr[pos + 1] - 'A';
        int possibilities = trans[l][r];
        
        for (int t = 0; t < 6; t++) {
            if (possibilities & (1 << t)) {
                if (dfs(curr, next + char('A' + t), trans)) {
                    return memo[key] = true;
                }
            }
        }
        
        return memo[key] = false;
    }
};
