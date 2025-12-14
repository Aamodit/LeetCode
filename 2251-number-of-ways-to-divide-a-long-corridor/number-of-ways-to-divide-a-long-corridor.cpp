class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        long long ans = 1;
        int seats = 0;
        int plantsBetween = 0;

        for (char c : corridor) {
            if (c == 'S') {
                seats++;
                // When we finish a pair (2nd, 4th, ...)
                if (seats > 2 && seats % 2 == 1) {
                    ans = (ans * (plantsBetween + 1)) % MOD;
                    plantsBetween = 0;
                }
            } else { // 'P'
                if (seats >= 2 && seats % 2 == 0) {
                    plantsBetween++;
                }
            }
        }

        // Total seats must be even and at least 2
        if (seats < 2 || seats % 2 != 0) return 0;

        return ans;
    }
};
