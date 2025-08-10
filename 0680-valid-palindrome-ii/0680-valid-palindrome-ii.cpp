class Solution {

private:
    bool helperFunction(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int length = s.length();
        int left = 0, right = length - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return helperFunction(s, left + 1, right) ||
                       helperFunction(s, left, right - 1);
            }
            left++; right--;
        }
        return true;
    }
};
