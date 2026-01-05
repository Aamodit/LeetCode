class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // increasing slope → peak on right
                l = mid + 1;
            } else {
                // decreasing slope → peak at mid or left
                r = mid;
            }
        }

        return l;  // l == r is guaranteed to be a peak
    }
};
