class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int n : nums) sum+=n;
        int target = sum - x;
        int left = 0 , right = 0;
        int windowSum = 0;
        int ways = -1;
        while (right < nums.size()){
            windowSum+=nums[right++];
            while (left < right && windowSum > target){
                windowSum-=nums[left++];
            }
            if (windowSum == target){
                ways = max(ways , right - left);
            }
        }

        return ways == -1 ? -1 : nums.size() - ways; 
    }
};