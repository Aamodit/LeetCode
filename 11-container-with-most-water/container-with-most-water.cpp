class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int n = height.size();
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         int w = j - i;
        //         int h = min(height[i], height[j]);
        //         int currA = w * h;
        //         maxA = max(maxA, currA);
        //     }
        // }
        int l = 0, r = n - 1;
        while (l < r) {
            int w = r - l;
            int h = min(height[l], height[r]);
            int currA = w * h;
            height[l] > height[r] ? r-- : l++;
            maxA = max(maxA, currA);
        }
        return maxA;
    }
};