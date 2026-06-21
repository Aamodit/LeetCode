class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int MAX_COST = 100000;
        vector<int> count(MAX_COST + 1, 0);
        
        for (int cost : costs) {
            count[cost]++;
        }
        
        int bars = 0;
        
        for (int cost = 1; cost <= MAX_COST && coins > 0; cost++) {
            if (count[cost] == 0) continue;
            
            int canBuy = min(coins / cost, count[cost]);
            
            bars += canBuy;
            coins -= cost * canBuy;
        }
        
        return bars;
    }
};