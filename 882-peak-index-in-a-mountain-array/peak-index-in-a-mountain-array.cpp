class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (arr[mid] >= arr[mid - 1]) {
                if (arr[mid] >= arr[mid + 1]) {
                    return mid;
                } else {
                    l = mid + 1;
                }
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};