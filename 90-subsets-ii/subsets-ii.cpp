class Solution {
public:
    vector<vector<int>> res;

    void ps(vector<int>& nums, vector<int>& ans, int i) {
        if (i == nums.size()) {
            res.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        ps(nums, ans, i + 1);
        ans.pop_back();

        // exclude + skip duplicates
        int idx = i;
        while (idx < nums.size() && nums[idx] == nums[i]) {
            idx++;
        }

        ps(nums, ans, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        ps(nums, ans, 0);
        return res;
    }
};