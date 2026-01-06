class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool st = false;
        int s;
        int n = nums.size();
        int count = 0;
        vector<int> ans(2, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (!st) {
                    st = true;
                    s = i;
                }
                count++;
            }
        }
        if (st) {
            ans[0] = s;
            ans[1] = s + count - 1;
        }
        return ans;
    }
};