class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        ans.reserve(nums.size());
        
        int mod = 0;
        for (int b : nums) {
            mod = (mod * 2 + b) % 5;
            ans.push_back(mod == 0);
        }
        
        return ans;
    }
};
