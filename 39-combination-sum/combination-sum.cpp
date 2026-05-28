class Solution {
public:
    vector<vector<int>> ans;

    vector<int> path;

    void solve(int i, vector<int>& nums, int target) {

        // target achieved
        if (target == 0) {

            ans.push_back(path);

            return;
        }

        // out of bounds
        if (i >= nums.size())
            return;

        // pruning
        if (nums[i] > target)
            return;

        // take current element
        path.push_back(nums[i]);

        solve(i, nums, target - nums[i]);

        path.pop_back();

        // skip current element
        solve(i + 1, nums, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        solve(0, nums, target);

        return ans;
    }
};