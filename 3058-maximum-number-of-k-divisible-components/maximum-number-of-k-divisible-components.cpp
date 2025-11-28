class Solution {
public:
    vector<vector<int>> g;
    int k;
    int components;

    long long dfs(int u, int parent, vector<int>& values) {
        long long sum = values[u] % k;

        for (int v : g[u]) {
            if (v == parent) continue;
            long long child = dfs(v, u, values);

            // If child subtree is divisible by k, cut it off
            if (child % k == 0) {
                components++;
            } else {
                sum = (sum + child) % k;
            }
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k_) {
        k = k_;
        g.assign(n, {});
        components = 0;

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        long long root = dfs(0, -1, values);

        // root component is also valid because total sum divisible by k
        components++;

        return components;
    }
};
