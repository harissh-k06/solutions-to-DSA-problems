class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(candidates , target , 0 ,res , subset);
        vector<vector<int>> ans;
        for (auto& subset : res){
            ans.push_back(subset);
        }
        return ans;
    }

private:
    void dfs(const vector<int>& candidates,int target,int idx,vector<vector<int>>& res,vector<int>& subset){
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (target< 0 || idx>=candidates.size()) return;

        subset.push_back(candidates[idx]);
        dfs(candidates , target-candidates[idx] , idx+1 , res , subset);
        subset.pop_back();
        while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
            idx++; // move pointer to the last duplicate
        }
        dfs(candidates , target , idx+1, res , subset);
    }
};
