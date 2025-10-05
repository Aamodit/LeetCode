#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // Directions (up, down, left, right)
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        // Lambda DFS function
        function<void(int, int, vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& visited) {
            visited[r][c] = true;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i], nc = c + dirs[i+1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue;  // reverse flow condition
                dfs(nr, nc, visited);
            }
        };
        
        // Start DFS from Pacific and Atlantic edges
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, pacific);       // Left edge (Pacific)
            dfs(i, n-1, atlantic);    // Right edge (Atlantic)
        }
        for (int j = 0; j < n; ++j) {
            dfs(0, j, pacific);       // Top edge (Pacific)
            dfs(m-1, j, atlantic);    // Bottom edge (Atlantic)
        }
        
        // Collect result
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};
