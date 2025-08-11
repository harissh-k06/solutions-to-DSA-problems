class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; int sum = 0;
        for (const int& num : nums){
            sum+=num;
            maxSum = max(sum , maxSum);
            sum = sum < 0 ? 0 : sum;
        }
        return maxSum;
    }
};
