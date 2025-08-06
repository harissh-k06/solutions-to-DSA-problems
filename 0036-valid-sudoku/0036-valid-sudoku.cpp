class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0 ; i < rows ; i++){
            unordered_set<char> track;
            for (int j = 0 ; j < cols ; j++){
                if (board[i][j] == '.') continue;
                if (track.find(board[i][j])!=track.end()){
                    return false;
                }
                else{
                    track.insert(board[i][j]);
                }
            }
        }
        for (int j = 0 ; j < cols ; j++){
            unordered_set<char> track;
            for (int i = 0 ; i < rows ; i++){
                if (board[i][j] == '.') continue;
                if (track.find(board[i][j])!=track.end()){
                    return false;
                }
                else{
                    track.insert(board[i][j]);
                }
            }
        }
        int sqno = 1;
        int startRow = 0;
        int startCol = 0;
        while (sqno<=9){
            unordered_set<char> track;
            for (int i = startRow ; i<=startRow+2 ; i++){
                for (int j = startCol ; j<=startCol+2 ; j++){
                    if (board[i][j] == '.') continue;
                    if (track.find(board[i][j])!=track.end()){
                    return false;
                    }
                    else{
                    track.insert(board[i][j]);
                    }
                }
            }
            startCol+=3;
            
            if (startCol>=9){
                startCol = 0 ;
                startRow+=3;
            }
            
            sqno++;
        }
        return true;      
    } 
};
