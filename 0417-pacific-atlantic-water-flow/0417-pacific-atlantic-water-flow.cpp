class Solution {
private:
    vector<vector<bool>> pac;
    vector<vector<bool>> ata;

    void dfs(int i, int j, int prevHeight, vector<vector<int>>& heights, bool isPacific) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Out of bounds OR water cannot flow uphill/stay level from ocean's perspective
        if (i < 0 || i >= m || j < 0 || j >= n || heights[i][j] < prevHeight) return;
        
        // Skip if already visited
        if (isPacific && pac[i][j]) return;
        if (!isPacific && ata[i][j]) return;

        // Mark as reachable
        if (isPacific) pac[i][j] = true;
        else ata[i][j] = true;

        // Explore 4-directional neighbors
        dfs(i + 1, j, heights[i][j], heights, isPacific);
        dfs(i - 1, j, heights[i][j], heights, isPacific);
        dfs(i, j + 1, heights[i][j], heights, isPacific);
        dfs(i, j - 1, heights[i][j], heights, isPacific);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // Fix 1: Properly initialize boolean matrices
        pac.assign(m, vector<bool>(n, false));
        ata.assign(m, vector<bool>(n, false));

        // Fix 2: Launch DFS from Pacific (top/left) and Atlantic (bottom/right) borders
        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights[i][0], heights, true);       // Pacific Left Border
            dfs(i, n - 1, heights[i][n - 1], heights, false); // Atlantic Right Border
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, heights[0][j], heights, true);       // Pacific Top Border
            dfs(m - 1, j, heights[m - 1][j], heights, false); // Atlantic Bottom Border
        }

        // Collect all coordinates that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && ata[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};