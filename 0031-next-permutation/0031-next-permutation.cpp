class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        
        int i = size -1  ;
        while ( i > 0 && nums[i] <= nums[i-1]){
            i--;
        }
        if (i ==0){
            reverse(nums.begin() , nums.end());
            return;
        }
        
        int nextGreaterElementIdx = i;
        for (int j = i ; j < size ;j++){
            if (nums[j] > nums[i-1] && nums[nextGreaterElementIdx]>=nums[j]){
                nextGreaterElementIdx = j;
            }
        }

        swap(nums[nextGreaterElementIdx] , nums[i-1]);
        reverse(nums.begin() + i , nums.end());
    }
};