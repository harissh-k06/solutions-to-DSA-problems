class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n , vector<string>(n,"."));
        unordered_set<int> cols;
        unordered_set<int> positiveDiag;
        unordered_set<int> negativeDiag;
        vector<vector<string>> res;
        backtrack(board , n , 0 ,cols , positiveDiag , negativeDiag , res);
        return res;
    }

private:
    void backtrack(vector<vector<string>>& board , const int& n , int row ,unordered_set<int>& cols,unordered_set<int>& positiveDiag,unordered_set<int>& negativeDiag , vector<vector<string>>& res){
        if (row == n){
            vector<string> solution;
            for (int i = 0 ; i < n; i++){
                string row = "";
                for (int j = 0 ; j<n; j++){
                    row+=board[i][j];
                }
                solution.push_back(row);
            }
            res.push_back(solution);
        }

        for (int c = 0 ; c < n ; c++){
            if (cols.find(c)!=cols.end() || positiveDiag.find(row+c)!=positiveDiag.end() || negativeDiag.find(row-c)!=negativeDiag.end() ) continue;
            else{
                board[row][c] = "Q";
                cols.insert(c);
                positiveDiag.insert(row+c);
                negativeDiag.insert(row-c);
                backtrack(board , n , row+1  , cols , positiveDiag , negativeDiag , res);
                board[row][c] = ".";
                cols.erase(c);
                positiveDiag.erase(row+c);
                negativeDiag.erase(row-c);
            }
        }
    }
};
