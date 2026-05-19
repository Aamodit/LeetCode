class Solution {
public:
    vector<vector<int>> res;

    void ps(vector<int>& nums, vector<int>& ans, int i) {
        if (i == nums.size()) {
            res.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        ps(nums, ans, i + 1);
        ans.pop_back();
        ps(nums, ans, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        ps(nums, ans, i);
        return res;
    }
};