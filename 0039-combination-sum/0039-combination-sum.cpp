class Solution {

private:
    vector<vector<int>> res;
    vector<int> subset;

    void dfs(vector<int>& nums, int idx , int target){
        if (target == 0) {
            res.push_back(subset);
            return;
        } // found case

        if (idx > nums.size() -1 || target < 0) return; //these are non promising nodes

        subset.push_back(nums[idx]); //if our current is included
        dfs(nums , idx , target - nums[idx]);
        subset.pop_back();
        dfs(nums , idx+1 , target); //not including current number
    }


public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if (target == 0) return res;
        dfs(nums , 0 , target);
        return res;
    }
};
