class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (!binary_search(ans.begin(), ans.end(), nums[i])) {
                ans.push_back(nums[i]);
                k++;
            }
        }

        for (int i = 0; i < k; i++) {
            nums[i] = ans[i];
        }
        return k;
    }
};