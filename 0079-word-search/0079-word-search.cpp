class Solution {

private:   
    bool dfs(vector<vector<char>>& board, int idx, int i, int j, const string& word){
        int m = board.size();
        int n = board[0].size();
        // Check bounds and character match (visited cells marked as '#' will naturally mismatch)
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx]) return false;
        // Base case: matched full word up to the last character
        if (idx == word.length() - 1) return true;

        // 1. Mark in-place to avoid std::set allocations
        char temp = board[i][j];
        board[i][j] = '#';

        // 2. Short-circuit exploration across 4 directions
        bool flag = dfs(board, idx + 1, i + 1, j, word) ||
                    dfs(board, idx + 1, i - 1, j, word) ||
                    dfs(board, idx + 1, i, j + 1, word) ||
                    dfs(board, idx + 1, i, j - 1, word);
            
        // 3. Backtrack: restore original character
        board[i][j] = temp;

        return flag;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Optimization 1: Frequency check & board capacity
        if (word.length() > m * n) return false;
        unordered_map<char, int> boardFreq, wordFreq;
        for (const auto& row : board) {
            for (char c : row) boardFreq[c]++;
        }
        for (char c : word) {
            if (++wordFreq[c] > boardFreq[c]) return false;
        }

        // Optimization 2: Reverse word if the tail character is rarer than the head
        if (boardFreq[word.back()] < boardFreq[word.front()]) {
            reverse(word.begin(), word.end());
        }

        // Search the board
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (word[0] == board[i][j]){
                    if (dfs(board, 0, i, j, word)) return true;
                }
            }
        }
        return false;
    }
};