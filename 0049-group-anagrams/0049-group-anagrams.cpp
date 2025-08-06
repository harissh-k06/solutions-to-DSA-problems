class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> maintain;

        for (string& str : strs) {
            string current = str;
            sort(current.begin(), current.end());

            if (maintain.find(current) == maintain.end()) {
                maintain[current] = {str};
            } else {
                maintain[current].push_back(str);
            }
        }

        for (auto& [k, v] : maintain) {
            result.push_back(v);
        }

        return result;
    }
};
