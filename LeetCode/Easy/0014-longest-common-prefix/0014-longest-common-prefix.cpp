
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) { 
            return "";
        }

        sort(strs.begin(), strs.end());
        
        string ans = "";
        string first = strs[0];
        string last = strs[strs.size() - 1];
        int i = 0;

        while (i < first.length() && i < last.length() && first[i] == last[i]) {
            ans += first[i++]; 
        }
        
        return ans;
    }
};