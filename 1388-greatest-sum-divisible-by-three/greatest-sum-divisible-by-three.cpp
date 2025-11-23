class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0); // dp[r] = maximum sum with remainder r

        for (int x : nums) {
            vector<int> cur(dp); // to avoid overwriting during iteration
            for (int r : {0, 1, 2}) {
                int new_sum = dp[r] + x;
                cur[new_sum % 3] = max(cur[new_sum % 3], new_sum);
            }
            dp = cur;
        }

        return dp[0]; // best sum divisible by 3
    }
};
