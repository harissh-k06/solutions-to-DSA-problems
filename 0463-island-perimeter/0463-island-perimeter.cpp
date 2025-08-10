class Solution {

private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& perm, vector<vector<bool>>& visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            //boundary condition
            perm+=1;
            return;
        }
        if (visited[i][j] == true) return;
        visited[i][j] = true;
        dfs(grid , i+1 , j , perm , visited);
        dfs(grid , i-1 , j , perm , visited);
        dfs(grid , i , j+1 , perm , visited);
        dfs(grid , i , j-1 , perm , visited);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perm = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, perm, visited);
                    return perm;
                }
            }
        }
        return -1;
    }
};