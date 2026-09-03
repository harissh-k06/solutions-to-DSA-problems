class Solution {
public:
    string convert(string s, int numRows) {
        bool goingDown = false;
        if (numRows == 1) return s;

        vector<string> matrix(numRows);
        int currRow = 0;
        for (char c : s){
            matrix[currRow]+=c;
            if (currRow == 0 || currRow == numRows - 1){
                goingDown = !goingDown;
            }
            currRow = goingDown ? (currRow + 1)%numRows : (currRow - 1)%numRows ;
        }
        string result = "";
        for (int i = 0 ; i < numRows ; i++){
            for (char c: matrix[i]){
                result+=c;
            }
        }
        return result;
    }
};