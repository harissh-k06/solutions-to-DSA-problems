class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(candidates, target, 0, res, subset);
        return res;
    }

private:
    void dfs(const vector<int>& candidates, int target, int idx,
             vector<vector<int>>& res, vector<int>& subset) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (idx == candidates.size() || target < 0)
            return;
        
        subset.push_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], idx, res, subset);
        subset.pop_back();
        dfs(candidates, target, idx + 1, res, subset);
    }
};