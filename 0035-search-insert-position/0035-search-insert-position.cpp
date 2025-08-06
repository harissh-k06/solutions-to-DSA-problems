class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return 0;
        int low = 0, high = size - 1;
        int mid = low;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};