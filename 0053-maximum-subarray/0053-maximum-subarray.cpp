class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int size = nums.size();
        int sumSoFar = 0;
        for (int i = 0 ; i < size ; i++){
            sumSoFar +=nums[i];
            maxSum = max(maxSum , sumSoFar); 
            sumSoFar = sumSoFar < 0 ? 0 : sumSoFar;
        }
        return maxSum;
    }
};