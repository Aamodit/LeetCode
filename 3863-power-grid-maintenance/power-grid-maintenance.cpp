class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // 1️⃣ Build DSU from connections
        for (auto &edge : connections)
            dsu.unite(edge[0], edge[1]);

        // 2️⃣ Map each DSU root to its set of online nodes
        unordered_map<int, set<int>> compOnline;
        vector<bool> online(c + 1, true);

        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            compOnline[root].insert(i);
        }

        // 3️⃣ Process queries
        vector<int> ans;
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);

            if (type == 1) {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    auto &st = compOnline[root];
                    if (st.empty())
                        ans.push_back(-1);
                    else
                        ans.push_back(*st.begin());
                }
            } else if (type == 2) {
                if (online[x]) {
                    compOnline[root].erase(x);
                    online[x] = false;
                }
            }
        }

        return ans;
    }
};