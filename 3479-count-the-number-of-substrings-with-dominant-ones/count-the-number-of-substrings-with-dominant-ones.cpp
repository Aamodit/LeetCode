class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zeros;
        zeros.reserve(n);
        for (int i = 0; i < n; ++i) if (s[i] == '0') zeros.push_back(i);

        // nextZeroIdx[i] = index in zeros[] of first zero >= i
        vector<int> nextZeroIdx(n);
        int zi = 0;
        for (int i = 0; i < n; ++i) {
            while (zi < (int)zeros.size() && zeros[zi] < i) ++zi;
            nextZeroIdx[i] = zi;
        }

        long long res = 0;
        int totalZeros = zeros.size();

        for (int l = 0; l < n; ++l) {
            int startZ = nextZeroIdx[l];   // index in zeros[] of first zero >= l
            // maximum zeros we can consider starting at l (cap at 200 for speed)
            int maxZ = min(200, totalZeros - startZ);
            // also include z = 0 case
            for (int z = 0; z <= maxZ; ++z) {
                int idx = startZ + z; // index of (z+1)-th zero >= l
                // posZ = position of the last zero included in substring (for z>0)
                long long posZ = (z == 0 ? l : zeros[idx - 1]);

                // minimal r from ones constraint: r >= l + z^2 + z - 1
                long long minR = (long long)l + 1LL * z * z + z - 1;
                long long left = max(posZ, minR);
                if (left >= n) continue;

                // upper bound: r must be before the next zero (so it includes exactly z zeros)
                long long upper = (idx < totalZeros ? (long long)zeros[idx] - 1 : (long long)n - 1);
                if (left > upper) continue;

                res += (upper - left + 1);
            }
        }

        return (int)res;
    }
};
