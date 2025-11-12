class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Compute overall gcd
        int overall_gcd = nums[0];
        for (int x : nums)
            overall_gcd = gcd(overall_gcd, x);
        if (overall_gcd > 1)
            return -1;

        // Step 2: Count existing ones
        int count_ones = count(nums.begin(), nums.end(), 1);
        if (count_ones > 0)
            return n - count_ones;

        // Step 3: Find shortest subarray with gcd == 1
        int min_len = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break; // no need to continue further
                }
            }
        }

        // If we found a subarray with gcd 1
        return (min_len == INT_MAX) ? -1 : (n + min_len - 2);
    }
};