class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1, 0);
        for (auto val : nums) {
            f[val]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (f[i] > 1) {
                return i;
            }
        }
        return -1;
    }
};