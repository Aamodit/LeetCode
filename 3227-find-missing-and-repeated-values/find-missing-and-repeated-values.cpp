class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;
        long long eSum = 1LL * (N * (N + 1) / 2);
        long long eSqSum = 1LL * ((N*(N + 1)*(2 * N + 1)) / 6);
        long long aSum = 0, aSqSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                aSum += 1LL * grid[i][j];
                aSqSum += (1LL * grid[i][j] * grid[i][j]);
            }
        }
        long long diff = aSum - eSum;
        long long sqDiff = aSqSum - eSqSum;

        int repeated = 1LL * (((sqDiff / diff) + diff) / 2);
        int missing = 1LL * (((sqDiff / diff) - diff) / 2);

        return {repeated, missing};
    }
};