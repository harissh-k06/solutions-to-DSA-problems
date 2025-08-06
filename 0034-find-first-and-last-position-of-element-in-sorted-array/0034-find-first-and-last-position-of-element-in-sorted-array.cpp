class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0 , high = size - 1;
        int mid;
        int first = -1 , last =-1;
        while (low<=high){
            mid = (low+high)/2;
            if (nums[mid] > target){
                high = mid -1;
            }
            else if (nums[mid] < target){
                low = mid+1;
            }
            else{
                first = mid ;
                high = mid-1;
            }

        }
        low = 0 , high = size - 1;
        while (low<=high){
            mid = (low+high)/2;
            if (nums[mid] > target){
                high = mid -1;
            }
            else if (nums[mid] < target){
                low = mid+1;
            }
            else{
                last = mid ;
                low= mid+1;
            }

        }
        return vector<int> {first,last};
    }
};