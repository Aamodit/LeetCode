class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int l = 0, r = n - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (m == 0) {
                if (nums[m] != nums[m + 1])
                    return nums[m];
            } else if (m == n - 1) {
                if (nums[m] != nums[m - 1])
                    return nums[m];
            } else if ((nums[m] != nums[m + 1]) && (nums[m] != nums[m - 1])) {
                return nums[m];
            }

            if (m % 2 == 0) // check even
            {
                if (nums[m] == nums[m + 1]) // check right half
                {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (nums[m] != nums[m + 1]) // check right half
                {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};