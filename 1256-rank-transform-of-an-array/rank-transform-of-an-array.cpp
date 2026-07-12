class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums;
        unordered_map<int, int> m;
        for (auto val : arr) {
            nums.push_back(val);
        }
        sort(nums.begin(), nums.end());
        int r = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] != nums[i - 1])
                r++;
            m[nums[i]] = r;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = m[arr[i]];
        }

        return arr;
    }
};