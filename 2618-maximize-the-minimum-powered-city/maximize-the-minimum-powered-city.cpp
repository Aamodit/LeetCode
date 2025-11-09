class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> power(n, 0);

        // Step 1: Compute initial power using sliding window
        long long window = 0;
        for (int i = 0; i < n; i++) {
            window += stations[i];
            if (i - r - 1 >= 0) window -= stations[i - r - 1];
            if (i + r < n) power[i + r] += window;
        }

        // Convert prefix sum-like cumulative adjustments
        vector<long long> prefix(n, 0);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += stations[i];
            prefix[i] = sum;
        }

        auto getRangeSum = [&](int l, int r) -> long long {
            if (l < 0) l = 0;
            if (r >= n) r = n - 1;
            return prefix[r] - (l > 0 ? prefix[l - 1] : 0);
        };

        for (int i = 0; i < n; i++) {
            power[i] = getRangeSum(i - r, i + r);
        }

        // Step 2: Binary search
        long long low = 0, high = 1e18, ans = 0;

        auto can = [&](long long target) {
            long long used = 0;
            vector<long long> diff(n, 0);
            long long add = 0;

            for (int i = 0; i < n; i++) {
                add += diff[i];
                long long curr = power[i] + add;
                if (curr < target) {
                    long long need = target - curr;
                    used += need;
                    if (used > k) return false;

                    add += need;
                    if (i + 2 * r + 1 < n)
                        diff[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};