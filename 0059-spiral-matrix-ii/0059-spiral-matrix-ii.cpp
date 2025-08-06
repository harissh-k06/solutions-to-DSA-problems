class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiralMatrix(n , vector<int>(n,1));
        int startRow = 0 , startCol = 0;
        int endRow = n-1 , endCol = n-1;
        int count = 0;
        int no = 1;
        while (count<n*n){
            for (int j = startCol ; j<=endCol ; j++){
                spiralMatrix[startRow][j] = no++;
                count++;
            }
            startRow++;
            for (int i = startRow ; i<=endRow ;i++){
                spiralMatrix[i][endCol] = no++;
                count++;
            }
            endCol--;
            for (int j = endCol ; j>=startCol ; j--){
                spiralMatrix[endRow][j] = no++;
                count++;
            }
            endRow--;
            for (int i = endRow ; i>=startRow ; i--){
                spiralMatrix[i][startCol] = no++;
                count++;
            }
            startCol++;
        }
        return spiralMatrix;
    }
};