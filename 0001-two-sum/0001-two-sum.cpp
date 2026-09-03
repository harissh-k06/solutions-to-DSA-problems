class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mapping;
        for (int i = 0 ; i < nums.size() ; i++){
            mapping[nums[i]] = i;
        }

        for (int i = 0 ; i < nums.size() ; i++){
            int newT = target - nums[i];

            if (mapping.contains(newT) && mapping[newT]!=i){
                return vector<int>{i , mapping[newT]};
            }
        }

    return vector<int>{};
    }
};