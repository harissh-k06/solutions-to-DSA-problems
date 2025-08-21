class Solution {
private:
    unordered_set<char> vowels;

public:

    Solution(){ 
        vowels = {'a' , 'e' , 'i' , 'o' , 'u'};
    }

    string reverseVowels(string s) {
        int left = 0 , right = s.size() - 1;
        while (left < right){
            while (vowels.find(tolower(s[left])) == vowels.end() && left < right) left++;
            while (vowels.find(tolower(s[right])) == vowels.end() && left < right) right--;
            swap(s[left++] , s[right--]);
        }
        return s;
    }
};