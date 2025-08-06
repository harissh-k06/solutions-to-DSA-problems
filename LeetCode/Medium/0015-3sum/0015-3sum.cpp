class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<vector<int>> resultSet;
        int size = nums.size();
        for (int i = 0 ; i<size-1 ; i++){
            int targetSum = -1*nums[i];
            int low = i + 1 , high = size-1;
            while (low<high){
                if (nums[low] + nums[high] > targetSum  ) high--;
                else if (nums[low] + nums[high] < targetSum) low++;
                else {
                    resultSet.insert({nums[i] , nums[low] , nums[high]});
                    low++; high--;
                }
            }
        }
        vector<vector<int>> resultVector;
        for (auto iterator :resultSet){
            resultVector.push_back(iterator);
        }
        return resultVector;
    }
};