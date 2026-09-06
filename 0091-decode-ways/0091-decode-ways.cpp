class Solution {
private:
    int dfs(const string& s, int i, vector<int>& dp) {
        int len = s.length();
        
        // Base case: If we successfully reached the end, we found 1 valid decoding path
        if (i >= len) return 1; 
        
        // Base case: '0' cannot start a valid decoding
        if (s[i] == '0') return 0;
        
        // If we have already calculated the answer for this index, return it
        if (dp[i] != -1) return dp[i];

        // Option 1: Take the current single character
        int ways = dfs(s, i + 1, dp);

        // Option 2: Take two characters if they form a valid number between "10" and "26"
        if (i + 1 < len) {
            if (s[i] == '1' || (s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6')) {
                ways += dfs(s, i + 2, dp);
            }
        }

        // Save the result in our memoization array and return
        return dp[i] = ways;
    }

public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        
        // Initialize DP array with -1 to indicate unvisited states
        vector<int> dp(s.length(), -1);
        
        return dfs(s, 0, dp);
    }
};
