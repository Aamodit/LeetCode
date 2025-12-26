class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int f = 0;
        int curr = arr[0];
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (f == 0) {
                curr = arr[i];
            }
            if (curr == arr[i]) {
                f++;
            } else {
                f--;
            }
        }
        return curr;
    }
};