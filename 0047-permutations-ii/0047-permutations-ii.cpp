class Solution {

private:
   set<vector<int>> dfs(vector<int> nums){
        if (nums.size() ==0) return {{}};
        vector<int> temp(nums.begin()+1 , nums.end());
        set<vector<int>> perms = dfs(temp);
        set<vector<int>> res;
        for (const auto& perm: perms){
            for (int i = 0 ; i<=perm.size() ; i++){
                vector<int> p_copy = perm;
                p_copy.insert(p_copy.begin() + i , nums[0]);
                res.insert(p_copy);
            }
        }

        return res;
   }


public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //
        set<vector<int>> res = dfs(nums );
        vector<vector<int>> ans;
        for (const auto& perm : res){
            ans.emplace_back(perm);
        }
        return ans;
    }
};