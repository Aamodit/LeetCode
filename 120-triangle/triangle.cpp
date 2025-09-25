class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Start from the second last row and move upwards
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                // Update current element with min path sum from below
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        // The top element now contains the minimum path sum
        return triangle[0][0];
    }
};
