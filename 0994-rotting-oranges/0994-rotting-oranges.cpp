class Solution {

private:
    bool checkFresh(vector<vector<int>>& grid , int i , int j){
        if (i < 0 || j >= grid[0].size() || i>=grid.size() || j < 0 || grid[i][j]!=1) return false;
        return true;
    }


public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , int>> rotten;
        int fresh = 0;
        for (int i = 0 ; i < grid.size() ; i++){
            for (int j = 0 ; j < grid[0].size() ; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) rotten.push({i , j});
            }
        }
        
        int time = 0;
        while (!rotten.empty()){
            int currentRotten = rotten.size();
            bool didWeRot = false;
            for (int process = 0 ; process < currentRotten ; process++){
                auto badOrange = rotten.front();
                rotten.pop();
                int i = badOrange.first; int j = badOrange.second;
                if (checkFresh(grid , i + 1 , j)){
                    fresh--;
                    grid[i+1][j] = 2;
                    rotten.push({i+1 , j});
                    didWeRot = true;
                }

                if (checkFresh(grid , i - 1 , j)){
                    fresh--;
                    grid[i-1][j] = 2;
                    rotten.push({i-1 , j});
                    didWeRot = true;
                } 

                if (checkFresh(grid , i , j+1)){
                    fresh--;
                    grid[i][j+1] = 2;
                    rotten.push({i , j+1});
                    didWeRot = true;
                } 


                if (checkFresh(grid , i , j-1)){
                    fresh--;
                    grid[i][j-1] = 2;
                    rotten.push({i , j-1});
                    didWeRot = true;
                }
                
            }
            if (didWeRot) time++;
        }
        return fresh == 0 ? time : -1;
    }
};