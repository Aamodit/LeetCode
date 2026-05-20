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
        do {
            i++;
        } while (i < nums.size() && nums[i] == nums[i - 1]);
        ps(nums, ans, i);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        ps(nums, ans, 0);
        return res;
    }
};