class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid; bool found = false;
        while (low<=high) {
            mid = (low + high) / 2;
            if (nums[mid] == target){
               found = true; break; 
            }
            if (nums[mid] >= nums[low]) {
                // left half is sorted along with mid
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else {
                    low = mid+1;
                }
            }
            else{
                //right half is sorted along with mid
                if (target>nums[mid] && target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return found ? mid :- 1;
    }
    

};