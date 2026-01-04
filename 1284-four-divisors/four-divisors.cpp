class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int count = 0, sum = 0, ts = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 2; j < nums[i]; j++) {
                if (nums[i] % j == 0) {
                    count++;
                    sum = sum + j;
                }
                if (count > 2 || nums[i] / j < 2) {
                    break;
                }
            }
            if (count == 2) {
                ts += sum + 1 + nums[i];
            }
            count = 0;
            sum = 0;
        }
        return ts;
    }
};