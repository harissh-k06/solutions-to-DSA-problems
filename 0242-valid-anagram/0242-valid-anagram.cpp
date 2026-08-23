class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;
        unordered_map<char , int> freq1;
        unordered_map<char , int> freq2;
        for (char c : s){
            freq1[c]+=1;
        }
        for (char c : t){
            freq2[c]+=1;
        }

        for (char c : s){
            if (freq1[c]!=freq2[c]) return false;
        }
        return true;
    }
};