class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end() );
        int size = nums.size(); 
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(target - closestSum);
        for (int i = 0 ; i < size ; i++){
            int remainingSum = target - nums[i];
            int low = i+1 ; int high = size - 1;
            while (low<high){
                int sum = nums[i] + nums[low] + nums[high];
                if (sum< target) low++;
                else if (sum>target) high--;
                else {
                    return sum;
                }
                if (abs(target - sum) < minDiff){
                    minDiff = abs(target-sum);
                    closestSum = sum;
                }
            }
        }
        return closestSum;
    }
};