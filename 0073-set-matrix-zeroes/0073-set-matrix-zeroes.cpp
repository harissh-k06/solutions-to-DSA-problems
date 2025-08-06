class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> isRowZero (rows , 0);
        vector<int> isColZero (cols , 0);
        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){
                if (matrix[i][j] == 0){
                    isRowZero[i] = 1;
                    isColZero[j] = 1;
                }
            }
        }

        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){
                if (isRowZero[i] == 1 || isColZero[j] == 1)
                    matrix[i][j] = 0;
            }
        }
    }
};