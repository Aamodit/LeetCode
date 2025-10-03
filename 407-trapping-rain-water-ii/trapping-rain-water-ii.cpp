class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > pq;  // min-heap: {height, {x,y}}

        // Push all boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m - 1][j], {m - 1, j}});
            visited[0][j] = visited[m - 1][j] = true;
        }

        int water = 0;
        vector<int> dirX = {1, -1, 0, 0};
        vector<int> dirY = {0, 0, 1, -1};

        // Process heap
        while (!pq.empty()) {
            auto [height, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            for (int d = 0; d < 4; d++) {
                int nx = x + dirX[d], ny = y + dirY[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    int neighborHeight = heightMap[nx][ny];
                    water += max(0, height - neighborHeight);
                    // Update boundary: if neighbor lower, use current height
                    pq.push({max(height, neighborHeight), {nx, ny}});
                }
            }
        }

        return water;
    }
};
