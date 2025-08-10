class Solution {

private:
    int maxSize;

    int dfs(vector<vector<int>>& grid , int i , int j , int& size){
        if (i<0 || i>=grid.size() || j< 0 || j>=grid[0].size() || grid[i][j] == 0){
            return size;
        }
        grid[i][j] = 0;
        size +=1;
        dfs(grid , i+1 , j , size);
        dfs(grid , i-1 , j , size);
        dfs(grid , i , j+1 , size);
        dfs(grid , i , j-1 , size);
        return size;
    }  

public: 
    Solution():maxSize(0){}

    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0 ; i< grid.size() ; i++){
            for (int j = 0 ; j<grid[0].size() ; j++){
                if (grid[i][j] == 1){
                    int size = 0 ;
                    size  = dfs(grid , i , j , size);
                    maxSize = max(size , maxSize);
                }
            }
        }
        return maxSize;
    }
};
