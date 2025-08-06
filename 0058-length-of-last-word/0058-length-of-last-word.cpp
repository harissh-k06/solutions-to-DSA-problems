class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int i = len - 1;
        while (s[i] == ' '){
            i--;
        }
        if (i<0) return -1;
        string lastWord = "";
        while (i>= 0 && s[i] != ' '){    
            lastWord+=s[i];
            i--;
        }
        return lastWord.length();

    }
};