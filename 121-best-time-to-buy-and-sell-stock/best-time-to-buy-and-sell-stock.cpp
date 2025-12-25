class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0], mp = 0; // minimum price and maximum profit
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > minP) {
                mp = max(mp, prices[i] - minP);
            }
            minP = min(minP, prices[i]);
        }
        return mp;
    }
};