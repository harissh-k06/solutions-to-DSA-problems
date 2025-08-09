class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sumXOR = 0;
        vector<int> subset ; 
        dfs(nums , 0 , subset , sumXOR);
        return sumXOR;
    }


    void dfs(vector<int>& nums , int idx , vector<int>& subset ,  int& sumXOR){
        if (idx == nums.size()){
            int xORSum = 0;
            for (int num : subset){
                xORSum = xORSum ^ num;
            }
            sumXOR = sumXOR + xORSum;
            return;
        }
        subset.emplace_back(nums[idx]);
        dfs(nums , idx+1 , subset , sumXOR);
        subset.pop_back();
        dfs(nums , idx+1 , subset , sumXOR);
    }
};