class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int opr = 0;
        for (int i = 0; i < n; i++) {
            float diff = nums[i] % 3;
            cout<<diff<<endl;
            if (diff) {
                nums[i] += diff;
                opr++;
            }
        }
        return opr;
    }
};