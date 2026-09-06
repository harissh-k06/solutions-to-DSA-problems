class Solution {

private:
    int dfs(string s , int i , vector<int>& dp){
        int len = s.length();

        if (i>=len) return 1;

        if (s[i] == '0') return 0;

        if (dp[i]!=-1) return dp[i];

        //take current character alone
        int ways = dfs(s , i +1 , dp);

        //take next charactaer also if exisits
        if ( i+ 1 < len && (s[i] == '1' || s[i] == '2' && (s[i+1]>='0' && s[i+1]<='6'))){
            ways+=dfs(s , i + 2 , dp);
        }
        dp[i] = ways;
        return ways;
    }


public:
    int numDecodings(string s) {
        vector<int> dp(s.length() , -1);
        return dfs(s , 0 , dp);
    }
};
