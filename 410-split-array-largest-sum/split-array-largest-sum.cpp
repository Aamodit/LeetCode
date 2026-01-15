class Solution {
public:
    bool isValid(int mp, vector<int>& nums, int ms) {
        // mp = curr max pages
        // ms = no of students given
        int cst = 1, csm = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((csm + nums[i]) <= mp) {
                csm += nums[i];
            } else {
                cst++;
                csm = nums[i];
            }
        }
        if(cst<=ms)
        {
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int r = 0, l = INT_MIN, m, ans;
        for (int i = 0; i < nums.size(); i++) {
            r += nums[i];
            l = max(l, nums[i]);
        }
        while (l <= r) {
            m = l + (r - l) / 2;
            if (isValid(m, nums, k)) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};