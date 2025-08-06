class Solution {

private:
    unordered_map<char, string> mapping;

public:
    Solution() {
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        int len = digits.length();
        vector<string> res;
        vector<char> subset;
        helper(digits, 0, subset, res);
        return res;
    }

private:
    void helper(const string digits, int idx, vector<char>& subset,
                vector<string>& res) {
        if (subset.size() == digits.size()) {
            string combination = "";
            for (char c : subset) {
                combination += c;
            }
            res.push_back(combination);
            return;
        }

        string options = mapping[digits[idx]];
        for (int i = 0; i < options.size(); i++) {
            subset.push_back(options[i]);
            helper(digits, idx + 1, subset, res);
            subset.pop_back();
        }
    }
};
