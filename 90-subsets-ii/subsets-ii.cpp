class Solution {
public:
    set<vector<int>> s;

    void ps(vector<int>& nums, vector<int>& ans, int i) {
        if (i == nums.size()) {
            s.insert(ans);
            return;
        }
        ans.push_back(nums[i]);
        ps(nums, ans, i + 1);
        ans.pop_back();
        ps(nums, ans, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;

        sort(nums.begin(),nums.end());

        ps(nums, ans, 0);
        for (auto val : s) {
            res.push_back(val);
        }
        return res;
    }
};