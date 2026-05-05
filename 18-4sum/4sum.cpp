class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == tar) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do {
                            l++;
                        } while (l < r && nums[l] == nums[l - 1]);
                        do {
                            r--;
                        } while (l < r && nums[r] == nums[r + 1]);
                    } else if (sum > tar) {
                        do {
                            r--;
                        } while (l < r && nums[r] == nums[r + 1]);
                    } else {
                        do {
                            l++;
                        } while (l < r && nums[l] == nums[l - 1]);
                    }
                }
            }
        }
        return ans;
    }
};