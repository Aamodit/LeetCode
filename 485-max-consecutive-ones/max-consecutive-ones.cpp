class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0, max_c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                c++;
            }
            if (nums[i] == 0) {
                c = 0;
            }
            max_c = max(c, max_c);
        }
        return max_c;
    }
};