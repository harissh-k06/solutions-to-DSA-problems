class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int leftSmallest = INT_MAX;
        int rightLargest = INT_MIN;
        vector<bool> traverseRight(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            bool foundSmaller = false;
            if (leftSmallest < nums[i]) {
                foundSmaller = true;
            } else {
                leftSmallest = nums[i];
            }
            traverseRight[i] = foundSmaller;
        }

        vector<bool> traverseLeft(nums.size(), false);
        for (int i = nums.size() - 1; i >= 0; i--) {
            bool foundLarger = false;
            if (rightLargest > nums[i]) {
                foundLarger = true;
            } else {
                rightLargest = nums[i];
            }
            traverseLeft[i] = foundLarger;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (traverseLeft[i] && traverseRight[i])
                return true;
        }

        return false;
    }
};