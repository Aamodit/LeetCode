class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int c = 1, n = arr.size();
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                c++;
            } else {
                c = 1;
            }
            if (c > (n / 4)) {
                return arr[i];
            }
        }
        return ans;
    }
};