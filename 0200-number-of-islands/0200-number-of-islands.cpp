class Solution {
private:
    set<pair<int , int>> seen;

    void dfs(vector<vector<char>>& grid , int i , int j ){
        if (i < 0 || j < 0 || i >= grid.size() || j >=grid[0].size() || seen.find({i , j}) != seen.end()) return;
        if (grid[i][j] == '0') return;
        if (grid[i][j] == '1') seen.insert({i,j});
        dfs(grid , i+1 , j);
        dfs(grid , i-1 , j);
        dfs(grid ,  i, j+1);
        dfs(grid , i , j-1);
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int noOfIslands = 0;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (grid[i][j] == '1' && seen.find({i,j}) == seen.end()){
                    dfs(grid , i , j);
                    noOfIslands++;
                }
            }
        }

        return noOfIslands;
    }
};