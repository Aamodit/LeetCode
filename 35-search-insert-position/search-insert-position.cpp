class Solution {
public:
    int searchInsert(vector<int>& nums, int tar) {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] == tar) {
                return m;
            } else if (nums[m] < tar) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};