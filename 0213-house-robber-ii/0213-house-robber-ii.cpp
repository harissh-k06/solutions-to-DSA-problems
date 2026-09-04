class Solution { 
private: 
    int houseRobber1(vector<int>& nums, int left, int right) {
        int n = right - left + 1;
        if (n == 1) return nums[left];
        
        vector<int> dp(n, 0);
        dp[0] = nums[left];
        dp[1] = max(nums[left + 1], dp[0]); // Fixed: use dp[0] instead of dp[left]
        
        for (int i = left + 2; i <= right; i++) {
            dp[i - left] = max(dp[i - left - 1], nums[i] + dp[i - left - 2]);
        }
        return dp[n - 1];
    } 
public: 
    int rob(vector<int>& nums) { 
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0]; 
        
        // Run including first and excluding last
        int p1 = houseRobber1(nums, 0, n - 2); 
        // Run including last and excluding first
        int p2 = houseRobber1(nums, 1, n - 1); 
        
        return max(p1, p2); 
    } 
};
