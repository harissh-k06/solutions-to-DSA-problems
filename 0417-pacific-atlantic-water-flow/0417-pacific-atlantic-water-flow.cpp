class Solution {
private:
    vector<vector<bool>> pac;
    vector<vector<bool>> ata;

    void dfs(int i, int j, int prevHeight, vector<vector<int>>& heights, bool isPacific) {
        int m = heights.size();
        int n = heights[0].size();
        
  
        if (i < 0 || i >= m || j < 0 || j >= n || heights[i][j] < prevHeight) return;
        
    
        if (isPacific && pac[i][j]) return;
        if (!isPacific && ata[i][j]) return;

      
        if (isPacific) pac[i][j] = true;
        else ata[i][j] = true;

        dfs(i + 1, j, heights[i][j], heights, isPacific);
        dfs(i - 1, j, heights[i][j], heights, isPacific);
        dfs(i, j + 1, heights[i][j], heights, isPacific);
        dfs(i, j - 1, heights[i][j], heights, isPacific);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        pac.assign(m, vector<bool>(n, false));
        ata.assign(m, vector<bool>(n, false));

        
        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights[i][0], heights, true);      
            dfs(i, n - 1, heights[i][n - 1], heights, false); 
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, heights[0][j], heights, true);     
            dfs(m - 1, j, heights[m - 1][j], heights, false); 
        }


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