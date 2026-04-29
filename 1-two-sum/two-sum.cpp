class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < n.size(); i++) {
            int f = n[i];
            int s = t - f;
            if (m.find(s) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[s]);
                return ans;
            } else {
                m[f] = i;
            }
        }
        return ans;
    }
};