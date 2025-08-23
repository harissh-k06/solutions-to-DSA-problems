class Solution {

int removeDup(vector<int>& nums){
    int left =1 , right = 1;
    while (right < nums.size()){
        if (nums[right ] != nums[right - 1]) {
            nums[left++] = nums[right];
        }
        right++;
    }
    return left;


}

public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin() , nums.end());
        int size = removeDup(nums);
        int maxLen = 1;
        int currLen = 1;
        for (int i = 1 ; i<  size ; i++){
            if (nums[i] == nums[i-1] + 1) {
                currLen++;
                maxLen = max(maxLen , currLen);
            }
            else{
                currLen = 1;
            }
        }
        return maxLen;
    }
};