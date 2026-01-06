class Solution {
public:
    int findMin(vector<int>& nums) {
        int m = INT_MAX;
        for (auto i : nums) {
            m = min(i, m);
        }
        return m;
    }
};