class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());

        // 1) compute max coverage over all integer points using event sweep
        // intervals: [nums[i]-k, nums[i]+k] (inclusive)
        // we add +1 at start, -1 at end+1
        vector<pair<long long,int>> events;
        events.reserve(n*2);
        for (int x : nums) {
            long long L = (long long)x - k;
            long long R = (long long)x + k;
            events.emplace_back(L, +1);
            events.emplace_back(R + 1, -1);
        }
        sort(events.begin(), events.end());
        int cur = 0;
        int maxCoverage = 0;
        for (auto &e : events) {
            cur += e.second;
            maxCoverage = max(maxCoverage, cur);
        }

        int ans = 1;
        // candidate when choosing a T that isn't necessarily an existing value:
        ans = max(ans, min(maxCoverage, numOperations)); // converting up to numOperations elements

        // 2) For each unique value v, compute coverage_v using binary search,
        //    then achievable = min(coverage_v, freq[v] + numOperations)
        unordered_map<int,int> freq;
        freq.reserve(n*2);
        for (int v : nums) freq[v]++;

        for (auto &p : freq) {
            int v = p.first;
            int fv = p.second;
            long long L = (long long)v - k;
            long long R = (long long)v + k;
            auto itL = lower_bound(nums.begin(), nums.end(), (int)max<long long>(LLONG_MIN, L));
            auto itR = upper_bound(nums.begin(), nums.end(), (int)min<long long>(LLONG_MAX, R));
            int coverage = int(itR - itL);
            int achievable = min(coverage, fv + numOperations);
            ans = max(ans, achievable);
            if (ans == n) return n;
        }

        return ans;
    }
};