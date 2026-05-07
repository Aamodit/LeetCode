class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cs = 0, count = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            cs += nums[i];
            count += m[cs - k];
            m[cs]++;
        }
        return count;
    }
};