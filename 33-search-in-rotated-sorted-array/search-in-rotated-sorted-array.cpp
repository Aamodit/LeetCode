class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == tar)
                return mid;

            // left half sorted
            if (nums[l] <= nums[mid]) {
                if (tar >= nums[l] && tar < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // right half sorted
            else {
                if (tar > nums[mid] && tar <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};
