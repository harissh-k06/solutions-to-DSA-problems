class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> freqS;
        unordered_map<char , int> freqT;
        for (char c : s){
            freqS[c]++;
        }
        for (char c: t){
            freqT[c]++;
        }

        for (const auto [k,v] : freqS){
            if (freqT.contains(k) && freqT[k] == v) continue;
            else return false;
        }
        return s.length() == t.length();
    }
};