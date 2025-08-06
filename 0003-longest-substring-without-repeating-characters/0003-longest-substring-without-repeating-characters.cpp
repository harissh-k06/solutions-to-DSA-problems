class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (!len) return 0;
        unordered_set<char> unique; int maxLength = 0; //{a,b,c} 
        int left = 0 , right = 0;
        while (right<len){
            while(unique.find(s[right])!=unique.end()){
                unique.erase(s[left]);
                left++;
            }
            unique.insert(s[right]);
            maxLength = maxLength>(right-left+1)?maxLength:(right-left+1);
            right++;
            
        }
        return maxLength;
    }
};