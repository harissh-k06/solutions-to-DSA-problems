class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sumXOR = 0;
         
        dfs(nums , 0 , 0 , sumXOR);
        return sumXOR;
    }


    void dfs(vector<int>& nums , int idx , int currXOR ,  int& sumXOR){
        if (idx == nums.size()){
            sumXOR +=currXOR;
            return;
        }
        dfs(nums , idx+1 , currXOR ^ nums[idx] , sumXOR);
        
        dfs(nums , idx+1 , currXOR , sumXOR);
    }
};