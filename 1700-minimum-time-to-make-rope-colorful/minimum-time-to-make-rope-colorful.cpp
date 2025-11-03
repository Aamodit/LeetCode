class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int n = colors.size();
        
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                // Remove the balloon with smaller time
                totalTime += min(neededTime[i], neededTime[i - 1]);
                
                // Keep the balloon with larger time (so future comparisons use it)
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        
        return totalTime;
    }
};
