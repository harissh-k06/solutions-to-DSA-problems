class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        unordered_map<char , int> freq;
        int maxLen = 0;
        int maxFreq = 0;
        int l = 0 , r = 0 ;
        while (r < len){
            freq[s[r]]++;
            maxFreq = max(maxFreq , freq[s[r]]);
            while (r - l +1 - maxFreq > k){
                freq[s[l++]]--;
            }
            maxLen = max(r - l + 1 , maxLen) ;            
            r++;
        }    
        return maxLen;
    }
};