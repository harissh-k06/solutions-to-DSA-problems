class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) return {vector<int> (1 , nums[0])};

        vector<int> temp(nums.begin() + 1 , nums.end());
        auto perms = permute(temp);
        vector<vector<int>> res ; 

        for (auto& perm : perms){
            for (int i = 0 ; i<=perm.size() ; i++ ){
                vector<int> perm_copy = perm;
                perm_copy.insert(perm_copy.begin() + i , nums[0]);
                res.push_back(perm_copy);
            }
        }
        return res;
    }
};