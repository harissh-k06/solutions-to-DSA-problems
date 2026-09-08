class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char , int> freq;
        for (char c :  s) freq[c]+=1;
        int maxLen = 0; bool flag = false;
        for (auto& [k,v] : freq){
            while (v > 1){
                freq[k]-=2;
                maxLen+=2;
            }
            if( v==1 && !flag){
                maxLen+=1;
                freq[k]-=1;
                flag= true;
            }
        }

        return maxLen;

    }
};