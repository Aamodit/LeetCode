class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        unordered_map<int, int> freq;

        // Custom comparator: higher frequency first, then higher value
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        };

        multiset<pair<int, int>, decltype(cmp)> top(cmp), rest(cmp);
        long long sumTop = 0;

        auto add = [&](int val) {
            int oldFreq = freq[val];
            freq[val]++;
            int newFreq = freq[val];

            if (oldFreq > 0) {
                pair<int, int> oldPair = {oldFreq, val};
                if (top.find(oldPair) != top.end()) {
                    sumTop -= 1LL * oldFreq * val;
                    top.erase(top.find(oldPair));
                } else {
                    rest.erase(rest.find(oldPair));
                }
            }
            rest.insert({newFreq, val});
        };

        auto remove = [&](int val) {
            int oldFreq = freq[val];
            freq[val]--;
            int newFreq = freq[val];

            pair<int, int> oldPair = {oldFreq, val};
            if (top.find(oldPair) != top.end()) {
                sumTop -= 1LL * oldFreq * val;
                top.erase(top.find(oldPair));
            } else {
                rest.erase(rest.find(oldPair));
            }
            if (newFreq > 0) rest.insert({newFreq, val});
        };

        auto rebalance = [&]() {
            while ((int)top.size() < x && !rest.empty()) {
                auto it = rest.begin();
                sumTop += 1LL * it->first * it->second;
                top.insert(*it);
                rest.erase(it);
            }
            while ((int)top.size() > x) {
                auto it = prev(top.end());
                sumTop -= 1LL * it->first * it->second;
                rest.insert(*it);
                top.erase(it);
            }

            // Ensure correct ordering between top and rest
            while (!rest.empty() && !top.empty()) {
                auto bestRest = *rest.begin();
                auto worstTop = *prev(top.end());
                if (cmp(bestRest, worstTop)) {
                    sumTop += 1LL * bestRest.first * bestRest.second;
                    sumTop -= 1LL * worstTop.first * worstTop.second;
                    top.erase(prev(top.end()));
                    top.insert(bestRest);
                    rest.erase(rest.begin());
                    rest.insert(worstTop);
                } else break;
            }
        };

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            rebalance();

            if (i >= k) {
                remove(nums[i - k]);
                if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
                rebalance();
            }

            if (i >= k - 1) ans.push_back(sumTop);
        }

        return ans;
    }
};
