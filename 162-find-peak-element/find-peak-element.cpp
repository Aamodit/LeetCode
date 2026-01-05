class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), m = INT_MIN, l = 0;
        for (int i = 0; i < n; i++) {
            if (m < nums[i]) {
                m = nums[i];
                l = i;
            }
        }
        return l;
    }
};