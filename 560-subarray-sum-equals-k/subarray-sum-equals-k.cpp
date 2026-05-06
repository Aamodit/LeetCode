class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n);
        p[0] = nums[0];
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] + nums[i];
        }
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                if (j > 0) {
                    if (p[i] - p[j - 1] == k) {
                        count++;
                    }
                } else {
                    if (p[i] == k) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};