class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {}; // Handle empty matrix
        int m = matrix.size();
        int n = matrix[0].size();
        int startRow = 0, endRow = m - 1;
        int startCol = 0, endCol = n - 1;
        int totalElements = m * n;
        int index = 0;
        vector<int> answer(totalElements, 0);
        
        while (index < totalElements) {

            for (int j = startCol; j <= endCol && index < totalElements; j++) {
                answer[index++] = matrix[startRow][j];
            }
            startRow++;
        
            for (int i = startRow; i <= endRow && index < totalElements; i++) {
                answer[index++] = matrix[i][endCol];
            }
            endCol--;
            
            if (startRow <= endRow) {
                for (int j = endCol; j >= startCol && index < totalElements; j--) {
                    answer[index++] = matrix[endRow][j];
                }
                endRow--;
            }
            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow && index < totalElements; i--) {
                    answer[index++] = matrix[i][startCol];
                }
                startCol++;
            }
        }
        return answer;
    }
};
