class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> sum;
        for (int x : power) sum[x] += x;  // combine duplicate powers
        
        vector<int> vals;
        for (auto &p : sum) vals.push_back(p.first);
        sort(vals.begin(), vals.end());
        
        int n = vals.size();
        vector<long long> dp(n);
        
        dp[0] = sum[vals[0]];
        for (int i = 1; i < n; ++i) {
            // find last index j such that vals[j] <= vals[i] - 3
            int j = upper_bound(vals.begin(), vals.begin() + i, vals[i] - 3) - vals.begin() - 1;
            
            long long take = sum[vals[i]] + (j >= 0 ? dp[j] : 0);
            long long skip = dp[i-1];
            dp[i] = max(skip, take);
        }
        
        return dp.back();
    }
};
