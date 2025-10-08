class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;
        
        for (int spell : spells) {
            long long required = (success + spell - 1) / spell; // ceiling division
            auto it = lower_bound(potions.begin(), potions.end(), required);
            int count = potions.end() - it;
            result.push_back(count);
        }
        
        return result;
    }
};