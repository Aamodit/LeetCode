class Solution {
public:
    int bS(vector<int>& N, int t, int l, int r) {
        if (l <= r) {
            int mid = l + (r - l) / 2;
            if (N[mid] == t) {
                return mid;
            } else if (N[mid] > t) {
                return bS(N, t, l, mid - 1);
            } else {
                return bS(N, t, mid + 1, r);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        return bS(nums, target, l, r);
    }
};