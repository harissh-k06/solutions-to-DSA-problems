class Solution {
private:
    bool helper(string s , int i , string word){
        int len = word.length();
        int count = 0;
        while (count < len){
            if (s[count + i] != word[count]) return false;
            count++;     
        }
        return true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp(len  +  1 ,false); 
        //because dp[length] = true for some  reason like starting point
        dp[len] = true;
        for (int i = len - 1 ; i>=0 ; i--){
            for (const auto& word : wordDict){
                int wordLen = word.length();
                if (len - i < wordLen) continue;
                //if (!dp[i+wordLen]) continue;
                bool flag = helper( s , i , word);
                if (flag && dp[i+wordLen]){
                    dp[i] = true; break;
                }
                 
            }
        }
        return dp[0];
    }
};