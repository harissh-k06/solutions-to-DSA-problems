class Solution {
private:
    unordered_set<int> colTrack;
    unordered_set<int> positiveDiagTrack;
    unordered_set<int> negativeDiagTrack;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        nQueensSolver(board , 0 , n);
        return res;

    }

private:
    void nQueensSolver(vector<vector<char>>& board, int row, const int& n) {
        if (row == n){
            vector<string> solution;
            for (int r = 0 ; r < n ; r++){
                string rowSol = "";
                for (int c = 0 ; c < n ; c++){
                    rowSol+=board[r][c];
                }
                solution.emplace_back(rowSol);
            }
            res.emplace_back(solution);
        }



        for (int col = 0; col < n; col++) {
            bool flag =
                (colTrack.find(col) != colTrack.end()) ||
                (positiveDiagTrack.find(row + col) != positiveDiagTrack.end()) ||
                (negativeDiagTrack.find(row - col) != negativeDiagTrack.end());

            if (flag) continue;
            else{
                board[row][col] = 'Q';
                colTrack.insert(col);
                negativeDiagTrack.insert(row - col);
                positiveDiagTrack.insert(row + col);
                nQueensSolver(board , row+1 , n);
                colTrack.erase(col);
                negativeDiagTrack.erase(row - col);
                positiveDiagTrack.erase(row + col);
                board[row][col] = '.';
            }
        }
    }
};