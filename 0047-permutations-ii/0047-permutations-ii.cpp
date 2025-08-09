class Solution {

private:
    vector<vector<int>> res;
    unordered_map<int , int> freqMap;

    void populateFreqMap(vector<int>& nums){
        for (int num : nums){
            freqMap[num]++;
        }
    }

    void dfs(vector<int>& nums , vector<int>& perm){
        if (nums.size() == perm.size()){
            res.emplace_back(perm);
            return;
        }

        for (const auto& [num , freq] : freqMap){
            if (freq>0){
                perm.emplace_back(num);
                freqMap[num]--;
                dfs(nums , perm);
                freqMap[num]++;
                perm.pop_back();
            }
        }


    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 ) return {{}};
        populateFreqMap(nums);
        vector<int> perm;
        dfs(nums , perm);
        return res;
    }
};