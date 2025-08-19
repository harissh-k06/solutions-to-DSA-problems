class Solution {

private:
    bool isPalin(string s , int left , int right){
        while (left < right){
            if (s[left++ ] == s[right -- ]) continue;
            else return false;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0 , right = s.size() -1 ;
        while (left < right){
            if (s[left]!=s[right]) return isPalin(s , left+1 , right) || isPalin(s , left , right-1);
            left++ ; right --;
        }
        return true;
    }
};