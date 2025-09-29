class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // gap means the distance between i and j
        for (int gap = 2; gap < n; gap++) {  // need at least 3 vertices to form a triangle
            for (int i = 0; i + gap < n; i++) {
                int j = i + gap;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n-1];
    }
};
