class Solution {
private:
    int sum = 0;

    bool findTarget(vector<int>& nums, int i, int currTarget, vector<vector<int>>& memo) {
        // Guard against negative index
        if (currTarget < 0) return false; 
        
        // Base conditions
        if (i >= nums.size() && currTarget != 0) return false;
        if (i >= nums.size()) return true;
        if (nums[i] == currTarget) return true;

        // 1. Return cached result if already computed
        if (memo[i][currTarget] != -1) {
            return memo[i][currTarget];
        }

        // 2. Compute, store in memo, and return
        return memo[i][currTarget] = findTarget(nums, i + 1, currTarget, memo) || 
                                     findTarget(nums, i + 1, currTarget - nums[i], memo);
    }

public:
    bool canPartition(vector<int>& nums) {
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2 != 0) return false;
        sum /= 2;

        // State table initialized to -1 (-1 = unvisited, 0 = false, 1 = true)
        vector<vector<int>> memo(nums.size(), vector<int>(sum + 1, -1));

        return findTarget(nums, 0, sum, memo);
    }
};